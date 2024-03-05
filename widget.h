#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QVector>
#include "calculator.h"
#include "qpushbutton.h"
#include <QPair>
#include <QMap>

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
private:
    void second_function_ui();
    void first_function_ui();
    void addSecondFunctionButton(QPushButton* button, const QString& first, const QString& second);
    void initSecondFunctionButton();
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
    // 小数点
    void on_dot_button_clicked();
    //添加特殊数值
    void on_pai_button_clicked();
    void on_e_button_clicked();
    //开启第二功能
    void on_second_function_button_clicked();
    //运算结果
    void on_equal_button_clicked();
    void on_abs_button_clicked();
    void on_sign_button_clicked();
    void on_inverse_button_clicked();
    void on_squre_button_clicked();
    void on_sqrt_button_clicked();
    void on_tenfold_button_clicked();
    void on_log_button_clicked();
    void on_ln_button_clicked();
    void on_mod_button_clicked();
    void on_power_button_clicked();
    void on_exp_button_clicked();
    void on_factorial_button_clicked();
private:
    Ui::Widget *ui;
    QVector<QPair<QPushButton*, QPair<QString,QString>>> m_second_function_buttons;
};




#endif // WIDGET_H
