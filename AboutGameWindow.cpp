#include "AboutGameWindow.h"
#include "ui_AboutGameWindow.h"
#include <QMovie>
AboutGameWidget::AboutGameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutGameWidget)
{
    ui->setupUi(this);
    QPixmap messageIcon("images/menu/about.png");
    setWindowIcon(messageIcon);

    ui->label->setText("<a href=https://github.com/Nemkof/Pacman-Among-Us/blob/main/README.md>github</a>");
    ui->label->setOpenExternalLinks(true);

}

AboutGameWidget::~AboutGameWidget()
{
    delete ui;
}
