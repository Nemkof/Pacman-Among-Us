#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QMenu>
#include <QMainWindow>
#include "HistoryWindow.h"
#include "SettingsWidget.h"
namespace Ui {
class MenuWindow;
class SettingsWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:

    void on_PlayButton_clicked();

    void on_ExitButton_clicked();

    void on_SettingsButton_clicked();

    void on_HowToPlay_clicked();

private:
    Ui::MenuWindow *ui;
    HistoryWindow *historyWindow;
    Settings *settings;
};

#endif // MENUWINDOW_H
