#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculator.h"

extern Calculator calculator;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void refresh();

private slots:
    //数字键
    void on_zero_button_clicked();
    void on_one_button_clicked();
    void on_two_button_clicked();
    void on_three_button_clicked();
    void on_four_button_clicked();
    void on_five_button_clicked();
    void on_six_button_clicked();
    void on_seven_button_clicked();
    void on_eight_button_clicked();
    void on_nine_button_clicked();
    //清除键
    void on_clear_button_clicked();
    void on_del_button_clicked();
    //括号键
    void on_left_parenthesis_button_clicked();
    void on_right_parenthesis_button_clicked();
    //四则运算符键
    void on_add_button_clicked();
    void on_minus_button_clicked();
    void on_multiply_button_clicked();
    void on_divided_button_clicked();

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
