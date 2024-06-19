#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <send.h>

extern QString loginName;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_exitButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::Widget *ui;
    Send *send;//跳转到发送页面

};

#endif // WIDGET_H
