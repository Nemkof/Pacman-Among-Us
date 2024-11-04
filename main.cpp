#include <QApplication>
#include "menuwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow Menu;
    Menu.show();

    return a.exec();
}

