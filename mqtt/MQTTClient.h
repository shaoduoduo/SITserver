#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QDebug>
#define TIMER_TIMEOUT 5000

class ThreadMQTTClient : public QObject
{
    Q_OBJECT
public:
    explicit ThreadMQTTClient(QObject *parent = nullptr);
    ~ThreadMQTTClient();


    QTimer *m_pTimer;//定时器
     void doWork();
     void start();
     void stop();
signals:
     void  signalThread_MQTTClient(QString);

public slots:

void    handleTimeout();  //定时器超时处理函数



};
#endif // MQTTCLIENT_H
