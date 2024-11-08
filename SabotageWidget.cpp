#include "SabotageWidget.h"
#include "ui_SabotageWidget.h"

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

std::string sabotageWidget::getStatus() {
    if(status == Condition::Solved) return "Solved";
    else if(status == Condition::notSolved) return "notSolved";
    else return "inProcess";
}

void sabotageWidget::on_checkButton_clicked()
{
    QString answer = ui->answerWidget->text();

    QMessageBox* message = new QMessageBox(nullptr);
    QPixmap messageIcon("images/menu/sabotageIcon.png");
    message->setWindowTitle("Result");
    message->setWindowIcon(messageIcon);

    if((answer != nullptr) && (answer.toInt() == questions.at(questionNumber).second)){
        status = Condition::Solved;
        message->setText("Sabotage is Success!");
        message->show();
    }
    else{
        status = Condition::notSolved;
        message->setText("Sabotage is Error! Try again later");
        message->show();
    }
    close();
}

