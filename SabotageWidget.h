#ifndef SABOTAGEWIDGET_H
#define SABOTAGEWIDGET_H

#include <QDialog>
#include <QMessageBox>
const std::vector<std::pair<std::string, int> > questions = {
    {"Чему равна функция Эйлера от 2?", 1},
    {"Чему равна функция Эйлера от 3?", 2},
    {"Чему равна функция Эйлера от 4?", 2},
    {"Чему равна функция Эйлера от 5?", 4},
    {"Чему равна функция Эйлера от 6?", 2},
    {"Чему равна функция Эйлера от 7?", 6},
    {"Чему равна функция Эйлера от 8?", 4},
    {"Чему равна функция Эйлера от 9?", 6},
    {"Чему равна функция Эйлера от 10?", 4},
    };

namespace Ui {
class sabotageWidget;
}
enum class Condition{
    Solved,
    notSolved,
    inProcess
};

class sabotageWidget : public QDialog
{
    Q_OBJECT

public:
    explicit sabotageWidget(QWidget *parent = nullptr);
    ~sabotageWidget();
    std::string getStatus();
private slots:
    void on_checkButton_clicked();

private:
    int questionNumber;
    Ui::sabotageWidget *ui;
    Condition status = Condition::inProcess;
};

#endif // SABOTAGEWIDGET_H
