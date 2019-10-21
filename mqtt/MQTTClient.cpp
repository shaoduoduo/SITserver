#include "MQTTClient.h"

ThreadMQTTClient::ThreadMQTTClient(QObject *parent) : QObject(parent)
{

 //QMQTT::Client *client = new QMQTT::Client("m1.smartbow.cn", 1883,ssl_config);
}

ThreadMQTTClient::~ThreadMQTTClient()
{
    delete m_pTimer;

}



void ThreadMQTTClient::doWork()
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(TIMER_TIMEOUT);


}
void ThreadMQTTClient::start()
{
    doWork();

}
void ThreadMQTTClient::stop()
{


}
void    ThreadMQTTClient::handleTimeout()  //定时器超时处理函数
{
            QString msg = QString("%1 -> %2 threadid:[%3]")
                    .arg(__FILE__)
                    .arg(__FUNCTION__)
                    .arg((uint64_t)QThread::currentThreadId());
            qDebug() << msg;

            if(m_pTimer->isActive()){
                m_pTimer->start();
            }

}
