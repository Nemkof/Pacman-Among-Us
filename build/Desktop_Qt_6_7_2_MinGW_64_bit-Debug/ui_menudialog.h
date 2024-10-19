/********************************************************************************
** Form generated from reading UI file 'menudialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUDIALOG_H
#define UI_MENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_MenuDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MenuDialog)
    {
        if (MenuDialog->objectName().isEmpty())
            MenuDialog->setObjectName("MenuDialog");
        MenuDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MenuDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 50, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(MenuDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MenuDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MenuDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MenuDialog);
    } // setupUi

    void retranslateUi(QDialog *MenuDialog)
    {
        MenuDialog->setWindowTitle(QCoreApplication::translate("MenuDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuDialog: public Ui_MenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUDIALOG_H
