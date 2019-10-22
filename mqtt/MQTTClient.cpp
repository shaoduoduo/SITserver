#include "MQTTClient.h"

ThreadMQTTClient::ThreadMQTTClient(QObject *parent) : QObject(parent)
{

 //QMQTT::Client *client = new QMQTT::Client("m1.smartbow.cn", 1883,ssl_config);
}

ThreadMQTTClient::~ThreadMQTTClient()
{
    delete m_pTimer;
    delete m_client;
}



void ThreadMQTTClient::doWork()
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
//    m_pTimer->start(TIMER_TIMEOUT);


    m_client = new QMqttClient(this);
    m_client->setHostname("10.10.10.78");
    m_client->setPort(1883);

    connect(m_client, &QMqttClient::stateChanged, this, &ThreadMQTTClient ::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &ThreadMQTTClient::brokerDisconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &ThreadMQTTClient::mqttmessageReceived);
    connect(m_client, &QMqttClient::pingResponseReceived, this,&ThreadMQTTClient::pingrecieve) ;
    updateLogStateChange();
    connecttohost();
    slotSubscribe();
   // m_client->requestPing();
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


void ThreadMQTTClient::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
        qDebug()<<content;
}

void ThreadMQTTClient::brokerDisconnected()
{
        qDebug()<<"brokerDisconnected";
}

void ThreadMQTTClient::mqttmessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
  //  ui->editLog->insertPlainText(content);
}


void ThreadMQTTClient::pingrecieve()//slot
{
        //ui->buttonPing->setEnabled(true);
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
       qDebug()<<content;
}
void ThreadMQTTClient::connecttohost()//slot
{
    if (m_client->state() == QMqttClient::Disconnected) {
            qDebug()<<"Disconnect";
            m_client->connectToHost();
        } else {
            qDebug()<<"Connect";
            m_client->disconnectFromHost();
        }
}

void ThreadMQTTClient::slotPublish()
{    QString topic="top1";
     const QString content = QDateTime::currentDateTime().toString();

        if(m_client->publish(topic,content.toUtf8(),0)==1)
    qDebug()<<"Could not publish message";
}

void ThreadMQTTClient::slotSubscribe()
{
    QString topic ="top1";
    auto subscription = m_client->subscribe(topic,0);
    if (!subscription) {
       qDebug()<<"Could not subscribe. Is there a valid connection?";
    }
}
