/********************************************************************************
** Form generated from reading UI file 'sabotagewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SABOTAGEWIDGET_H
#define UI_SABOTAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sabotageWidget
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *sabotageWidget)
    {
        if (sabotageWidget->objectName().isEmpty())
            sabotageWidget->setObjectName("sabotageWidget");
        sabotageWidget->resize(480, 409);
        pushButton = new QPushButton(sabotageWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 240, 80, 24));
        label = new QLabel(sabotageWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 110, 251, 61));

        retranslateUi(sabotageWidget);

        QMetaObject::connectSlotsByName(sabotageWidget);
    } // setupUi

    void retranslateUi(QWidget *sabotageWidget)
    {
        sabotageWidget->setWindowTitle(QCoreApplication::translate("sabotageWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("sabotageWidget", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("sabotageWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sabotageWidget: public Ui_sabotageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SABOTAGEWIDGET_H
