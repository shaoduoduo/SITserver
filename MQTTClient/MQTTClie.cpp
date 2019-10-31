#include "MQTTClie.h"
#include <QObject>
#include <readconfig.h>
MQTTClient::MQTTClient()
{
    m_client = new QMqttClient();
    Readconfig *cfg_ini =new Readconfig("config.ini");

    mqtt_add = cfg_ini->Get("mqtt","ip","localhost").toString();
    mqtt_port =cfg_ini->Get("mqtt","port",1883).toInt();


    mqtt_topic=cfg_ini->Get("mqtt","OPC_topic","qtmqtt/topic").toString();
    mqtt_username=cfg_ini->Get("mqtt","usrname","qt_server").toString();
    mqtt_password=cfg_ini->Get("mqtt","password","").toString();
    mqtt_qos=cfg_ini->Get("mqtt","qos",1).toInt();
    mqtt_keep =cfg_ini->Get("mqtt","keepalive",60).toInt();

    m_client->setHostname(mqtt_add);
    m_client->setPort(mqtt_port);
    m_client->setUsername(mqtt_username);
    m_client->setKeepAlive(mqtt_keep);

    m_client->connectToHost();

    delete cfg_ini;
    connect(m_client,&QMqttClient::stateChanged,this,&MQTTClient::updateLogStateChange);
    connect(m_client,&QMqttClient::disconnected,this,&MQTTClient::brokerDisconnected);
    connect(m_client,&QMqttClient::messageReceived,this,&MQTTClient::mqttmessagerecieve);
    connect(m_client,&QMqttClient::pingResponseReceived,this,&MQTTClient::mqttpingresponse);
    connect(m_client,&QMqttClient::errorChanged,this,&MQTTClient::mqtterrormessage);


}

MQTTClient::~MQTTClient()
{


}
void MQTTClient::start()
{


//    m_pTimer = new QTimer(this);
//    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
//    m_pTimer->start(MQTT_TIMEOUT);
}


