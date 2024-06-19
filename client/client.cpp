#include "client.h"
#include "ui_client.h"
#include "login.h"
#include<QTcpSocket> //通信套接字
#include<QTcpServer> //监听套接字
#include <QKeyEvent> //快捷键
#include <QtNetwork>
#include <QMessageBox>

//客户端

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);// 实例化 QTcpSocket 并将其设置为当前对象的子对象


    QString peerip = "127.0.0.1"; // 目标主机的 IP 地址
    quint16 peerport = 6666; // 目标主机的端口号


//    tcpSocket->connectToHost(QHostAddress(peerip),peerport);//尝试与主机连接
    connect(tcpSocket,&QTcpSocket::connected,[=] //客户端成功建立连接后触发connected信号
    {
        QString str = QString("成功与[%1:%2]建立连接...").arg(peerip).arg(peerport);
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->messageBrowser->append(time+"\n"+str);
    });

    connect(tcpSocket,&QTcpSocket::readyRead,[=] //客户端接收数据
        {
           QString message = tcpSocket->readAll();
           QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//           QString name = tcpSocket->peerName();
//           ui->messageBrowser->append(time + "\n"+name+":"+message);


           //    // 设置正常文本的格式（黑色）
           QTextCharFormat normalFormat;
           normalFormat.setForeground(Qt::black); // 设置字体颜色为黑色
           normalFormat.setFontPointSize(10); // 设置字体大小（默认或你想要的大小）


           // 创建一个 QTextCursor 对象，并将其定位到文本末尾
           QTextCursor cursor(ui->messageBrowser->textCursor());
           cursor.movePosition(QTextCursor::End);
           // 重置为正常格式以插入普通文本
           cursor.mergeCharFormat(normalFormat);

           // 插入消息文本（使用正常格式）
           cursor.insertText("\n"+time + "\n"+message);

           //确保视图在最底端
           ui->messageBrowser->ensureCursorVisible();

//           ui->messageBrowser->append(time + "\n"+message+"\n");
        });

    //设置消息过滤器
    ui->messageTextEdit->installEventFilter(this);

}

Client::~Client()
{
    delete ui;
}

void Client::sendMessage()
{
    //QMessageBox::information(this, "标题", "这是一条信息消息");

    //获取用户输入的信息
    QString ip = tcpSocket->peerAddress().toString();//获取对方的IP
    qint16 strport = tcpSocket->peerPort();//获取对方的端口
    QString port = QString::number(strport); // 将端口号转换为QString
    QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间

    //消息内容
    QString content = ui->messageTextEdit->toPlainText();
    //用户名
    QString text = "["+loginName + "]:"+content;

    //设置发送字体样式
    //设置自己的发送内容显示为12号蓝色字体
    QTextCursor cursor(ui->messageBrowser->textCursor());
    cursor.movePosition(QTextCursor::End); // 移动到文本末尾


    // 设置正常文本的格式（黑色）
    QTextCharFormat normalFormat;
    normalFormat.setForeground(Qt::black); // 设置字体颜色为黑色
    normalFormat.setFontPointSize(10); // 设置字体大小（默认或你想要的大小）

    // 设置特殊文本的格式（蓝色并增大字体）
    QTextCharFormat specialFormat;
    specialFormat.setForeground(Qt::blue); // 设置字体颜色为蓝色
    specialFormat.setFontPointSize(12); // 设置字体大小为12点

    // 插入时间戳（使用特殊格式）
    cursor.mergeCharFormat(normalFormat);
    cursor.insertText("\n"+time + "\n");

    // 重置为正常格式以插入其他文本
    cursor.mergeCharFormat(specialFormat);

    cursor.insertText(text);

//    cursor.insertText(QString("[%1]:").arg(loginName) + text+"\n"); // 插入文本
    //确保视图滚动到最底部位置
    ui->messageBrowser->ensureCursorVisible();


    tcpSocket->write(text.toUtf8().data());

}

//快捷键ctrl+enter发送消息
bool Client::eventFilter(QObject *obj, QEvent *event)
{

    if(obj == ui->messageTextEdit){

        if(event->type() == QEvent::KeyPress){
            QKeyEvent *k = static_cast<QKeyEvent *>(event);
            //按下ctrl+enter发消息
            if(k->key() == Qt::Key_Return &&(k->modifiers() & Qt::ControlModifier))
            {
                on_sendpushButton_clicked();//相当于发生了点击送的事件
                return true;
            }
        }
    }
    return false;
}


void Client::on_sendpushButton_clicked()//发送按钮
{
    sendMessage();
    ui->messageTextEdit->clear();//清空输入栏
}


void Client::on_exitpushButton_clicked()//断开连接并退出
{
    connect(tcpSocket,&QTcpSocket::disconnected,[=]
       {
           QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
           ui->messageBrowser->append(time + "\n"+"与服务器断开连接...");
       });

    close();
}

void Client::on_exitpushButton_2_clicked()//点击连接
{
    QString peerip = "127.0.0.1"; // 目标主机的 IP 地址
    quint16 peerport = 6666; // 目标主机的端口号

    tcpSocket->connectToHost(QHostAddress(peerip),peerport);//尝试与主机连接
}

void Client::on_pushButton_clicked()//清空消息栏
{
    ui->messageBrowser->clear();
}
