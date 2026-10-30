#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void digitClicked();       // 数字 0-9
    void pointClicked();       // 小数点
    void backspaceClicked();   // 退格
    void clearClicked();       // 清除
    void operatorClicked();    // 加减乘除
    void equalClicked();       // 等于

private:
    Ui::Calculator *ui;

    // --- 核心状态管理 ---
    bool waitingForOperand;    // 是否等待输入新操作数
    bool hasPoint;             // 当前输入是否已包含小数点
    double firstOperand;       // 第一个操作数
    QString pendingOperator;   // 待执行的操作符

    // 统一计算函数，返回 false 表示除数为 0
    bool calculate(double a, double b, const QString &op, double &result);
};

#endif // CALCULATOR_H