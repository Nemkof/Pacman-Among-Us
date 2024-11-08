#include "MenuWindow.h"
#include "Game.h"
#include "ui_MenuWindow.h"
#include "Game.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("images/menu/Background.png");
    resize(bkgnd.width(), bkgnd.height());
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    setWindowIcon(QIcon("images/menu/icon.jpeg"));
    setWindowTitle("Pacman Among Us");

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
    settings = new Settings();
    settings->show();
}


void MenuWindow::on_HowToPlay_clicked()
{
    historyWindow = new HistoryWindow();
    historyWindow->show();
}

