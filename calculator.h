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

protected:
    QString EquationTOString(QStack<char> equation);

private:
    QStack<char> m_equation;
    QQueue<QString> m_logs;
    uint32_t m_max_log_count;
};

#endif // CALCULATOR_H
