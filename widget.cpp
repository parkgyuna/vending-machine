#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    SettingButton();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::SettingButton(){

    ui->pbCoffee->setEnabled(money>=100);
    ui->pbMilk->setEnabled(money>=200);
    ui->pbTea->setEnabled(money>=150);



}
void Widget::IncreaseMoney(int value)
{
    money +=value;
    ui->lcdNumber->display(money);
    SettingButton();

}

void Widget::on_pb10_clicked()
{
    IncreaseMoney(10);
}

void Widget::on_pb50_clicked()
{
    IncreaseMoney(50);
}


void Widget::on_pb100_clicked()
{
    IncreaseMoney(100);
}


void Widget::on_pb500_clicked()
{
    IncreaseMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    IncreaseMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    IncreaseMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    IncreaseMoney(-150);
}


void Widget::on_pbReset_clicked()
{
    int tmpMon = money;
    int cnt500 = tmpMon / 500;
    tmpMon %= 500;
    int cnt100 = tmpMon / 100;
    tmpMon %= 100;
    int cnt50  = tmpMon / 50;
    tmpMon %= 50;
    int cnt10  = tmpMon / 10;

    QString changeMsg = QString(
                                "500: %1\n"
                                "100: %2\n"
                                "50: %3\n"
                                "10: %4")
                            .arg(cnt500).arg(cnt100).arg(cnt50).arg(cnt10);

    QMessageBox::information(this, "Reset~", changeMsg);

    money = 0;
    ui->lcdNumber->display(money);
    SettingButton();
}

