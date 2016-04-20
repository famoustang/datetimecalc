#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDateEdit>
#include <time.h>
#include <QDebug>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void PushButtonCalcSlot();
    void PushButtonCalc_2_Slot();
    void CheckBox_Change_Slot();
    void CheckBox_isLocalTime_Slot();
};

#endif // WIDGET_H
