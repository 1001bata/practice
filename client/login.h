#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "client.h"

extern QString loginName;


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_loginButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::login *ui;
    Client *client;
};

#endif // LOGIN_H
