#include "send.h"
#include "ui_send.h"
#include <QtNetwork>
#include <QTcpSocket> //通信套接字
#include <QTcpServer> //监听套接字
#include <QKeyEvent> //快捷键
#include "widget.h"


Send::Send(QWidget *parent) ://用于监听接收
    QDialog(parent),
    ui(new Ui::Send)
{
    ui->setupUi(this);


    tcpServer = new QTcpServer(this); //分配空间,指定父对象 监听套接字
    tcpServer->listen(QHostAddress::LocalHost,6666);//监听本机所有网口及6666端口号


    connect(tcpServer,&QTcpServer::newConnection,[=] //Server监听到连接请求触发newConnection信号
        {
            tcpSocket = tcpServer->nextPendingConnection();//Client与Server建立连接后，Server返回一个建立好连接用于通信的套接字
            QString ip = tcpSocket->peerAddress().toString();//获取对方的IP
//            qint16 port = tcpSocket->peerPort();//获取对方的端口
            QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间
            ui->messageBrowser->append(time+"\n"+QString("成功与[%1]建立连接...").arg(ip));

            connect(tcpSocket,&QTcpSocket::readyRead,[=] //接收数据
            {
                QString message = tcpSocket->readAll();
               QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");


               // 设置正常文本的格式（黑色）
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


//               ui->messageBrowser->append(time + "\n"+message);
            });
        });

    //设置消息过滤器
    ui->messageTextEdit->installEventFilter(this);


}

Send::~Send()
{
    delete ui;
}



void Send::sendMessage()
{
    //获取用户输入的信息
    QString ip = tcpSocket->peerAddress().toString();//获取对方的IP
    qint16 strport = tcpSocket->peerPort();//获取对方的端口
    QString port = QString::number(strport); // 将端口号转换为QString


    QString time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间
   // QString content = ui->messageTextEdit->toPlainText();

    //消息内容
    QString content = ui->messageTextEdit->toPlainText();
    //用户名
    QString text = "["+loginName + "]:"+content;

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


    cursor.insertText(text); // 插入文本
    //确保视图滚动到最底部位置
    ui->messageBrowser->ensureCursorVisible();


    tcpSocket->write(text.toUtf8().data());

}


//快捷键ctrl+enter发送消息
bool Send::eventFilter(QObject *obj, QEvent *event)
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

void Send::on_sendpushButton_clicked()
{

    sendMessage();
    ui->messageTextEdit->clear();

}


void Send::on_exitpushButton_clicked()//断开连接并退出
{
    tcpSocket->disconnectFromHost();//主动和客户端断开连接
    tcpSocket->close();
    tcpSocket = NULL;

    close();
}

void Send::on_pushButton_clicked()//清空消息
{
    ui->messageBrowser->clear();

}
