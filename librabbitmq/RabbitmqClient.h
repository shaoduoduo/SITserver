#ifndef RABBITMQCLIENT_H
#define RABBITMQCLIENT_H

#include <Python.h>
#include <QObject>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QTimer>


class RabbitmqClient : public QObject
{
    Q_OBJECT
public:
    explicit RabbitmqClient();
~RabbitmqClient();

                QTimer *m_pTimer;//定时器

signals:


public slots:




private:

};




#endif // RABBITMQCLIENT_H
