#include "Headers/HistoryWindow.h"
#include "Headers/ui_HistoryWindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

HistoryWindow::HistoryWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
    QIcon icon("images/menu/HistoryIcon.png");
    setWindowIcon(icon);
    setWindowTitle("History of games");
    csvModel = new QStandardItemModel(this);

    csvModel->setColumnCount(5);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Nickname" << "Date" << "Score" << "Game time " << "Levels");
    ui->tableView->setModel(csvModel);

    QFile file("history.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            // Добавляем в модель по строке с элементами
            QList<QStandardItem *> standardItemsList;
            // учитываем, что строка разделяется точкой с запятой на колонки
            for (QString item : line.split(";")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        }
        file.close();
    }
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}
