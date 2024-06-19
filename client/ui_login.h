/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_login
{
public:
    QLabel *label_2;
    QLineEdit *nameLineEdit;
    QPushButton *exitButton;
    QPushButton *loginButton;
    QLineEdit *pwdLineEdit;
    QLabel *label;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(492, 482);
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 61, 61));
        nameLineEdit = new QLineEdit(login);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(140, 40, 211, 51));
        exitButton = new QPushButton(login);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(300, 330, 131, 61));
        loginButton = new QPushButton(login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(40, 330, 131, 61));
        pwdLineEdit = new QLineEdit(login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(140, 140, 211, 51));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 71, 61));
        QWidget::setTabOrder(nameLineEdit, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, loginButton);
        QWidget::setTabOrder(loginButton, exitButton);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        exitButton->setText(QApplication::translate("login", "\351\200\200\345\207\272", Q_NULLPTR));
        loginButton->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
