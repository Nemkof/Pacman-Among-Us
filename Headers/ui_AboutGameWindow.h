/********************************************************************************
** Form generated from reading UI file 'AboutGameWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTGAMEWINDOW_H
#define UI_ABOUTGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutGameWidget
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AboutGameWidget)
    {
        if (AboutGameWidget->objectName().isEmpty())
            AboutGameWidget->setObjectName("AboutGameWidget");
        AboutGameWidget->resize(411, 317);
        label = new QLabel(AboutGameWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 60, 101, 16));
        label_2 = new QLabel(AboutGameWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 20, 361, 41));

        retranslateUi(AboutGameWidget);

        QMetaObject::connectSlotsByName(AboutGameWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutGameWidget)
    {
        AboutGameWidget->setWindowTitle(QCoreApplication::translate("AboutGameWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("AboutGameWidget", "AboutGame", nullptr));
        label_2->setText(QCoreApplication::translate("AboutGameWidget", "If you want read about this game, you can click to this link:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutGameWidget: public Ui_AboutGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTGAMEWINDOW_H
