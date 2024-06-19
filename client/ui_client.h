/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

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

class Ui_Client
{
public:
    QPushButton *exitpushButton;
    QPushButton *sendpushButton;
    QTextEdit *messageTextEdit;
    QTextBrowser *messageBrowser;
    QLabel *label;
    QPushButton *exitpushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(712, 632);
        exitpushButton = new QPushButton(Client);
        exitpushButton->setObjectName(QStringLiteral("exitpushButton"));
        exitpushButton->setGeometry(QRect(380, 520, 101, 51));
        sendpushButton = new QPushButton(Client);
        sendpushButton->setObjectName(QStringLiteral("sendpushButton"));
        sendpushButton->setGeometry(QRect(540, 520, 101, 51));
        messageTextEdit = new QTextEdit(Client);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(60, 350, 601, 131));
        messageBrowser = new QTextBrowser(Client);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(60, 40, 601, 251));
        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 530, 72, 15));
        exitpushButton_2 = new QPushButton(Client);
        exitpushButton_2->setObjectName(QStringLiteral("exitpushButton_2"));
        exitpushButton_2->setGeometry(QRect(220, 520, 101, 51));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(570, 310, 93, 28));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Dialog", Q_NULLPTR));
        exitpushButton->setText(QApplication::translate("Client", "\351\200\200\345\207\272", Q_NULLPTR));
        sendpushButton->setText(QApplication::translate("Client", "\345\217\221\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "\345\256\242\346\210\267\347\253\257", Q_NULLPTR));
        exitpushButton_2->setText(QApplication::translate("Client", "\350\277\236\346\216\245", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Client", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
