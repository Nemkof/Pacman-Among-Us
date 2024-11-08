#include "HistoryWindow.h"
#include "ui_HistoryWindow.h"

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

    csvModel->setColumnCount(4);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Nickname" << "Date" << "Score" << "Levels");
    ui->tableView->setModel(csvModel); // Устанавливаем модель в таблицу
    //tableView->sortByColumn(3, Qt::SortOrder::AscendingOrder);

    // Открываем файл из ресурсов. Вместо данного файла
    // необходимо указывать путь к вашему требуемому файлу
    QFile file("testing.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file);
        // Считываем данные до конца файла
        while (!in.atEnd())
        {
            // ... построчно
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
