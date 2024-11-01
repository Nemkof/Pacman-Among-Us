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




