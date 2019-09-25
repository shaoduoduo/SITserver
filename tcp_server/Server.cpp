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

    emit    updataServer(msg,length);//service updata to mianwindow.cpp
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
