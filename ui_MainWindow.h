/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_start;
    QTextBrowser *text_output;
    QLabel *label_IP;
    QPushButton *pushButton;
    QTextBrowser *textBrowser_server;
    QTextEdit *textEdit_port;
    QTextEdit *textEdit_send;
    QPushButton *pushButton_send;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_connect;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(460, 50, 75, 23));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(50, 30, 75, 23));
        text_output = new QTextBrowser(centralWidget);
        text_output->setObjectName(QString::fromUtf8("text_output"));
        text_output->setGeometry(QRect(460, 80, 311, 211));
        label_IP = new QLabel(centralWidget);
        label_IP->setObjectName(QString::fromUtf8("label_IP"));
        label_IP->setGeometry(QRect(140, 230, 271, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 300, 101, 31));
        textBrowser_server = new QTextBrowser(centralWidget);
        textBrowser_server->setObjectName(QString::fromUtf8("textBrowser_server"));
        textBrowser_server->setGeometry(QRect(50, 70, 371, 151));
        textEdit_port = new QTextEdit(centralWidget);
        textEdit_port->setObjectName(QString::fromUtf8("textEdit_port"));
        textEdit_port->setGeometry(QRect(110, 310, 201, 31));
        textEdit_send = new QTextEdit(centralWidget);
        textEdit_send->setObjectName(QString::fromUtf8("textEdit_send"));
        textEdit_send->setGeometry(QRect(40, 360, 281, 61));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(340, 370, 81, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 240, 72, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 320, 72, 16));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(320, 290, 101, 51));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "server", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        label_IP->setText(QCoreApplication::translate("MainWindow", "--------", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272IP", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\347\253\257\345\217\243", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
