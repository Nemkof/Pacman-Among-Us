/********************************************************************************
** Form generated from reading UI file 'aboutgamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTGAMEWIDGET_H
#define UI_ABOUTGAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutGameWidget
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_5;

    void setupUi(QWidget *AboutGameWidget)
    {
        if (AboutGameWidget->objectName().isEmpty())
            AboutGameWidget->setObjectName("AboutGameWidget");
        AboutGameWidget->resize(665, 346);
        label_2 = new QLabel(AboutGameWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 20, 81, 16));
        label_3 = new QLabel(AboutGameWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 160, 111, 16));
        label_4 = new QLabel(AboutGameWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 150, 91, 16));
        verticalLayoutWidget = new QWidget(AboutGameWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 30, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);


        retranslateUi(AboutGameWidget);

        QMetaObject::connectSlotsByName(AboutGameWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutGameWidget)
    {
        AboutGameWidget->setWindowTitle(QCoreApplication::translate("AboutGameWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("AboutGameWidget", "Energizers", nullptr));
        label_3->setText(QCoreApplication::translate("AboutGameWidget", "Ventilation", nullptr));
        label_4->setText(QCoreApplication::translate("AboutGameWidget", "Lives", nullptr));
        label->setText(QCoreApplication::translate("AboutGameWidget", "Sabotages", nullptr));
        label_5->setText(QCoreApplication::translate("AboutGameWidget", "SabGif", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutGameWidget: public Ui_AboutGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTGAMEWIDGET_H
