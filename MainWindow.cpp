#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    thread_mysql = NULL;
    server = NULL;
    thread_mqtt = NULL;

    RabbitmqClient rabbit;

    //timer
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(TIMER_TIMEOUT_MAIN);

    Readconfig *cfg_ini =new Readconfig("config.ini");

    //tcp
    port = cfg_ini->Get_and_Default("TCP","port",8888).toInt();
    ui->textEdit_port->setText(QString::number(port));
    Get_IP_Local();

    //mqtt

    mqtt_topic =cfg_ini->Get_and_Default("mqtt","topic","qtmqtt/topic").toString();
    mqtt_qos =cfg_ini->Get_and_Default("mqtt","qos",2).toInt();
//    qDebug()<<"mqtt_topic :"<<mqtt_topic<<"  mqtt_port :"<<mqtt_port<<"  mqtt_qos :"<<mqtt_qos;
    ui->textEdit_pub->setText(mqtt_topic);


    delete cfg_ini;
    ui->pushButton_start->setEnabled(false);

//    qInstallMessageHandler(myMessageOutput);//start log file
    starthread();//init and start thread
}

MainWindow::~MainWindow()
{
        closethread();

        delete      thread_mysql;
        delete      server;
        delete      thread_mqtt;
        //delete      m_pTimer;
        delete      ui;
}
    void MainWindow::threadFinished()
    {

    }
//停止线程
void MainWindow::on_pushButton_stop_clicked()
{
     //   closethread();
}

//启动线程
 void MainWindow::starthread()
 {

     #if 1
         //开启数据库线程
         thread_mysql    =new Thread_MySQL();
         thread_mysql->moveToThread(&m_thread_sql);
         connect(&m_thread_sql,&QThread::started,thread_mysql,&Thread_MySQL::start);
         connect(&m_thread_sql,&QThread::finished,thread_mysql,&Thread_MySQL::deleteLater);
  //       connect(this,SIGNAL(signalsendtoMysql(QString)),thread_mysql,SLOT(dealmesfrommain(QString)),Qt::QueuedConnection);

     #endif
         server  =   new Server(port);
         server->moveToThread(&m_thread_server);
         connect(&m_thread_server,&QThread::started,server,&Server::start);
         connect(&m_thread_server,&QThread::finished,server,&Server::deleteLater);
         connect(server,SIGNAL(updataServer(QString,int) ),this,SLOT(updataServer(QString,int) ));
         connect(server,SIGNAL(updataSQL(QString)),thread_mysql,SLOT(dealstrfromserver(QString)));
        connect(thread_mysql,SIGNAL(signalMySQL(QString)),this,SLOT(slotdealfromMysql(QString)));
        connect(server,SIGNAL(updataMain(QString)),this,SLOT(updataMain(QString)));

#if 1
           thread_mqtt = new MQTTClient();
//           thread_mqtt->moveToThread(&m_thread_mqtt);
//           connect(&m_thread_mqtt,&QThread::started,thread_mqtt,&MQTTClient::start);
//           connect(&m_thread_mqtt,&QThread::finished,thread_mqtt,&MQTTClient::deleteLater);
           connect(this,SIGNAL(signalsendtoMQTT(QStringList)),thread_mqtt,SLOT(dealfrommain(QStringList)));
           connect(thread_mqtt,SIGNAL(signal_mqtttomain(QString)),this,SLOT(deal_frommqtt(QString)));
           connect(thread_mqtt,SIGNAL(signal_mqtttomysql(QStringList)),thread_mysql,SLOT(dealstrfrommqtt(QStringList)));
#endif
                m_thread_sql.start();
                m_thread_server.start();
//                m_thread_mqtt.start();// no in thread
 }

//关闭线程
 void MainWindow::closethread()
 {
     if(thread_mysql)
     {
         qDebug() << "线程有效，关闭线程thread_mysql " ;
         thread_mysql->stop();
         m_thread_sql.quit();
         m_thread_sql.wait();
         thread_mysql= NULL;
     }
     if(server)
         {
         qDebug() << "线程有效，关闭线程server " ;
//         server ->stop();
         m_thread_server.quit();
         m_thread_server.wait();
         server = NULL;
     }
//     if(thread_mqtt)
//         {
//         qDebug() << "线程有效，关闭线程thread_mqtt " ;
//         m_thread_mqtt.quit();
//         m_thread_mqtt.wait();
//         thread_mqtt = NULL;
//     }
 }


 void MainWindow::on_pushButton_start_clicked()
{
        starthread();
//        slotCreateServer();//start server

        ui->pushButton_start->setEnabled(false);

}


    void MainWindow::handleTimeout()
    {
//        QString msg = QString("%1 -> %2 threadid:[%3]")
//                .arg(__FILE__)
//                .arg(__FUNCTION__)
//                .arg((uintptr_t)QThread::currentThreadId());
//        qDebug() << msg;

        if(m_pTimer->isActive()){
            m_pTimer->start();
        }
    }
void MainWindow::on_pushButton_connect_clicked()
{
    QStringList s;
    s<<QString("%1").arg(PRO_MAIN_INFO);
   s<<ui->textEdit_port->toPlainText();//get port
}

void MainWindow::on_pushButton_send_clicked()
{
    QStringList s;
    s<<QString("%1").arg(PRO_MAIN_SEND);
    s<<ui->textEdit_send->toPlainText();//get send msg


}

void MainWindow::Get_IP_Local(void)//get ip local
{
    QString localHostName = QHostInfo::localHostName();

    QHostInfo hostInfo =QHostInfo::fromName(localHostName);
 //   qDebug()<<hostInfo.addresses().at(2).toString();

    //获得IP
//    QList<QHostAddress>listAddress =    hostInfo.addresses();
//    if(!listAddress.isEmpty())
//    {
           ui->label_IP->setText(hostInfo.addresses().at(1).toString());
//    }
}

void    MainWindow::slotCreateServer()
{
//        server  =   new Server(this,port);
//        connect(server,SIGNAL(updataServer(QString,int) ),this,SLOT(updataServer(QString,int) ));

}



void    MainWindow::updataServer(QString msg,int length)
{

    //server 收到信息
 //   ui->textBrowser_server->append(msg.toUtf8().data());//templature close
 //   qDebug()<<"length === "<<length;

}

void    MainWindow::slotdealfromMysql(QString str)
{
        ui->text_output->append(str);
}

void    MainWindow::updataMain(QString str)
{
    QStringList list =str.split('/');
//    ui->text_output->append(list.join(' '));//templature close
}

void MainWindow::on_pushButton_subs_clicked()
{
    QStringList list;
    list.clear();

    mqtt_topic =ui->textEdit_pub->toPlainText();
    list<<QString::number(1);//:0
    list<<mqtt_topic;//:1
    list<<QString::number(2);//:2
    emit signalsendtoMQTT(list);
}

void MainWindow::on_pushButton_pub_clicked()
{
//        if (m_client->publish(ui->textEdit_pub->toPlainText(), ui->textEdit_sub->toPlainText().toUtf8()) == -1)
//            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    mqtt_topic =ui->textEdit_pub->toPlainText();

    QStringList list;
    list.clear();
    list<<QString::number(0);
    list<<mqtt_topic;
    list<<ui->textEdit_sub->toPlainText();
    list<<QString::number(mqtt_qos);
    emit signalsendtoMQTT(list);

}


void MainWindow::deal_frommqtt(QString s)
{
        ui->text_output->append(s);
        qDebug()<<s;
}
