#include "Server.h"

Server::Server(QObject *parent,int port):QTcpServer (parent)
{
    listen(QHostAddress::Any,port);

}

Server::~Server()
{


}
void    Server::incomingConnection(qintptr socketDescriptor)
{


//    void    signalupdataClients(QString,int);
//    void    signaldisconnect(int);

        QString msg = QString("%1 -> %2 ")
                .arg(__FILE__)
                .arg(__FUNCTION__);

        qDebug() << msg;
    TcpClientSocket *tcpclientSocket    =   new TcpClientSocket (this);
    connect(tcpclientSocket,&TcpClientSocket::signalupdataClients,this,&Server::updataClients);

    connect(tcpclientSocket,&TcpClientSocket::signaldisconnect,this,&Server::slotDisconnected);


    tcpclientSocket->setSocketDescriptor(socketDescriptor);
    tcpclientsocketList.append(tcpclientSocket);

}
void Server::updataClients(QString   msg,int length)
{
//收到客户端上传数据
    emit    updataServer(msg,length);//service updata to mianwindow.cpp
    qDebug()<<msg;
//"0,5,2019/8/24\t9:34:19\tDN\tDN19082409280001\t5\t0?"
 QStringList sections = msg.split(QRegExp("[,]")); //把每一个块装进一个QStringList中
// ANODIZE,//阳极氧化数据
// PLASMA,
// OPC,
// ARCSPRAY,
// OEE,

 switch (sections.at(0).toInt()) {

 case ANODIZE://阳极氧化数据
     if(sections.at(1).toInt()== HEART)
     {
        //收到HEART包

         break;
     }
        pro_anodizing = new  Protocol_Anodizing(sections);

        //deal data

        //save data

        //release
        delete  pro_anodizing;
     break;
 default:
     break;
 }
 //    for (int i=0;i<tcpclientsocketList.count();i++)
//    {
//        QTcpSocket  *item   =tcpclientsocketList.at(i);
//        if(item->write(msg.toLatin1(),length)!=length)
//        {
//            continue;
//        }
//    }
}

void    Server::slotDisconnected(int    descriptor)
{
    for(int i= 0;i<tcpclientsocketList.count();i++)
    {
        QTcpSocket  *item   =tcpclientsocketList.at(i);
        if(item->socketDescriptor()==descriptor )
        {
            tcpclientsocketList.removeAt(i);
            return;
        }
    }
}
