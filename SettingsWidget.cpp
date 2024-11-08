#include "SettingsWidget.h"
#include "ui_SettingsWidget.h"

Settings::Settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
    QPixmap messageIcon("images/menu/settings.png");
    setWindowIcon(messageIcon);
    ui->radioButton->setChecked(true);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_radioButton_clicked()
{

}

