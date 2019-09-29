#include "Thread_MySQL.h"

Thread_MySQL::Thread_MySQL(MoveToThreadTest *parent) : MoveToThreadTest(parent)
{
//        m_bRun = true;
}


Thread_MySQL::~Thread_MySQL()
{
         db.close();
         delete m_pTimer;

}
void Thread_MySQL::doWork()
{


    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(TIMER_TIMEOUT);


    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("10.10.10.245");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("db_server");      //连接数据库名，与设置一致
    db.setUserName("user_server");          //数据库用户名，与设置一致
    db.setPassword("P@ssw0rd");    //数据库密码，与设置一致
    MySQLFlag   =db.open();

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
   //     db.open();
        QSqlQuery query(db);

            query.exec("select * from test_alarm");
         while(query.next()){
             qDebug()<<query.value("msg").toString();
        }

            // query.exec("insert into student values(4,'kevin')");

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
