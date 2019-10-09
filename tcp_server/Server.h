#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include    <QTcpServer>
#include    <tcp_server/TcpClientSocket.h>
#include    <QByteArray>

#include "protocol/protocol_anodizing.h"
#include    <QTimer>
#include    <QThread>
#define  TIMER_TIMEOUT_SERVER  8000
class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(int port =0);
    ~Server();

    QList<TcpClientSocket*>tcpclientsocketList;

signals:
    void    updataServer(QString,int);
    void    updataSQL(QString);
private:
    Protocol_Anodizing * pro_anodizing;
    QTimer *m_pTimer;//定时器
public slots:
     void doWork();
     void start();
     void stop();


    void    updataClients(QString,int);
    void    slotDisconnected(int);
    void    handleTimeout();

protected:
    void    incomingConnection(qintptr  socketDescriptor);
    bool    Flag_receive;
};

#endif // SERVER_H
