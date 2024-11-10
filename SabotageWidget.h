#ifndef SABOTAGEWIDGET_H
#define SABOTAGEWIDGET_H

#include <QDialog>
#include <QMessageBox>
const std::vector<std::pair<std::string, int> > questions = {
    {"What is the Euler function of 2?", 1},
    {"What is the Euler function of 3?", 2},
    {"What is the Euler function of 4?", 2},
    {"What is the Euler function of 5?", 4},
    {"What is the Euler function of 6?", 2},
    {"What is the Euler function of 7?", 6},
    {"What is the Euler function of 8?", 4},
    {"What is the Euler function of 9?", 6},
    {"What is the Euler function of 10?", 4},
    };

namespace Ui { class sabotageWidget; }

enum class SabotageCondition{
    Finished,
    inProcess
};

class sabotageWidget : public QDialog
{
    Q_OBJECT

public:
    explicit sabotageWidget(QWidget *parent = nullptr);
    ~sabotageWidget();
    SabotageCondition getStatus();
private slots:
    void on_checkButton_clicked();

private:
    int questionNumber;
    Ui::sabotageWidget *ui;
    SabotageCondition status = SabotageCondition::inProcess;
};

#endif // SABOTAGEWIDGET_H
