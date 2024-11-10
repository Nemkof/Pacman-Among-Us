/********************************************************************************
** Form generated from reading UI file 'MenuWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *PlayButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *HistoryButton;
    QVBoxLayout *verticalLayout_2;
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
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(430, 290, 241, 151));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        PlayButton = new QPushButton(verticalLayoutWidget_3);
        PlayButton->setObjectName("PlayButton");

        verticalLayout_3->addWidget(PlayButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        HistoryButton = new QPushButton(verticalLayoutWidget_3);
        HistoryButton->setObjectName("HistoryButton");

        verticalLayout->addWidget(HistoryButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        SettingsButton = new QPushButton(verticalLayoutWidget_3);
        SettingsButton->setObjectName("SettingsButton");

        verticalLayout_2->addWidget(SettingsButton);

        ExitButton = new QPushButton(verticalLayoutWidget_3);
        ExitButton->setObjectName("ExitButton");

        verticalLayout_2->addWidget(ExitButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

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
        HistoryButton->setText(QCoreApplication::translate("MenuWindow", "History", nullptr));
        SettingsButton->setText(QCoreApplication::translate("MenuWindow", "Settings", nullptr));
        ExitButton->setText(QCoreApplication::translate("MenuWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
