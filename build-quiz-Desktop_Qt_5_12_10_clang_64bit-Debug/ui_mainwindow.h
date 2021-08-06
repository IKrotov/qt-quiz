/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *questionGroupBox;
    QPushButton *replyButton;
    QPushButton *openFileButton;
    QLabel *timerLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        questionGroupBox = new QGroupBox(centralwidget);
        questionGroupBox->setObjectName(QString::fromUtf8("questionGroupBox"));
        questionGroupBox->setGeometry(QRect(160, 70, 501, 441));
        replyButton = new QPushButton(centralwidget);
        replyButton->setObjectName(QString::fromUtf8("replyButton"));
        replyButton->setGeometry(QRect(340, 520, 113, 32));
        openFileButton = new QPushButton(centralwidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(570, 30, 231, 41));
        timerLabel = new QLabel(centralwidget);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        timerLabel->setGeometry(QRect(440, 0, 201, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        questionGroupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202", nullptr));
        replyButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        openFileButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        timerLabel->setText(QApplication::translate("MainWindow", "0:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
