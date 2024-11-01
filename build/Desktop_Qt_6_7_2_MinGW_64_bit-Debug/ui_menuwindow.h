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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *ExitButton;
    QPushButton *PlayButton;
    QPushButton *SettingsButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(800, 600);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(410, 240, 281, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ExitButton = new QPushButton(gridLayoutWidget);
        ExitButton->setObjectName("ExitButton");

        gridLayout->addWidget(ExitButton, 2, 0, 1, 1);

        PlayButton = new QPushButton(gridLayoutWidget);
        PlayButton->setObjectName("PlayButton");

        gridLayout->addWidget(PlayButton, 0, 0, 1, 1);

        SettingsButton = new QPushButton(gridLayoutWidget);
        SettingsButton->setObjectName("SettingsButton");

        gridLayout->addWidget(SettingsButton, 1, 0, 1, 1);

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
        ExitButton->setText(QCoreApplication::translate("MenuWindow", "Exit", nullptr));
        PlayButton->setText(QCoreApplication::translate("MenuWindow", "StartGame", nullptr));
        SettingsButton->setText(QCoreApplication::translate("MenuWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
