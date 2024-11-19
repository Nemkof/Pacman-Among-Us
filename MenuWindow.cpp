#include "Headers/MenuWindow.h"
#include "Headers/Game.h"
#include "ui_MenuWindow.h"
#include <fstream>
#include "Headers/GameSettings.h"
#include <QDate>
//#include <QMovie>
MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("images/menu/BackgroundSmall.png");
    resize(bkgnd.width(), bkgnd.height());
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    setWindowIcon(QIcon("images/menu/icon.jpeg"));
    setWindowTitle("Pacman Among Us");

    ui->PlayButton->resize(200,200);
    // QMovie *movie = new QMovie("images/testGiss.gif");
    // ui->testLabel->setMovie(movie);
    // movie->start();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::gamerunning(int& gameLevel){
    if(game(gameLevel)) {
        gameLevel++;
        Sabotage::solvedTasks = 0;
        gamerunning((gameLevel));
    }
    else{
        this->show();

        std::ofstream file("history.csv", std::ios::app); // ios::app открывает файл для добавления данных в конец

        if (file.is_open()) {
            file << GameSettings::Nickname << ";" << (QDateTime::currentDateTime().toString("hh:mm dd.MM.yyyy")).toStdString()
                 << ";" << Player::score << ";" << (int)Player::gameTime << ";" << gameLevel << "\n";
            file.close();
        }
    }
}

void MenuWindow::on_PlayButton_clicked()
{
    this->hide();
    int gameLevel = 1;
    gamerunning(gameLevel);
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

void MenuWindow::on_HistoryButton_clicked()
{
    historyWindow = new HistoryWindow();
    historyWindow->show();
}


void MenuWindow::on_AboutButton_clicked()
{
    aboutGameWidget = new AboutGameWidget();
    aboutGameWidget->show();
}

