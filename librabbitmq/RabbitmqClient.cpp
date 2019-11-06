
#include "RabbitmqClient.h"

RabbitmqClient::RabbitmqClient()
{
    Py_Initialize();
        if (!Py_IsInitialized()) {
            return;
        }

        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('./python')");

        PyObject* pModule = PyImport_ImportModule("pythonstart");
        if (!pModule) {
            qDebug()<<"cant open python file";
            return;
        }

        PyObject* pFunHello = PyObject_GetAttrString(pModule,"test2");
        if (!pFunHello) {
            qDebug("get function hello failed");
            return;
        }

//        PyObject *pArgs=

        PyObject* pFunRes=  PyObject_CallFunction(pFunHello,NULL);



        int res_int;
        char* res_char;
      PyArg_Parse(pFunRes,"s",&res_char);
//      res_char = PyBytes_AsString(pFunRes);
//        res_char = PyByteArray_AsString(pFunRes);

        std::cout<<res_char<<"\r\n";
//        qDebug()<<res_str;
//        qDebug()<<res_int;
        qDebug()<<QString::fromLatin1(res_char);
        Py_DECREF(pFunRes);
        if (!pFunRes) {
            qDebug("cal function  failed");
            return;
        }

}
RabbitmqClient::~RabbitmqClient()
{

       Py_Finalize();
}

