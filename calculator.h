#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QQueue>
#include <QStack>
#include <QString>
#include <QVector>

class Calculator
{
public:

    enum class Error{
        /// @brief 正常
        OK = 0,
        /// @brief 语法错误
        SYNTAX_ERROR = 1,
        /// @brief 除零错误
        DIVIDE_ZERO = 2,
        /// @brief 未知元素
        UNKNOWN_ELEMENT = 3,
    };

    Calculator();
    virtual void input(QString ch);
    virtual void clear();
    virtual void back();
    virtual double calculate();
    const QString& getExpression() const { return m_expression; }
    void setExpression(const QString& v) { m_expression = v; }
    const QString& getLastExpression() const { return m_last_expression; }
    void setLastExpression(const QString& v) { m_last_expression = v; }
protected:
    double polishCal(QVector<QString> polishEquation);
    QVector<QString> expressionToPolish(QString expression);
    double cal(QString op, double a, double b);

private:
    QString m_expression;
    QString m_last_expression;
    Error m_error;
    bool m_second_function;

};


#endif // CALCULATOR_H
