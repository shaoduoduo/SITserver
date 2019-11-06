
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

        PyObject* pFunHello = PyObject_GetAttrString(pModule,"hello");
        if (!pFunHello) {
            qDebug("get function hello failed");
            return;
        }

        PyObject_CallFunction(pFunHello,NULL);

}
RabbitmqClient::~RabbitmqClient()
{

       Py_Finalize();
}

