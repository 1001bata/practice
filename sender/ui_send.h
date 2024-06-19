/********************************************************************************
** Form generated from reading UI file 'send.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEND_H
#define UI_SEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Send
{
public:
    QPushButton *sendpushButton;
    QTextEdit *messageTextEdit;
    QTextBrowser *messageBrowser;
    QPushButton *exitpushButton;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Send)
    {
        if (Send->objectName().isEmpty())
            Send->setObjectName(QStringLiteral("Send"));
        Send->resize(676, 583);
        sendpushButton = new QPushButton(Send);
        sendpushButton->setObjectName(QStringLiteral("sendpushButton"));
        sendpushButton->setGeometry(QRect(510, 490, 101, 51));
        messageTextEdit = new QTextEdit(Send);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(30, 310, 601, 131));
        messageBrowser = new QTextBrowser(Send);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(30, 10, 601, 251));
        exitpushButton = new QPushButton(Send);
        exitpushButton->setObjectName(QStringLiteral("exitpushButton"));
        exitpushButton->setGeometry(QRect(350, 490, 101, 51));
        label = new QLabel(Send);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 510, 72, 15));
        pushButton = new QPushButton(Send);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 270, 93, 28));

        retranslateUi(Send);

        QMetaObject::connectSlotsByName(Send);
    } // setupUi

    void retranslateUi(QDialog *Send)
    {
        Send->setWindowTitle(QApplication::translate("Send", "Dialog", Q_NULLPTR));
        sendpushButton->setText(QApplication::translate("Send", "\345\217\221\351\200\201", Q_NULLPTR));
        exitpushButton->setText(QApplication::translate("Send", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("Send", "\346\234\215\345\212\241\347\253\257", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Send", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Send: public Ui_Send {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEND_H
