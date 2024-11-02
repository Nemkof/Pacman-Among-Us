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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sabotageWidget
{
public:
    QLabel *taskLabel;
    QPushButton *checkButton;
    QLineEdit *answerWidget;

    void setupUi(QDialog *sabotageWidget)
    {
        if (sabotageWidget->objectName().isEmpty())
            sabotageWidget->setObjectName("sabotageWidget");
        sabotageWidget->resize(407, 204);
        taskLabel = new QLabel(sabotageWidget);
        taskLabel->setObjectName("taskLabel");
        taskLabel->setGeometry(QRect(40, 20, 199, 92));
        checkButton = new QPushButton(sabotageWidget);
        checkButton->setObjectName("checkButton");
        checkButton->setGeometry(QRect(190, 160, 199, 24));
        answerWidget = new QLineEdit(sabotageWidget);
        answerWidget->setObjectName("answerWidget");
        answerWidget->setGeometry(QRect(230, 130, 113, 24));

        retranslateUi(sabotageWidget);

        QMetaObject::connectSlotsByName(sabotageWidget);
    } // setupUi

    void retranslateUi(QDialog *sabotageWidget)
    {
        sabotageWidget->setWindowTitle(QCoreApplication::translate("sabotageWidget", "Dialog", nullptr));
        taskLabel->setText(QCoreApplication::translate("sabotageWidget", "TextLabel", nullptr));
        checkButton->setText(QCoreApplication::translate("sabotageWidget", "Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sabotageWidget: public Ui_sabotageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SABOTAGEWIDGET_H
