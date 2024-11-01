/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QSlider *horizontalSlider;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(480, 640);
        SettingsWindow->setMinimumSize(QSize(480, 0));
        horizontalSlider = new QSlider(SettingsWindow);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(280, 50, 160, 16));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
