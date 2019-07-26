#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int n){
    money += n;
    ui->lcdNumber->display(money);
    button();
}

void Widget::on_pb10_clicked()
{
    change_money(10);
}

void Widget::on_pb50_clicked()
{
   change_money(50);
}

void Widget::on_pb100_clicked()
{
    change_money(100);

}

void Widget::on_pb500_clicked()
{
    change_money(500);
}

void Widget::on_pbCoffee_clicked()
{
    change_money(-100);
}

void Widget::on_pbTea_clicked()
{
    change_money(-150);
}

void Widget::on_pbCoke_clicked()
{
    change_money(-200);
}


void Widget::on_pbReset_clicked()
{
    int num10 = 0, num50 = 0, num100 = 0, num500 = 0;
    if(money >= 500) num500 = money / 500;
    money %= 500;
    if(money >= 100) num100 = money / 100;
    money %= 100;
    if(money >= 50) num50 = money / 50;
    money %= 50;
    if(money >= 10) num10 = money / 10;
    money %= 10;
     ui->lcdNumber->display(money);
    QMessageBox msg;
    QString str = QString("500: %1, 100: %2, 50: %3, 10: %4").arg(num500).arg(num100).arg(num50).arg(num10);
    msg.information(nullptr,"change", str);
}

void Widget::button(){
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbCoke->setEnabled(money >= 200);
}

