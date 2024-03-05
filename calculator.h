#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QQueue>
#include <QStack>
#include <QString>
#include <QVector>
#include <QMap>

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


    /// @brief 构造函数
    Calculator();

    /// @brief 输入
    /// @param ch 输入的单个字符
    virtual void input(QString ch);

    /// @brief 清空操作数
    virtual void clear();

    /// @brief 回退一个字符
    virtual void back();

    /// @brief 计算当前表达式的值
    /// @return 计算结果
    virtual double calculate();

    /// @brief 得到当前表达式 
    const QString& getExpression() const { return m_expression; }

    /// @brief 设置当前表达式
    void setExpression(const QString& v) { m_expression = v; }

    /// @brief 获取上一次操作的表达式
    const QString& getLastExpression() const { return m_last_expression; }

    /// @brief 设置上一次操作的表达式
    void setLastExpression(const QString& v) { m_last_expression = v; }

    /// @brief 获取当前第二功能是否开启状态的信息 
    bool getSecondFunctionState() const { return m_second_function; }

    /// @brief 开启第二功能
    void switch_second_function();
protected:

    /// @brief 计算逆波兰表达式的结果
    /// @param polishEquation 逆波兰表达式
    /// @return 运算结果
    double polishCal(QVector<QString> polishEquation);

    /// @brief 将中缀表达式转为逆波兰表达式
    /// @param expression 中缀表达式
    /// @return 逆波兰表达式
    QVector<QString> expressionToPolish(QString expression);

    /// @brief 一次四则计算
    /// @param op 运算符号
    /// @param a 操作数一
    /// @param b 操作数二
    /// @return 计算结果
    double cal(QString op, double a, double b);

private:
    // 当前操作的表达式
    QString m_expression;
    // 上一次操作的表达式
    QString m_last_expression;
    // 计算器当前错误码
    Error m_error;
    // 是否开启第二功能
    bool m_second_function;
    // 运算符与优先级映射
    QMap<QString, int> m_operatorPriority;

};


#endif // CALCULATOR_H
