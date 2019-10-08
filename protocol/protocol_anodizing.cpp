#include "protocol_anodizing.h"

Protocol_Anodizing::Protocol_Anodizing(QStringList section)//: Myprotocol(parent)
{
    msglist =section;

}


QString  Protocol_Anodizing::unpacklist()
{
        QString   str =NULL;
        str.clear();
             if(msglist.count()<PRO_NUM)//anodize | id  |  data
                 return NULL;
            int pro_size =msglist.at(PRO_SIZE).toInt();

            if(msglist.size()<pro_size+PRO_NUM-1) // 数量不足
                return NULL;
            switch (msglist.at(PRO_ID).toInt())
            {
            case ALARM:
                str = packALARM(msglist);
                break;
            case ANOD1:
                str = packANOD(msglist);
                break;
            case ANOD2:
                str = packANOD(msglist);
                break;
            case ANOD3:
                str = packANOD(msglist);
                break;
            case TCDATA1:
                str = packTC(msglist);
                break;
            case TCDATA2:
                str = packTC(msglist);
                break;
            case TEMPHIS:
                str = packTEMP(msglist);
                break;
            default:
                //str=NULL;
                break;
            }
                return str;


}

QString Protocol_Anodizing::packALARM(QStringList msglist)
{
        QStringList anodize_Alarmlist;
        int pro_size=msglist.at(PRO_SIZE).toInt();
        QString str;
        str= " insert into test_alarm ";
        str +="(date_client,time_client,status,msg,date_server,time_server)  values  " ;

        for(int j=0;j<pro_size;j++)//数据收到了多少组
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
                    return str;
}
QString Protocol_Anodizing::packANOD(QStringList msglist)
{
    int pro_size=msglist.at(PRO_SIZE).toInt();
    int index = msglist.at(PRO_ID).toInt();
    QStringList anodize_ANODlist;
    QString str;
    str= " insert into test_anod ";
    str +="(anod_index ,date_client,time_client,I_PV,U_PV,I_SV,U_SV,date_server,time_server) values  " ;

    for(int j=0;j<pro_size;j++)//数据收到了多少组
    {
        str += "(";

        str +="'";
        str +=QString::number(index-ALARM);
        str +="',";

        anodize_ANODlist = msglist.at(PRO_DATA+j).split(QRegExp("[\t]"));

        for(int i=0;i<anodize_ANODlist.size();i++)
        {
            str +="'";
            str +=anodize_ANODlist.at(i);
            str +="',";
        }
                str+="CURDATE(),CURTIME())";

                if(j!= pro_size-1)//当不是最后一项时，需要增加 “，”
                 str +=",";
    }
                str +=";";
                return str;
}
QString Protocol_Anodizing::packTC(QStringList)
{
    int pro_size=msglist.at(PRO_SIZE).toInt();
    int index = msglist.at(PRO_ID).toInt();
    QStringList anodize_TClist;
    QString str;
    str= " insert into test_tc ";
    str +="(tc_index ,date_client,time_client,no,code,pos,action,date_server,time_server) values  " ;

    for(int j=0;j<pro_size;j++)//数据收到了多少组
    {
        str += "(";

        str +="'";
        str +=QString::number(index-ANOD3);//调整位 1和2
        str +="',";

        anodize_TClist = msglist.at(PRO_DATA+j).split(QRegExp("[\t]"));

        for(int i=0;i<anodize_TClist.size();i++)
        {
            str +="'";
            str +=anodize_TClist.at(i);
            str +="',";
        }
                str+="CURDATE(),CURTIME())";

                if(j!= pro_size-1)//当不是最后一项时，需要增加 “，”
                 str +=",";
    }
                str +=";";
                return str;
}
QString Protocol_Anodizing::packTEMP(QStringList)
{
    QStringList anodize_TEMPlist;
    int pro_size=msglist.at(PRO_SIZE).toInt();
    QString str;
    str= " insert into test_temp ";
    str +="(date_client,time_client,A1,A3,A5,A7,A9,A11,A13,D1,\
       D3,A16,A18,A20,S1,S2,S3,date_server,time_server) values " ;

    for(int j=0;j<pro_size;j++)//数据收到了多少组
    {
        str += "(";
        anodize_TEMPlist = msglist.at(PRO_DATA+j).split(QRegExp("[\t]"));

        for(int i=0;i<anodize_TEMPlist.size();i++)
        {
            str +="'";
            str +=anodize_TEMPlist.at(i);
            str +="',";
        }
                str+="CURDATE(),CURTIME())";

                if(j!= pro_size-1)//当不是最后一项时，需要增加 “，”
                 str +=",";
    }
                str +=";";
                return str;
}
