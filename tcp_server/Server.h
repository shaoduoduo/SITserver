#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include    <QTcpServer>
#include    <tcp_server/TcpClientSocket.h>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr,int port =0);
    ~Server();

    QList<TcpClientSocket*>tcpclientsocketList;

signals:
    void    updataServer(QString,int);



public slots:
    void    updataClients(QString,int);
    void    slotDisconnected(int);

protected:
    void    incomingConnection(qintptr  socketDescriptor);

};

#endif // SERVER_H
