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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ExitButton;
    QPushButton *PlayButton;
    QPushButton *SettingsButton;
    QWidget *SettingsWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *HowToPlay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(800, 600);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(630, 440, 101, 41));
        PlayButton = new QPushButton(centralwidget);
        PlayButton->setObjectName("PlayButton");
        PlayButton->setGeometry(QRect(620, 250, 111, 71));
        SettingsButton = new QPushButton(centralwidget);
        SettingsButton->setObjectName("SettingsButton");
        SettingsButton->setGeometry(QRect(570, 390, 203, 41));
        SettingsWidget = new QWidget(centralwidget);
        SettingsWidget->setObjectName("SettingsWidget");
        SettingsWidget->setGeometry(QRect(230, 200, 331, 301));
        horizontalLayoutWidget = new QWidget(SettingsWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 20, 291, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        HowToPlay = new QPushButton(centralwidget);
        HowToPlay->setObjectName("HowToPlay");
        HowToPlay->setGeometry(QRect(610, 330, 131, 51));
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
        label->setText(QCoreApplication::translate("MenuWindow", "Volume", nullptr));
        HowToPlay->setText(QCoreApplication::translate("MenuWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
