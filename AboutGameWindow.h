#ifndef ABOUTGAMEWINDOW_H
#define ABOUTGAMEWINDOW_H

#include <QWidget>

namespace Ui {
class AboutGameWidget;
}

class AboutGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AboutGameWidget(QWidget *parent = nullptr);
    ~AboutGameWidget();

private:
    Ui::AboutGameWidget *ui;
};

#endif // ABOUTGAMEWINDOW_H
