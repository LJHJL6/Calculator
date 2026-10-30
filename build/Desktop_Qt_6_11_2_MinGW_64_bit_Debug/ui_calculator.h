/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QLineEdit *displayLineEdit;
    QWidget *buttonsWidget;
    QGridLayout *gridLayout;
    QPushButton *digit2Button;
    QPushButton *pushButton_4;
    QPushButton *digit8Button;
    QPushButton *minusButton;
    QPushButton *digit4Button;
    QPushButton *digit3Button;
    QPushButton *digit7Button;
    QPushButton *digit5Button;
    QPushButton *multiplyButton;
    QPushButton *pointButton;
    QPushButton *digit6Button;
    QPushButton *digit9Button;
    QPushButton *equalButton;
    QPushButton *digit1Button;
    QPushButton *plusButton;
    QPushButton *backspaceButton;
    QPushButton *divideButton;
    QPushButton *clearButton;

    void setupUi(QWidget *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(800, 600);
        displayLineEdit = new QLineEdit(Calculator);
        displayLineEdit->setObjectName("displayLineEdit");
        displayLineEdit->setGeometry(QRect(100, 40, 341, 151));
        displayLineEdit->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setPointSize(24);
        displayLineEdit->setFont(font);
        displayLineEdit->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0; color: #333333; border: 1px solid #ccc; border-radius: 5px;"));
        displayLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        displayLineEdit->setReadOnly(true);
        buttonsWidget = new QWidget(Calculator);
        buttonsWidget->setObjectName("buttonsWidget");
        buttonsWidget->setGeometry(QRect(100, 190, 341, 361));
        gridLayout = new QGridLayout(buttonsWidget);
        gridLayout->setObjectName("gridLayout");
        digit2Button = new QPushButton(buttonsWidget);
        digit2Button->setObjectName("digit2Button");

        gridLayout->addWidget(digit2Button, 7, 1, 1, 1);

        pushButton_4 = new QPushButton(buttonsWidget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 8, 1, 1, 1);

        digit8Button = new QPushButton(buttonsWidget);
        digit8Button->setObjectName("digit8Button");

        gridLayout->addWidget(digit8Button, 4, 1, 1, 1);

        minusButton = new QPushButton(buttonsWidget);
        minusButton->setObjectName("minusButton");

        gridLayout->addWidget(minusButton, 5, 3, 1, 1);

        digit4Button = new QPushButton(buttonsWidget);
        digit4Button->setObjectName("digit4Button");

        gridLayout->addWidget(digit4Button, 5, 0, 1, 1);

        digit3Button = new QPushButton(buttonsWidget);
        digit3Button->setObjectName("digit3Button");

        gridLayout->addWidget(digit3Button, 7, 2, 1, 1);

        digit7Button = new QPushButton(buttonsWidget);
        digit7Button->setObjectName("digit7Button");

        gridLayout->addWidget(digit7Button, 4, 0, 1, 1);

        digit5Button = new QPushButton(buttonsWidget);
        digit5Button->setObjectName("digit5Button");

        gridLayout->addWidget(digit5Button, 5, 1, 1, 1);

        multiplyButton = new QPushButton(buttonsWidget);
        multiplyButton->setObjectName("multiplyButton");

        gridLayout->addWidget(multiplyButton, 4, 3, 1, 1);

        pointButton = new QPushButton(buttonsWidget);
        pointButton->setObjectName("pointButton");

        gridLayout->addWidget(pointButton, 8, 2, 1, 1);

        digit6Button = new QPushButton(buttonsWidget);
        digit6Button->setObjectName("digit6Button");

        gridLayout->addWidget(digit6Button, 5, 2, 1, 1);

        digit9Button = new QPushButton(buttonsWidget);
        digit9Button->setObjectName("digit9Button");

        gridLayout->addWidget(digit9Button, 4, 2, 1, 1);

        equalButton = new QPushButton(buttonsWidget);
        equalButton->setObjectName("equalButton");

        gridLayout->addWidget(equalButton, 8, 3, 1, 1);

        digit1Button = new QPushButton(buttonsWidget);
        digit1Button->setObjectName("digit1Button");

        gridLayout->addWidget(digit1Button, 7, 0, 1, 1);

        plusButton = new QPushButton(buttonsWidget);
        plusButton->setObjectName("plusButton");

        gridLayout->addWidget(plusButton, 7, 3, 1, 1);

        backspaceButton = new QPushButton(buttonsWidget);
        backspaceButton->setObjectName("backspaceButton");

        gridLayout->addWidget(backspaceButton, 2, 3, 1, 1);

        divideButton = new QPushButton(buttonsWidget);
        divideButton->setObjectName("divideButton");

        gridLayout->addWidget(divideButton, 2, 2, 1, 1);

        clearButton = new QPushButton(buttonsWidget);
        clearButton->setObjectName("clearButton");

        gridLayout->addWidget(clearButton, 2, 1, 1, 1);


        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QWidget *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        digit2Button->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        digit8Button->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        minusButton->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        digit4Button->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        digit3Button->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        digit7Button->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        digit5Button->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        multiplyButton->setText(QCoreApplication::translate("Calculator", "\303\227", nullptr));
        pointButton->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        digit6Button->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        digit9Button->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        equalButton->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        digit1Button->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        plusButton->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        backspaceButton->setText(QCoreApplication::translate("Calculator", "\342\214\253", nullptr));
        divideButton->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
        clearButton->setText(QCoreApplication::translate("Calculator", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
