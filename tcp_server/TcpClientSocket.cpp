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
    while (bytesAvailable()>0)
    {
        int length  =   bytesAvailable();
        char buf[1024];
        read(buf,length);
        QString msg =buf;
        emit    signalupdataClients(msg,length);
    }

}
void    TcpClientSocket::slotDisconnected()
{
        emit    signaldisconnect(this->socketDescriptor());

}
