#include "calculator.h"

Calculator::Calculator() {}

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

void Calculator::calculate()
{
    QVector<QString> polishEquation = expressionToPolish(m_expression);
    double res = polishCal(polishEquation);
    m_expression = QString::number(res);
}

bool isNum(QString str)
{
    bool res = true;
    if(str == ""){
        return false;
    }
    for(int i = 0; i < str.size(); i++){
        QChar ch = str[i];
        if(ch >= '0' && ch <= '9'){
            continue;
        }else if(ch == '-' && i < str.size() - 1){
            continue;
        }else{
            res = false;
        }
    }
    return res;
}

double Calculator::polishCal(QVector<QString> polishEquation)
{
    QStack<double> stk;
    for(QString& item: polishEquation)
    {
        if(isNum(item))
        {
            stk.push(item.toDouble());
        }else if(item == "+"
                || item == "-"
                || item == "*"
                || item == "/")
                {
                    if(stk.size() < 2){
                        m_error = Error::SYNTAX_ERROR;
                    }
                    double num1 = stk.top();stk.pop();
                    double num2 = stk.top();stk.pop();
                    if(item == "/" && num2 == 0){
                        m_error = Error::DIVIDE_ZERO;
                    }
                    stk.push(cal(item, num1, num2));
        }else{
            m_error = Error::UNKNOWN_ELEMENT;
        }
    }
    if(stk.size() != 1){
        m_error = Error::SYNTAX_ERROR;
    }
    return stk.top();
}

QVector<QString> Calculator::expressionToPolish(QString expression)
{
    QVector<QString> polish;
    QStack<QString> stk;
    QString num = "";
    for(QChar& ch: expression)
    {
        if(ch.isDigit() || ch == '.')
        {
            num += ch;
        }else{
            if(!num.isEmpty())
            {
                polish.push_back(num);
                num.clear();
            }
            if(ch == '+' || ch == '-')
            {
                while(!stk.empty() && (stk.top() == "+" || stk.top() == "-" || stk.top() == "*" || stk.top() == "/"))
                {
                    polish.push_back(stk.top());
                    stk.pop();
                }
                stk.push(ch);
            }else if(ch == '*' || ch == '/')
            {
                while(!stk.empty() && (stk.top() == "*" || stk.top() == "/"))
                {
                    polish.push_back(stk.top());
                    stk.pop();
                }
                stk.push(ch);
            }else if(ch == '(')
            {
                stk.push(ch);
            }else if(ch == ')')
            {
                while(!stk.empty() && stk.top() != "(")
                {
                    polish.push_back(stk.top());
                    stk.pop();
                }
                if(!stk.empty())
                {
                    stk.pop();
                }
            }
        }
    }
    if(!num.isEmpty())
    {
        polish.push_back(num);
    }
    while(!stk.empty())
    {
        polish.push_back(stk.top());
        stk.pop();
    }
    return polish;
}

double Calculator::cal(QString op, double a, double b)
{
    if(op == "+"){
        return a + b;
    }else if(op == "-"){
        return a - b;
    }else if(op == "*"){
        return a * b;
    }else if(op == "/"){
        return a / b;
    }
    return 0;
}

