#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "GameManager.h"

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

