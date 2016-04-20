#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setVisible(false);
    ui->dateEdit_Start->setDate(QDate(QDate::currentDate()));
    ui->lineEdit_Input_2->setText(QString::number(QDateTime::currentDateTime().toTime_t()));
    connect(ui->pushButtonCalc,SIGNAL(clicked()),this,SLOT(PushButtonCalcSlot()));
    connect(ui->pushButtonCalc_2,SIGNAL(clicked()),this,SLOT(PushButtonCalc_2_Slot()));
    connect(ui->checkBox_Change,SIGNAL(clicked()),this,SLOT(CheckBox_Change_Slot()));
    connect(ui->checkBox_LocalTime,SIGNAL(clicked()),this,SLOT(CheckBox_isLocalTime_Slot()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::PushButtonCalcSlot()
{
    if(ui->lineEdit_Input->text() == "")
    {
        ui->lineEdit_Input->setText("0");

    }
    int tempDate = ui->dateEdit_Start->date().toJulianDay();
    tempDate += ui->lineEdit_Input->text().toInt(0,10);
    ui->lineEdit_Output->setText(QDate::fromJulianDay(tempDate).toString("yyyy-MM-dd"));
}

void Widget::PushButtonCalc_2_Slot()
{
#if 0
    QDateTime cur_datetime  = QDateTime::currentDateTime();
    QDateTime ref_datetime = QDateTime(QDate(1970,1,1),QTime(0,0,0),Qt::UTC);
    qDebug()<<"current time secs to (1970-01-01:00-00-00):"<<ref_datetime.secsTo(cur_datetime);
    qDebug()<<"current time to time_t                    :"<<cur_datetime.toTime_t();
    qDebug()<<"time(NULL)                                :"<<time(NULL);
    QDateTime temp;
    temp.setTime_t(time(NULL));
    qDebug()<<"DateTime From time(NULL)                :"<<temp;
    qDebug()<<"DateTime From time(NULL) toLocalTime()  :"<<temp.toLocalTime();
    qDebug()<<"DateTime From time(NULL) to UTC()       :"<<temp.toUTC();
    qDebug()<<"DateTime From current time              :"<<cur_datetime;
    qDebug()<<"DateTime From current time toLocalTime():"<<cur_datetime.toLocalTime();
    qDebug()<<"DateTime From current time to UTC()     :"<<cur_datetime.toUTC();
    temp.setTime_t(cur_datetime.toTime_t());
    qDebug()<<"DateTime From current time to time_t()  :"<<temp;
#else
    QDateTime datetime;
    if(ui->checkBox_Change->isChecked() == false)
    {
        if(ui->checkBox_LocalTime->isChecked())
        {
            datetime.setTime_t(ui->lineEdit_Input_2->text().toInt());
            ui->lineEdit_Output_2->setText(datetime.toUTC().toString("yyyy-MM-dd : hh-mm-ss"));
        }
        else
        {
            datetime.setTime_t(ui->lineEdit_Input_2->text().toInt());
            ui->lineEdit_Output_2->setText(datetime.toString("yyyy-MM-dd : hh-mm-ss"));
            //ui->lineEdit_Output_2->setText(datetime.toString());
        }

    }
    else
    {
        if(ui->checkBox_LocalTime->isChecked())
        {
            ui->lineEdit_Output_2->setText(QString::number(ui->dateTimeEdit->dateTime().toTime_t()));
        }
        else
        {
            ui->lineEdit_Output_2->setText(QString::number(ui->dateTimeEdit->dateTime().toTime_t()));
        }

    }
#endif

}

void Widget::CheckBox_Change_Slot()
{

    if(ui->checkBox_Change->isChecked())
    {
        ui->label_5->setText(QApplication::translate("Widget", "\345\276\227\345\210\260\347\247\222\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        //ui->label_5->setText(QApplication::translate("Widget", "输入秒数", 0, QApplication::UnicodeUTF8));
        ui->label_4->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        ui->lineEdit_Input_2->setVisible(false);
        ui->dateTimeEdit->setVisible(true);
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    }
    else
    {
        ui->label_4->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\347\247\222\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        ui->label_5->setText(QApplication::translate("Widget", "\345\276\227\345\210\260\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        ui->lineEdit_Input_2->setVisible(true);
        ui->dateTimeEdit->setVisible(false);
        ui->lineEdit_Input_2->setText(QString::number(QDateTime::currentDateTime().toTime_t()));
    }
    ui->lineEdit_Output_2->clear();
}

void Widget::CheckBox_isLocalTime_Slot()
{

    if(ui->checkBox_LocalTime->isChecked())
    {
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().toUTC());
    }
    else
    {
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    }
    this->PushButtonCalc_2_Slot();
}
