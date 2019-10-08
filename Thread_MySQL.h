
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

private:
            QSqlDatabase db;
            bool MySQLFlag;
};

#endif // MYSQLTHREAD_H
