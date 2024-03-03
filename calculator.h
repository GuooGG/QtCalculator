#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QQueue>
#include <QStack>
#include <QString>
#include <QStringBuilder>

class Calculator
{
public:
    Calculator();
    virtual void Calculate(QStack<char> equation);
    virtual void input(QString ch);
    virtual void clear();
    virtual void back();

    const QString& getExpression() const { return m_expression; }

protected:
    double polishCal(QStack<char> polishEquation);
    QStack<char> expressionToPolish(QString expression);

private:
    QString m_expression;
};


#endif // CALCULATOR_H
