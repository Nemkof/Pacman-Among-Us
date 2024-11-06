#include "menuwindow.h"
#include "Game.h"
#include "ui_menuwindow.h"
#include "Game.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("../../images/menu/Background.png");
    resize(bkgnd.width(), bkgnd.height());
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    setWindowIcon(QIcon("../../images/menu/icon.jpeg"));


}

MenuWindow::~MenuWindow()
{
    delete ui;
}


void MenuWindow::on_PlayButton_clicked()
{
    this->close();
    game();
}


void MenuWindow::on_ExitButton_clicked()
{
    this->close();
}


void MenuWindow::on_SettingsButton_clicked()
{

}

