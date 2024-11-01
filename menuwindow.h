#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QMenu>
#include <QMainWindow>
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

    int volume = 5;

private slots:

    void on_PlayButton_clicked();

    void on_ExitButton_clicked();

    void on_SettingsButton_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
