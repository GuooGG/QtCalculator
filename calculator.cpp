#include "calculator.h"

Calculator::Calculator() {}

void Calculator::Calculate(QStack<char> equation) {}

void Calculator::input(QString ch)
{
    m_expression.append(ch);
}

void Calculator::clear()
{
    m_expression.clear();
}

void Calculator::back()
{
    m_expression.chop(1);
}

QString Calculator::EquationTOString(QStack<char> equation)
{
    QString str;
    while (!equation.empty()) {
        char ch = equation.top();
        equation.pop();
        if (ch >= '0' && ch <= '9') {
            continue;
        } else if (ch == '+' || ch == '-') {
        }
    }
    return str;
}
