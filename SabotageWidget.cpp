#include "SabotageWidget.h"
#include "ui_SabotageWidget.h"
#include "Sabotages.h"
sabotageWidget::sabotageWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sabotageWidget)
{
    ui->setupUi(this);

    questionNumber = rand() % (questions.size());
    QString task = QString::fromStdString(questions.at(questionNumber).first);
    ui->taskLabel->setText(task);
    QPixmap messageIcon("images/menu/sabotageIcon.png");
    setWindowIcon(messageIcon);
    setWindowTitle("Sabotage");
    //ui->taskLabel->show();
}

sabotageWidget::~sabotageWidget()
{
    delete ui;
}

SabotageCondition sabotageWidget::getStatus() {
    if(status == SabotageCondition::Finished) return SabotageCondition::Finished;
    else return SabotageCondition::inProcess;
}

void sabotageWidget::on_checkButton_clicked()
{
    QString answer = ui->answerWidget->text();

    QMessageBox* message = new QMessageBox(nullptr);
    QPixmap messageIcon("images/menu/sabotageIcon.png");
    message->setWindowTitle("Result");
    message->setWindowIcon(messageIcon);

    if((answer != nullptr) && (answer.toInt() == questions.at(questionNumber).second)){
        status = SabotageCondition::Finished;
        message->setText("Sabotage is Success!");
        message->show();
        Sabotage::setSolvedTasks();
    }
    else{
        status = SabotageCondition::Finished;
        message->setText("Sabotage is Error! Try again later");
        message->show();
    }
    close();
}

