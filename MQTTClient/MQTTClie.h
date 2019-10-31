#ifndef MQTTCLIE_H
#define MQTTCLIE_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QtMqtt/QMqttClient>
#include <QStringList>
#include <qmqttclient.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#define  MQTT_TIMEOUT (5000)

class MQTTClient:public QMqttClient
{
    Q_OBJECT
public:
    MQTTClient();
    ~MQTTClient();
    void start();

    bool publish(const QMqttTopicName &topic, const QByteArray &message = QByteArray(),quint8 qos = 0);
    bool subscribe (const QMqttTopicFilter &topic, quint8 qos = 0);


private:
    QTimer *m_pTimer;
    QMqttClient *m_client;

    QString mqtt_topic;
    QString mqtt_add;
    int mqtt_port;
    QString mqtt_username;
    QString mqtt_password;
    int mqtt_qos;
    int mqtt_keep;

    void packandsend(QStringList);//pack mqtt data
    bool unpackFromMqtt(QJsonDocument);
public slots:
    void handleTimeout();
    void dealfrommain(QStringList);


    void updateLogStateChange();
    void brokerDisconnected();
    void mqttmessagerecieve(const QByteArray &message,const QMqttTopicName &topic);
    void mqttpingresponse();
    void mqtterrormessage(int error);



signals:
    void signal_mqtttomain(QString);
    void signal_mqtttomysql(QStringList);
};

#endif // MQTTCLIE_H