void MQTTClient::handleTimeout()
{

//            QString msg = QString("%1 -> %2 threadid:[%3]")
//                    .arg(__FILE__)
//                    .arg(__FUNCTION__)
//                    .arg((uint64_t)QThread::currentThreadId());
//            qDebug() << msg;
    if (m_client->state() == QMqttClient::Disconnected) {
        qDebug("connectToHost");
        m_client->connectToHost();
    }
            if(m_pTimer->isActive()){
                m_pTimer->start();
            }
}
void MQTTClient::dealfrommain(QStringList list)
{
        bool res;
    if(list.size()!=false)
    {
        switch (list.at(0).toInt()) {
        case 0://publish

            res = publish(list.at(1),list.at(2).toUtf8(),list.at(3).toInt());
            emit signal_mqtttomain("publish :"+QString::number(res));
            break;
        case 1://subscribe

            res = subscribe(list.at(1),list.at(2).toInt());
           emit signal_mqtttomain("subscribe :"+QString::number(res));
        default:
            break;
        }

    }


}
bool MQTTClient::publish(const QMqttTopicName &topic, const QByteArray &message,quint8 qos)
{
//            if (m_client->publish(topic, ui->textEdit_sub->toPlainText().toUtf8()) == -1)
        bool res  =      m_client->publish(topic, message,qos);
            return res;
//                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}
bool MQTTClient::subscribe (const QMqttTopicFilter &topic, quint8 qos)
{
    auto subscription = m_client->subscribe(topic,qos);
   return subscription;

}

void MQTTClient::updateLogStateChange()
{
emit signal_mqtttomain("updateLogStateChange : "+QString::number(m_client->state()));
//    enum ClientState {
//        Disconnected = 0,
//        Connecting,
//        Connected
//    };
    if(m_client->state()==QMqttClient::Connected)
    {
        bool res =subscribe(mqtt_topic,mqtt_qos);
        qDebug()<<"subcribe mqtt_topic  :"<<mqtt_topic<<res;
    }
}

void MQTTClient::brokerDisconnected()
{
emit signal_mqtttomain("brokerDisconnected ");
}
void MQTTClient::mqttmessagerecieve(const QByteArray &message,const QMqttTopicName &topic)
{
//    qDebug()<<message;
    QJsonParseError json_error;

    QJsonDocument jsonDoc(QJsonDocument::fromJson(message,&json_error));
    if(json_error.error != QJsonParseError::NoError)
        qDebug()<<json_error.error;
    else
    {
        bool res = unpackFromMqtt(jsonDoc);
//        qDebug()<<res;
    }


}
void MQTTClient::mqttpingresponse()
{
emit signal_mqtttomain("mqttpingresponse ");
}
 void MQTTClient::mqtterrormessage(int error)
 {

//     enum ClientError {
//         // Protocol states
//         NoError                = 0,
//         InvalidProtocolVersion = 1,
//         IdRejected             = 2,
//         ServerUnavailable      = 3,
//         BadUsernameOrPassword  = 4,
//         NotAuthorized          = 5,
//         // Qt states
//         TransportInvalid       = 256,
//         ProtocolViolation,
//         UnknownError
//     };
     emit signal_mqtttomain("errorChanged :"+QString::number(error));
//     qDebug()<<error;
 }


 void MQTTClient::packandsend(QStringList items_list)
 {
     //("2019-10-25T14:40:21", "ITTest.DCP_GAC_02_SI_AI_HMI", "1.118998", "good")
     //insert into test_anod (anod_index ,date_client,time_client,I_PV,U_PV,I_SV,U_SV,date_server,time_server) values (2,"2019-9-25","16:47:50","10","10.3","20","30.5",CURDATE(),CURTIME());
    QStringList value_list =  items_list.at(0).split(QRegExp("T"));


    QStringList list=items_list.at(1).split('.');
//    qDebug()<<list.at(1);

    value_list<<list.at(1)<<items_list.at(2)<<items_list.at(3);

//    qDebug()<<"send to sql  :"<<value_list;

    emit signal_mqtttomysql(value_list);
 }
bool MQTTClient::unpackFromMqtt(QJsonDocument jsonDoc)
{

    QJsonObject jsonObj = jsonDoc.object();
    QStringList  keys =jsonObj.keys();
//    for(int i=0;i< keys.size();i++)
//        qDebug()<<"keys"<<i<<"is  :"<< keys.at(i);
//keys 0 is  : "soap:Envelope"
    if(keys.size()==0)
        return false;
    QJsonObject jsonObj1 = jsonObj.value(keys.at(0)).toObject();
    keys =jsonObj1.keys();
//    for(int i=0;i< keys.size();i++)
//        qDebug()<<"keys"<<i<<"is  :"<< keys.at(i);
//    keys 0 is  : "@xmlns:soap"
//    keys 1 is  : "@xmlns:xsd"
//    keys 2 is  : "@xmlns:xsi"
//    keys 3 is  : "soap:Body"
    if(keys.size()==0)
        return false;
    QJsonObject jsonObj2 = jsonObj1.value(keys.at(keys.size()-1)).toObject();
    keys =jsonObj2.keys();
    if(keys.size()==0)
        return false;
//    for(int i=0;i< keys.size();i++)
//        qDebug()<<"keys"<<i<<"is  :"<< keys.at(i);
//keys 0 is  : "ReadResponse"
    QJsonObject jsonObj3 = jsonObj2.value(keys.at(keys.size()-1)).toObject();
    keys =jsonObj3.keys();
//    for(int i=0;i< keys.size();i++)
//        qDebug()<<"keys"<<i<<"is  :"<< keys.at(i);
//    keys 0 is  : "@xmlns"
//    keys 1 is  : "RItemList"
//    keys 2 is  : "ReadResult"
    if(keys.size()==0)
        return false;
    QJsonObject jsonObj4 = jsonObj3.value("RItemList").toObject();
    keys =jsonObj4.keys();
//        for(int i=0;i< keys.size();i++)
//            qDebug()<<"keys"<<i<<"is  :"<< keys.at(i);
    if(keys.size()==1&&jsonObj4.contains("Items"))
       {
        QJsonValue items_value=jsonObj4.take("Items");
        if(items_value.isArray())
        {
            QJsonArray items_array = items_value.toArray();
            qDebug()<<"recieve num:"<<items_array.size();
            for(int i=0;i<items_array.size();i++)
            {
                QStringList items_list;
                items_list.clear();
                QJsonObject items_object = items_array.at(i).toObject();

                if(items_object.contains("@Timestamp"))
                {
                    items_value = items_object.take("@Timestamp");
//                        if(items_value.isString())
//                            qDebug()<<items_value.toString();
                        items_list<<items_value.toString();
                }
                if(items_object.contains("@ItemName"))
                {
                    items_value = items_object.take("@ItemName");
//                        if(items_value.isString())
//                            qDebug()<<items_value;
                        items_list<<items_value.toString();
                }

                if(items_object.contains("Value"))
                {

                    items_object = items_object.value("Value").toObject();
//                        qDebug()<< "Value object"<<items_object.keys();
                    if(items_object.keys().size()==2)
                    {
//                            QJsonObject items_object_temp = items_object.value(items_object.keys().at(0)).toObject();
                        if(items_object.contains("#text"))
                        {
                            items_value = items_object.take("#text");
//                                qDebug()<<"text value"<<items_value;
                            items_list<<items_value.toString();
                        }
                    }
                }
                items_object = items_array.at(i).toObject();
                if(items_object.contains("Quality"))
                {
                    items_object = items_object.value("Quality").toObject();

                    if(items_object.keys().size()==1)
                    {
//                            items_object = items_object.value(items_object.keys().at(0)).toObject();
                        if(items_object.contains("@QualityField"))
                        {
                            items_value = items_object.take("@QualityField");
                           if(items_value.toString()=="good")
                             items_list<<items_value.toString();
                           else
                             qDebug()<<"recieve false data"<<items_value.toString()<<items_list;
                        }
                    }
                }
//                qDebug()<<items_list;
                if(items_list.size()==4)//cuccess get four items
                    packandsend(items_list);


            }
            return true;
        }


    }
        //    keys 0 is  : "Items"

        return false;

}
