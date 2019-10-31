#-------------------------------------------------
#
# Project created by QtCreator 2019-09-24T08:44:40
#
#-------------------------------------------------

QT       += core gui
QT += network
QT       += core gui widgets
QT += sql
QT +=core network
QT +=mqtt
QT +=core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server_code
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        MoveToThreadTest.cpp \
        Thread_MySQL.cpp \
        main.cpp \
        MainWindow.cpp \
        protocol/protocol.cpp \
        protocol/protocol_anodizing.cpp \
        tcp_server/Server.cpp \
        tcp_server/TcpClientSocket.cpp \
    MQTTClient/MQTTClie.cpp \
    readconfig.cpp \
    logfile.cpp

HEADERS += \
        MainWindow.h \
        MoveToThreadTest.h \
        Thread_MySQL.h \
        protocol/protocol.h \
        protocol/protocol_anodizing.h \
        protocol/protocol_list.h \
        tcp_server/Server.h \
        tcp_server/TcpClientSocket.h \
    MQTTClient/MQTTClie.h \
    readconfig.h \
    logfile.h

FORMS += \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    说明.txt \
    mysql.txt \
    服务器端程序.txt \
    ../build-server_code-Desktop_Qt_5_11_0_GCC_64bit-Release/config.ini \
    ../build-server_code-Desktop_Qt_5_11_0_GCC_64bit-Release/config.ini
INCLUDEPATH +=$$PWD/include
