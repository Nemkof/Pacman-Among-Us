#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QMenu>
#include <QMainWindow>
#include "HistoryWindow.h"
#include "SettingsWidget.h"
#include "AboutGameWindow.h"
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
    void gamerunning(int& gameLevel);
private slots:

    void on_PlayButton_clicked();

    void on_ExitButton_clicked();

    void on_SettingsButton_clicked();

    void on_HistoryButton_clicked();

    void on_AboutButton_clicked();

private:
    Ui::MenuWindow *ui;
    HistoryWindow *historyWindow;
    AboutGameWidget *aboutGameWidget;
    Settings *settings;
};

#endif // MENUWINDOW_H
