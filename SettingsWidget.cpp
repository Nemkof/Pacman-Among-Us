#include "Headers/SettingsWidget.h"
#include "ui_SettingsWidget.h"
#include "Headers/GameSettings.h"
string GameSettings::Nickname = "player";
Controller GameSettings::controller = Controller::Arrows;
bool GameSettings::Sounds = true;

Settings::Settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
    QPixmap messageIcon("images/menu/settings.png");
    setWindowIcon(messageIcon);
    ui->soundsBox->setChecked(true);
    ui->ButtonArrows->setChecked(true);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    if(ui->ButtonLetters->isChecked()) GameSettings::controller = Controller::Letters;
    else GameSettings::controller = Controller::Arrows;

    if(ui->soundsBox->isChecked()) GameSettings::Sounds = true;
    else GameSettings::Sounds = false;

    std::string name = (ui->nameLine->text()).toStdString();
    if(name.size() == 0) name = "Player";
    else if(name.size() > 10) name = name.substr(0, 10);
    GameSettings::Nickname = name;
    ui->nameLine->setText(QString::fromStdString(name));
}

