#include "protocol_anodizing.h"

Protocol_Anodizing::Protocol_Anodizing(QStringList section)//: Myprotocol(parent)
{
    msglist =section;

}


QString  Protocol_Anodizing::unpacklist()
{
     if(msglist.count()<3)//anodize | id  |  data
         return NULL;

   anodize_Alarmlist = msglist.at(2).split(QRegExp("[\t]"));
  //  for(int i=0;i<anodize_Alarmlist.size();i++)
        qDebug()<<anodize_Alarmlist;

       QString   str= " insert into test_alarm ";
          str +="(date_client,time_client,status,msg,date_server,time_server)" ;
          str += " values (";

             for(int i=0;i<anodize_Alarmlist.size();i++)
             {
                           std::string sss ;
                           sss.clear();
                           sss.append("\"");
                           sss.append(anodize_Alarmlist.at(i).toStdString());
                           sss.append("\"");
                           str +=QString::fromStdString(sss);
                // sss=+anodize_Alarmlist.at(i);
             }
        str+=",CURDATE(),CURTIME())";
        qDebug()<<str;
        //  ("2019-9-25","8:2:37","Ac","test1",CURDATE(),CURTIME());


//   for(int i=0;i<anodize_Alarmlist.size();i++)
//       anodize_Alarmlist.at(i)=QString("%1").arg(anodize_Alarmlist.at(i));

}
