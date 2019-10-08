#include "protocol_anodizing.h"

Protocol_Anodizing::Protocol_Anodizing(QStringList section)//: Myprotocol(parent)
{
    msglist =section;

}


QString  Protocol_Anodizing::unpacklist()
{
     if(msglist.count()<PRO_NUM)//anodize | id  |  data
         return NULL;
    int pro_size =msglist.at(PRO_SIZE).toInt();

    if(msglist.size()<pro_size+PRO_NUM-1) // 数量不足
        return NULL;

    QString   str= " insert into test_alarm ";
       str +="(date_client,time_client,status,msg,date_server,time_server)  values" ;

for(int j=0;j<pro_size;j++)
{
    str += "(";
    anodize_Alarmlist = msglist.at(PRO_DATA+j).split(QRegExp("[\t]"));

    for(int i=0;i<anodize_Alarmlist.size();i++)
    {
        str +="'";
        str +=anodize_Alarmlist.at(i);
        str +="',";
    }
            str+="CURDATE(),CURTIME())";
            if(j!= pro_size-1)//当不是最后一项时，需要增加 “，”
             str +=",";
}
            str +=";";
        qDebug()<<str;
        //  ("2019-9-25","8:2:37","Ac","test1",CURDATE(),CURTIME());

        return str;
//   for(int i=0;i<anodize_Alarmlist.size();i++)
//       anodize_Alarmlist.at(i)=QString("%1").arg(anodize_Alarmlist.at(i));

}
