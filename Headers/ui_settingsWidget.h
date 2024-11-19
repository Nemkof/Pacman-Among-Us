/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *ButtonLetters;
    QRadioButton *ButtonArrows;
    QCheckBox *soundsBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *nameLine;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(368, 300);
        verticalLayoutWidget_2 = new QWidget(Settings);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(16, 30, 341, 208));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        ButtonLetters = new QRadioButton(verticalLayoutWidget_2);
        ButtonLetters->setObjectName("ButtonLetters");

        verticalLayout->addWidget(ButtonLetters);

        ButtonArrows = new QRadioButton(verticalLayoutWidget_2);
        ButtonArrows->setObjectName("ButtonArrows");

        verticalLayout->addWidget(ButtonArrows);


        horizontalLayout->addLayout(verticalLayout);

        soundsBox = new QCheckBox(verticalLayoutWidget_2);
        soundsBox->setObjectName("soundsBox");

        horizontalLayout->addWidget(soundsBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        nameLine = new QLineEdit(verticalLayoutWidget_2);
        nameLine->setObjectName("nameLine");

        horizontalLayout_3->addWidget(nameLine);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Form", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Navigation Keys", nullptr));
        ButtonLetters->setText(QCoreApplication::translate("Settings", "W/A/S/D", nullptr));
        ButtonArrows->setText(QCoreApplication::translate("Settings", "Up/Down/Left/Right", nullptr));
        soundsBox->setText(QCoreApplication::translate("Settings", "Sounds", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "Your nickname:", nullptr));
        nameLine->setText(QCoreApplication::translate("Settings", "Player", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "(from 1 to 10 characters)", nullptr));
        pushButton->setText(QCoreApplication::translate("Settings", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
