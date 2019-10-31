#include "Thread_MySQL.h"
#include <readconfig.h>

Thread_MySQL::Thread_MySQL(MoveToThreadTest *parent) : MoveToThreadTest(parent)
{
//        m_bRun = true;
}


Thread_MySQL::~Thread_MySQL()
{
         db.close();


}
void Thread_MySQL::doWork()
{


    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(TIMER_TIMEOUT);

    Readconfig *cfg_ini =new Readconfig("config.ini");

    db=QSqlDatabase::addDatabase("QMYSQL");

    mqsqlHostName=cfg_ini->Get("mysql","host","localhost").toString();     //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    mqsqldPort=cfg_ini->Get("mysql","port",3306).toInt();               //连接数据库端口号，与设置一致
    databaseName=cfg_ini->Get("mysql","databasename","db_server").toString();           //连接数据库名，与设置一致
    msqlUserName=cfg_ini->Get("mysql","username","user_server").toString();          //数据库用户名，与设置一致
    table_elec = cfg_ini->Get("mysql","table_tb_elec","TB_ELEC_copy").toString();
    inc_func=cfg_ini->Get("mysql","inc_func","sp_tb_elec_update_inc_val").toString();
    db.setHostName(mqsqlHostName);      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(mqsqldPort);                 //连接数据库端口号，与设置一致
    db.setDatabaseName(databaseName);      //连接数据库名，与设置一致
    db.setUserName(msqlUserName);          //数据库用户名，与设置一致
    db.setPassword("P@ssw0rd");    //数据库密码，与设置一致
    MySQLFlag   =db.open();

    delete cfg_ini;


    if(!db.open())
    {

        // QSqlError   s=(QSqlError)db.lastError();//lastError().text();
         qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
    }
    else
    {
           qDebug()<<"连接成功"<<"connect to mysql OK";
           //创建成功，开启线程处理数据库
    }

}

void Thread_MySQL::start()
{
    doWork();
    if(MySQLFlag==false)
        return;


//        QSqlQuery query(db);
//            query.exec("select * from TB_ELEC_copy");
//         while(query.next()){
//             qDebug()<<query.value("value").toString();
//        }
}

void Thread_MySQL::stop()
{
//    QString msg = QString("%1 -> %2 threadid:[%3]")
//            .arg(__FILE__)
//            .arg(__FUNCTION__)
//            .arg((QThread)QThread::currentThreadId());
//    qDebug() << msg;

//    QMutexLocker locker(&m_Mutex);
//    m_bRun = false;
}
void    Thread_MySQL::dealmesfrommain(QString s)
{
    qDebug()<<s<<"sql thread";
}


    void    Thread_MySQL::deallistfromfile(QStringList s)
    {
            qDebug()<<"mysql 收到 data"<<s.at(1);
    }
    void Thread_MySQL::handleTimeout()
    {
//        QString msg = QString("%1 -> %2 threadid:[%3]")
//                .arg(__FILE__)
//                .arg(__FUNCTION__)
//                .arg((uint64_t)QThread::currentThreadId());
//        qDebug() << msg;

        if(m_pTimer->isActive()){
            m_pTimer->start();
        }
    }

    void    Thread_MySQL::dealstrfromserver(QString str)
    {

      //   qDebug()<<"dealstrfromclient 收到 "<<str;
         emit   signalMySQL(str);
        if(MySQLFlag ==false)
            return;

                QSqlQuery query(db);
                    query.exec(str);
//                 while(query.next()){
//                     qDebug()<<query.value("msg").toString();
//                }


    }
   void Thread_MySQL::dealstrfrommqtt(QStringList list)
   {


//       qDebug()<<"Thread_MySQL  recieve"<<list;
//       qDebug()<<"inc_func ---->>>>>"<<inc_func;
       inc_func.clear();

QString dt_tm =QString("%1 %2").arg(list.at(0)).arg(list.at(1));
       //("2019-10-26", "16:40:26", "6CPFc", "0.000000", "good")

QString sqlstr =QString("insert into %1 ( dt,tm,dt_tm,location,\
value,create_dt,create_tm) \
values ('%2','%3','%4','%5','%6',CURDATE(),CURTIME())%7;").arg(table_elec)\
            .arg(list.at(0)).arg(list.at(1)).arg(dt_tm).arg(list.at(2))\
        .arg(list.at(3)).arg(inc_func);

//QString sqlstr =QString("insert into %1 ( dt,tm,dt_tm,location,\
//value,create_dt,create_tm) \
//values ('%2','%3','%4','%5','%6',CURDATE(),CURTIME());").arg(table_elec)\
//            .arg(list.at(0)).arg(list.at(1)).arg(dt_tm).arg(list.at(2))\
//        .arg(list.at(3));

//
//qDebug()<<sqlstr;
//       return;


//       QString str;
       if(MySQLFlag ==false)
           return;
//    qDebug()<<sqlstr;
               QSqlQuery query(db);
                   query.exec(sqlstr);
//                while(query.next()){
//                    qDebug()<<query.value("msg").toString();
//               }


   }
