#ifndef SABOTAGEWIDGET_H
#define SABOTAGEWIDGET_H

#include <QWidget>

namespace Ui {
class sabotageWidget;
}

class sabotageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sabotageWidget(QWidget *parent = nullptr);
    ~sabotageWidget();

private:
    Ui::sabotageWidget *ui;
};

#endif // SABOTAGEWIDGET_H
