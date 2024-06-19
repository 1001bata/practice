/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QLabel *label;
    QLineEdit *nameLineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(642, 502);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 180, 61, 61));
        pwdLineEdit = new QLineEdit(Widget);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(230, 180, 211, 51));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(130, 370, 131, 61));
        exitButton = new QPushButton(Widget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(390, 370, 131, 61));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 70, 71, 61));
        nameLineEdit = new QLineEdit(Widget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(230, 80, 211, 51));
        QWidget::setTabOrder(nameLineEdit, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, loginButton);
        QWidget::setTabOrder(loginButton, exitButton);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
