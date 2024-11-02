#include "sabotagewidget.h"
#include "ui_sabotagewidget.h"

sabotageWidget::sabotageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sabotageWidget)
{
    ui->setupUi(this);
    QLabel label("Task");
    label.show();
}

sabotageWidget::~sabotageWidget()
{
    delete ui;
}
