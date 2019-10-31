#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MoveToThreadTest.h"

#include <Thread_MySQL.h>

#include    <QFileSystemWatcher>
#include    <QProcess>

#include <QHostInfo>
#include <QHostAddress>
#include    <tcp_server/Server.h>
//#include <QtMqtt/QMqttClient>
#include "MQTTClient/MQTTClie.h"
#include <readconfig.h>
#include <logfile.h>


namespace Ui {
class MainWindow;
}
#define TIMER_TIMEOUT_MAIN   (5*1000)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void starthread();
    void closethread();
    void    slotCreateServer();
private slots:

    void    slotdealfromMysql(QString);
    void threadFinished();
    void on_pushButton_stop_clicked();

    void on_pushButton_start_clicked();

    void    handleTimeout();  //定时器超时处理函数
    void on_pushButton_connect_clicked();
    void on_pushButton_send_clicked();

//tcp server

    void    updataServer(QString,int);
    void    updataMain(QString);


    void on_pushButton_subs_clicked();
    void on_pushButton_pub_clicked();
    void deal_frommqtt(QString);
private:
    Ui::MainWindow *ui;
    MoveToThreadTest    *   m_pMoveThread ;
    QThread     m_Thread;

    Thread_MySQL        *thread_mysql;
    QThread     m_thread_sql;


    QTimer *m_pTimer;//定时器
    void Get_IP_Local(void);

//mqtt

    MQTTClient        *thread_mqtt;
    QThread     m_thread_mqtt;



    QString mqtt_topic;
//    int mqtt_port;
    int mqtt_qos;
    //tcp server
    int port;
    Server  *server;
    QThread     m_thread_server;

signals:
        void signalsendtoMysql(QString s);
        void signalsendtoMQTT(QStringList);
};

#endif // MAINWINDOW_H
