#include "TcpClientSocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
{

    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));


    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

TcpClientSocket::~TcpClientSocket()
{


}
void    TcpClientSocket::dataReceived()
{
//    while (bytesAvailable()>0)
//    {
//        int length  =   bytesAvailable();
//        char buf[1024];
//        read(buf,length);
//        QString msg =buf;
//        emit    signalupdataClients(msg,length);
//    }
//解决了数据包最后有出现乱码的问题
        QByteArray array = readAll();
        QString     msg  = array;
        emit    signalupdataClients(msg,array.size());

}
void    TcpClientSocket::slotDisconnected()
{
        emit    signaldisconnect(this->socketDescriptor());

}
