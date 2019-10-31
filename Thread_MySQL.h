
#ifndef MYSQLTHREAD_H
#define MYSQLTHREAD_H

#include <QObject>
#include "MoveToThreadTest.h"
#include    <protocol/protocol_anodizing.h>

#include <QSqlDatabase>
#include <QSqlQuery>
#include    <QSqlError>
#define TIMER_TIMEOUT   (5*1000)
class Thread_MySQL : public MoveToThreadTest
{
    Q_OBJECT
public:
    explicit Thread_MySQL(MoveToThreadTest *parent = nullptr);
~Thread_MySQL();

                QTimer *m_pTimer;//定时器
                 void doWork();
                 void start();
                 void stop();
signals:
                 void  signalMySQL(QString);

public slots:


    void    dealmesfrommain(QString s);
    void    deallistfromfile(QStringList s);
    void    dealstrfromserver(QString);
            void    handleTimeout();  //定时器超时处理函数
    void    dealstrfrommqtt(QStringList);

private:
            QSqlDatabase db;
            bool MySQLFlag;
             QSqlQuery query_global;

             QString mqsqlHostName;     //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
             int mqsqldPort;               //连接数据库端口号，与设置一致
             QString databaseName;           //连接数据库名，与设置一致
             QString msqlUserName;          //数据库用户名，与设置一致
             QString table_elec;
             QString inc_func;
};

#endif // MYSQLTHREAD_H
