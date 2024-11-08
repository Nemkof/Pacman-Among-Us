#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H
#include <QStandardItemModel>
#include <QWidget>
#include <QTableView>
namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();
    QTableView* tableView;

private:
    Ui::HistoryWindow *ui;
    QStandardItemModel *csvModel;
};

#endif // HISTORYWINDOW_H
