#include "Server.h"

Server::Server(int port)
{
    listen(QHostAddress::Any,port);
    Flag_receive =false;


}

Server::~Server()
{

    delete m_pTimer;
}

void Server::doWork()
{


    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start(TIMER_TIMEOUT_SERVER);

    if(Flag_receive==false)
    {
        //connect out

    }
    else {
        //is connecting
        Flag_receive =false;
    }
}

void Server::start()
{
    doWork();

}

void Server::stop()
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
    QString str;
    //收到客户端上传数据
        emit    updataServer(msg,length);//service updata to mianwindow.cpp
  //      qDebug()<<msg;
    //"0,5,2019/8/24\t9:34:19\tDN\tDN19082409280001\t5\t0?"
     QStringList sections = msg.split(QRegExp("[,]")); //把每一个块装进一个QStringList中
    // ANODIZE,//阳极氧化数据
    // PLASMA,
    // OPC,
    // ARCSPRAY,
    // OEE,
    if(sections.count()<PRO_SIZE)//包数量不足2
        return;
     switch (sections.at(PRO_INDEX).toInt())
     {
             case ANODIZE://阳极氧化数据
                 if(sections.at(PRO_ID).toInt()== HEART)
                 {
                    //收到HEART包
                        Flag_receive =true;
                     break;
                 }
                    pro_anodizing = new  Protocol_Anodizing(sections);

                     str = pro_anodizing->unpacklist();
                    //deal data
                    emit  updataSQL(str);
                    //save data

                    //release
                    delete  pro_anodizing;
                 break;

             default:
                 break;
     }
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


void Server::handleTimeout()
{
//        QString msg = QString("%1 -> %2 threadid:[%3]")
//                .arg(__FILE__)
//                .arg(__FUNCTION__)
//                .arg((uintptr_t)QThread::currentThreadId());
//        qDebug() << msg;

    if(m_pTimer->isActive()){
        m_pTimer->start();
    }
}

