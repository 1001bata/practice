#ifndef SEND_H
#define SEND_H

#include <QDialog>
#include "QLineEdit"

class QTcpServer;//
class QTcpSocket;

namespace Ui {
class Send;
}

class Send : public QDialog
{
    Q_OBJECT

public:
    explicit Send(QWidget *parent = 0);
    ~Send();


private slots:
    void on_sendpushButton_clicked();
    void sendMessage();

    void on_exitpushButton_clicked();

    void on_pushButton_clicked();

    //事件过滤器，按下回车发送信息
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::Send *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

};




#endif // SEND_H
