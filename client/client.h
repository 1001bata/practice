#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>

class QTcpServer;//
class QTcpSocket;

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_sendpushButton_clicked();
    void sendMessage();

    void on_exitpushButton_clicked();

    void on_exitpushButton_2_clicked();

    void on_pushButton_clicked();

    //事件过滤器，按下回车发送信息
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::Client *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};

#endif // CLIENT_H
