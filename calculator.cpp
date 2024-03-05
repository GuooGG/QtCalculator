#include "calculator.h"
Calculator::Calculator()
    :m_error(Error::OK)
    ,m_second_function(false)
{
    m_expression.clear();
    m_last_expression.clear();
}


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

double Calculator::calculate()
{
    m_last_expression = m_expression;
    QVector<QString> polishEquation = expressionToPolish(m_expression);
    double res = polishCal(polishEquation);
    m_expression = QString::number(res);
    return res;
}

void Calculator::switch_second_function()
{
    m_second_function = m_second_function ? false : true;
}

bool isNum(QString str)
{
    bool res = true;
    str.toDouble(&res);
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
        }else if(m_operatorPriority.find(item) != m_operatorPriority.end())
        {
                    if(stk.size() < 2 && item != "-"){
                        m_error = Error::SYNTAX_ERROR;
                    }
                    double num1 = stk.empty() ? 0 : stk.top();
                    if(!stk.empty()){ stk.pop(); }
                    double num2 = stk.empty() ? 0 : stk.top();
                    if(!stk.empty()){ stk.pop(); }
                    if(item == "/" && num2 == 0){
                        m_error = Error::DIVIDE_ZERO;
                    }
                    stk.push(cal(item, num2, num1));
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
    QVector<QString> postfixExpression;
    QStack<QString> operatorStack;
    m_operatorPriority["+"] = 1;
    m_operatorPriority["-"] = 1;
    m_operatorPriority["*"] = 2;
    m_operatorPriority["/"] = 2;
    m_operatorPriority["%"] = 2;
    m_operatorPriority["^"] = 3;
    m_operatorPriority["r"] = 3;
    m_operatorPriority["b"] = 3;
    m_operatorPriority["e"] = 3;

    QString num = "";
    for(QChar& ch: expression)
    {
        if(ch.isDigit() || ch == '.')
        {
            num += ch;
        }
        else
        {
            if(!num.isEmpty())
            {
                postfixExpression.push_back(num);
                num.clear();
            }
            if(ch == '(')
            {
                operatorStack.push(ch);
            }
            else if(ch == ')')
            {
                while(!operatorStack.empty() && operatorStack.top() != "(")
                {
                    postfixExpression.push_back(operatorStack.pop());
                }
                if(!operatorStack.empty())
                {
                    operatorStack.pop();
                }
            }
            else
            {
                QString op(1, ch);
                while(!operatorStack.empty() && m_operatorPriority[op] <= m_operatorPriority[operatorStack.top()])
                {
                    postfixExpression.push_back(operatorStack.pop());
                }
                operatorStack.push(op);
            }
        }
    }
    if(!num.isEmpty())
    {
        postfixExpression.push_back(num);
    }
    while(!operatorStack.empty())
    {
        postfixExpression.push_back(operatorStack.pop());
    }
    return postfixExpression;
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
    }else if(op == "%"){
        return fmod(a , b);
    }else if(op == "^"){
        return pow(a, b);
    }else if(op == "r"){
        return pow(a, 1.0/b);
    }else if(op == "b"){
        return log(a) / log(b);
    }else if(op == "e"){
        return pow(10 , b) * a;
    }
    return 0;
}

