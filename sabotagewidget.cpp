#include "sabotagewidget.h"
#include "ui_sabotagewidget.h"

sabotageWidget::sabotageWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sabotageWidget)
{
    ui->setupUi(this);


    questionNumber = rand() % (questions.size());
    QString task = QString::fromStdString(questions.at(questionNumber).first);
    ui->taskLabel->setText(task);
    QPixmap messageIcon("../../images/sabotageIcon.png");
    setWindowIcon(messageIcon);
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
    QPixmap messageIcon("../../images/sabotageIcon.png");
    message->setWindowTitle("Result");
    message->setWindowIcon(messageIcon);

    if((answer != nullptr) && (answer.toInt() == questions.at(questionNumber).second)){
        status = Condition::Solved;
        message->setText("Success!");
        message->show();
    }
    else{
        status = Condition::notSolved;
        message->setText("Error!");
        message->show();
    }
    close();
}

