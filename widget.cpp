#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::refresh()
{
    ui->now_edit_expression->setText(calculator.getExpression());
}


//数字键
void Widget::on_zero_button_clicked()
{
    calculator.input("0");
    refresh();
}

void Widget::on_one_button_clicked()
{
    calculator.input("1");
    refresh();
}

void Widget::on_two_button_clicked()
{
    calculator.input("2");
    refresh();
}

void Widget::on_three_button_clicked()
{
    calculator.input("3");
    refresh();
}

void Widget::on_four_button_clicked()
{
    calculator.input("4");
    refresh();
}

void Widget::on_five_button_clicked()
{
    calculator.input("5");
    refresh();
}

void Widget::on_six_button_clicked()
{
    calculator.input("6");
    refresh();
}

void Widget::on_seven_button_clicked()
{
    calculator.input("7");
    refresh();
}

void Widget::on_eight_button_clicked()
{
    calculator.input("8");
    refresh();
}

void Widget::on_nine_button_clicked()
{
    calculator.input("9");
    refresh();
}

void Widget::on_clear_button_clicked()
{
    calculator.clear();
    refresh();
}

void Widget::on_del_button_clicked()
{
    calculator.back();
    refresh();
}

void Widget::on_left_parenthesis_button_clicked()
{
    calculator.input("(");
    refresh();
}

void Widget::on_right_parenthesis_button_clicked()
{
    calculator.input(")");
    refresh();
}

void Widget::on_add_button_clicked()
{
    calculator.input("+");
    refresh();
}

void Widget::on_minus_button_clicked()
{
    calculator.input("-");
    refresh();
}

void Widget::on_multiply_button_clicked()
{
    calculator.input("*");
    refresh();
}

void Widget::on_divided_button_clicked()
{
    calculator.input("/");
    refresh();
}

void Widget::on_equal_button_clicked()
{
    calculator.calculate();
    refresh();
}





