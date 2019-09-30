#ifndef PTOTOCOL_ANODIZING_H
#define PTOTOCOL_ANODIZING_H
#include "protocol.h"
#include    <qDebug>

//专用封装类。用于封装特定接口，增加特定参数属性

class Protocol_Anodizing : public Myprotocol
{
public:
    Protocol_Anodizing(QStringList section);

    QString  unpacklist();//处理协议，返回固定格式

private:
//特定接口对应的参数

    QStringList msglist;
    QStringList anodize_Alarmlist;



    bool flag;
    char check;


};

#endif // PTOTOCOL_ANODIZING_H
