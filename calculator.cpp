#include "calculator.h"

Calculator::Calculator() {}

void Calculator::Calculate(QStack<char> equation){

}

QString Calculator::EquationTOString(QStack<char> equation)
{
    QString str;
    while(!equation.empty()){
        char ch = equation.top();
        equation.pop();
        if(ch >= '0' && ch <='9'){
            continue;
        }
        else if(ch == '+' || ch == '-'){

        }

    }
    return str;
}
