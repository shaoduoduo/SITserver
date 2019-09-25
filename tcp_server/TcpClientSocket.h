#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include    <QTcpSocket>
#include    <QString>

//创建套接字，实现和客户端通信
class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = nullptr);
    ~TcpClientSocket();


signals:
    void    signalupdataClients(QString,int);
    void    signaldisconnect(int);


public slots:
    void    dataReceived();//
    void    slotDisconnected();


};

#endif // TCPCLIENTSOCKET_H
