/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PlayButton;
    QPushButton *SettingsButton;
    QPushButton *ExitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(800, 600);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        PlayButton = new QPushButton(centralwidget);
        PlayButton->setObjectName("PlayButton");
        PlayButton->setGeometry(QRect(290, 390, 181, 61));
        SettingsButton = new QPushButton(centralwidget);
        SettingsButton->setObjectName("SettingsButton");
        SettingsButton->setGeometry(QRect(550, 390, 241, 51));
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(290, 500, 201, 41));
        MenuWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MenuWindow);
        statusbar->setObjectName("statusbar");
        MenuWindow->setStatusBar(statusbar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "MainWindow", nullptr));
        PlayButton->setText(QCoreApplication::translate("MenuWindow", "StartGame", nullptr));
        SettingsButton->setText(QCoreApplication::translate("MenuWindow", "Settings", nullptr));
        ExitButton->setText(QCoreApplication::translate("MenuWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
