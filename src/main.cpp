#include <QApplication>
#include "MenuWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow* Menu = new MenuWindow();
    Menu->show();

    return a.exec();
}

