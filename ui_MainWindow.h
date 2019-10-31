/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
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
    QTextEdit *textEdit_pub;
    QPushButton *pushButton_pub;
    QPushButton *pushButton_subs;
    QTextEdit *textEdit_sub;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(460, 50, 75, 23));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(50, 30, 75, 23));
        text_output = new QTextBrowser(centralWidget);
        text_output->setObjectName(QStringLiteral("text_output"));
        text_output->setGeometry(QRect(460, 80, 311, 211));
        label_IP = new QLabel(centralWidget);
        label_IP->setObjectName(QStringLiteral("label_IP"));
        label_IP->setGeometry(QRect(140, 230, 271, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 300, 101, 31));
        textBrowser_server = new QTextBrowser(centralWidget);
        textBrowser_server->setObjectName(QStringLiteral("textBrowser_server"));
        textBrowser_server->setGeometry(QRect(50, 70, 371, 151));
        textEdit_port = new QTextEdit(centralWidget);
        textEdit_port->setObjectName(QStringLiteral("textEdit_port"));
        textEdit_port->setGeometry(QRect(110, 310, 201, 31));
        textEdit_send = new QTextEdit(centralWidget);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));
        textEdit_send->setGeometry(QRect(40, 360, 281, 61));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(340, 370, 81, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 240, 72, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 320, 72, 16));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(320, 290, 101, 51));
        textEdit_pub = new QTextEdit(centralWidget);
        textEdit_pub->setObjectName(QStringLiteral("textEdit_pub"));
        textEdit_pub->setGeometry(QRect(70, 450, 261, 41));
        pushButton_pub = new QPushButton(centralWidget);
        pushButton_pub->setObjectName(QStringLiteral("pushButton_pub"));
        pushButton_pub->setGeometry(QRect(340, 450, 80, 41));
        pushButton_subs = new QPushButton(centralWidget);
        pushButton_subs->setObjectName(QStringLiteral("pushButton_subs"));
        pushButton_subs->setGeometry(QRect(340, 510, 80, 51));
        textEdit_sub = new QTextEdit(centralWidget);
        textEdit_sub->setObjectName(QStringLiteral("textEdit_sub"));
        textEdit_sub->setGeometry(QRect(70, 510, 261, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 460, 59, 15));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "server", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "stop", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "start", nullptr));
        label_IP->setText(QApplication::translate("MainWindow", "--------", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "next", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "send", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\344\270\273\346\234\272IP", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\270\273\346\234\272\347\253\257\345\217\243", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "connect", nullptr));
        pushButton_pub->setText(QApplication::translate("MainWindow", "publish", nullptr));
        pushButton_subs->setText(QApplication::translate("MainWindow", "subscribe", nullptr));
        label->setText(QApplication::translate("MainWindow", "topic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
