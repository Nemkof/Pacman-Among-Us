#include <QApplication>
#include "menuwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow Menu;
    Menu.show();

    // У квадратика в map координаты x и y - координаты левого верхнего угла в пикселях
    // У нашего героя размер 90х90 пикселей
    // Координаты центра игрока -
    // Идея - игрок должен поворачивать, запоминать координаты поворота
    // И на следующем повороте проверять, вдруг он тут только что поворачивал
    // В этом случае нужно прерывать поворот

    return a.exec();
}


// #include "sabotagewidget.h"
// #include "ui_sabotagewidget.h"

// sabotageWidget::sabotageWidget(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::sabotageWidget)
// {
//     ui->setupUi(this);

//     taskLabel = new QLabel();

//     int questionNumber = rand() % (questions.size());
//     QString task = QString::fromStdString(questions.at(questionNumber).first);
//     taskLabel->setText(task);

//     taskLabel->show();
// }

// sabotageWidget::~sabotageWidget()
// {
//     delete ui;
//     delete taskLabel;

// }





// #ifndef SABOTAGEWIDGET_H
// #define SABOTAGEWIDGET_H

// #include <QWidget>
// #include <QLabel>
// const std::vector<std::pair<std::string, int> > questions = {
//     {"Чему равна функция Эйлера от 2?", 1},
//     {"Чему равна функция Эйлера от 3?", 2},
//     {"Чему равна функция Эйлера от 4?", 2},
//     {"Чему равна функция Эйлера от 5?", 4},
//     {"Чему равна функция Эйлера от 6?", 2},
//     {"Чему равна функция Эйлера от 7?", 6},
//     {"Чему равна функция Эйлера от 8?", 4},
//     {"Чему равна функция Эйлера от 9?", 6},
//     {"Чему равна функция Эйлера от 10?", 4},
//     };

// namespace Ui {
// class sabotageWidget;
// }

// class sabotageWidget : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit sabotageWidget(QWidget *parent = nullptr);
//     ~sabotageWidget();

// private slots:


// private:
//     Ui::sabotageWidget *ui;
//     QLabel* taskLabel;
// };

// #endif // SABOTAGEWIDGET_H
