#include "calculator.h"
#include "ui_calculator.h"
#include <QPushButton>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
    , waitingForOperand(true)
    , hasPoint(false)
    , firstOperand(0.0)
{
    ui->setupUi(this);
    ui->displayLineEdit->setText("0");

    // 连接数字键
    for (int i = 0; i <= 9; ++i) {
        QPushButton *btn = findChild<QPushButton*>(QString("digit%1Button").arg(i));
        if (btn) connect(btn, &QPushButton::clicked, this, &Calculator::digitClicked);
    }

    // 连接功能键
    connect(ui->pointButton, &QPushButton::clicked, this, &Calculator::pointClicked);
    connect(ui->backspaceButton, &QPushButton::clicked, this, &Calculator::backspaceClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &Calculator::clearClicked);

    // 连接操作符键
    connect(ui->plusButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->minusButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->equalButton, &QPushButton::clicked, this, &Calculator::equalClicked);
}

Calculator::~Calculator()
{
    delete ui;
}

// ==================== 按键输入处理 ====================

void Calculator::digitClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;
    QString digit = btn->text();

    if (waitingForOperand) {
        ui->displayLineEdit->setText(digit);
        waitingForOperand = false;
        hasPoint = false;
        return;
    }

    // 处理前导零
    if (ui->displayLineEdit->text() == "0" && digit != "0") {
        ui->displayLineEdit->setText(digit);
        return;
    }
    if (ui->displayLineEdit->text() == "0" && digit == "0") return;

    ui->displayLineEdit->setText(ui->displayLineEdit->text() + digit);
}

void Calculator::pointClicked()
{
    if (waitingForOperand) {
        ui->displayLineEdit->setText("0.");
        waitingForOperand = false;
        hasPoint = true;
        return;
    }
    // 防止连续小数点
    if (hasPoint) return;

    ui->displayLineEdit->setText(ui->displayLineEdit->text() + ".");
    hasPoint = true;
}

void Calculator::backspaceClicked()
{
    if (waitingForOperand) return;

    QString text = ui->displayLineEdit->text();
    if (text.endsWith('.')) hasPoint = false;
    text.chop(1);

    if (text.isEmpty() || text == "-") {
        text = "0";
        waitingForOperand = true;
        hasPoint = false;
    }
    ui->displayLineEdit->setText(text);
}

void Calculator::clearClicked()
{
    ui->displayLineEdit->setText("0");
    waitingForOperand = true;
    hasPoint = false;
    firstOperand = 0.0;
    pendingOperator.clear();
}

// ==================== 运算处理 ====================

void Calculator::operatorClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;
    QString op = btn->text();

    double current = ui->displayLineEdit->text().toDouble();

    // 连续运算处理
    if (!pendingOperator.isEmpty() && !waitingForOperand) {
        double result;
        if (!calculate(firstOperand, current, pendingOperator, result)) {
            ui->displayLineEdit->setText("除零错误");
            pendingOperator.clear();
            waitingForOperand = true;
            return;
        }
        firstOperand = result;
        ui->displayLineEdit->setText(QString::number(result));
    } else {
        firstOperand = current;
    }

    pendingOperator = op; // 覆盖旧操作符，解决连续按操作符问题
    waitingForOperand = true;
    hasPoint = false;
}

void Calculator::equalClicked()
{
    if (pendingOperator.isEmpty()) return;

    double second = ui->displayLineEdit->text().toDouble();
    double result;

    if (!calculate(firstOperand, second, pendingOperator, result)) {
        ui->displayLineEdit->setText("除零错误");
    } else {
        ui->displayLineEdit->setText(QString::number(result));
    }

    pendingOperator.clear();
    waitingForOperand = true;
    hasPoint = false;
}

bool Calculator::calculate(double a, double b, const QString &op, double &result)
{
    if (op == "+") result = a + b;
    else if (op == "-") result = a - b;
    else if (op == "×" || op == "x" || op == "*") result = a * b;
    else if (op == "÷" || op == "/") {
        if (qAbs(b) < 0.0000001) return false;
        result = a / b;
    }
    return true;
}

// ==================== 键盘事件处理 ====================

void Calculator::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        QPushButton *btn = findChild<QPushButton*>(QString("digit%1Button").arg(key - Qt::Key_0));
        if (btn) btn->click();
        return;
    }

    switch (key) {
    case Qt::Key_Plus:      ui->plusButton->click(); return;
    case Qt::Key_Minus:     ui->minusButton->click(); return;
    case Qt::Key_Asterisk:  ui->multiplyButton->click(); return;
    case Qt::Key_Slash:     ui->divideButton->click(); return;
    case Qt::Key_Period:    ui->pointButton->click(); return;
    case Qt::Key_Backspace: ui->backspaceButton->click(); return;
    case Qt::Key_Escape:    ui->clearButton->click(); return;
    case Qt::Key_Return:
    case Qt::Key_Enter:     ui->equalButton->click(); return;
    case Qt::Key_Delete:    ui->clearButton->click(); return;
    default:
        break;
    }

    QWidget::keyPressEvent(event);
}