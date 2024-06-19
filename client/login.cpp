#include "login.h"
#include "ui_login.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "QMessageBox"

QString loginName = "";//全局

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);  //密码 输入设置为小黑点

}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()//点击登录按钮
{
    //从数据库中取出用户名，验证密码

    QString username = ui->nameLineEdit->text();
    QString password = ui->pwdLineEdit->text();


    // 连接到数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../userlist.db");
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return;
    }

    // 构建查询语句
    QSqlQuery query(db);
    query.prepare("SELECT pwd FROM user WHERE name = :username");
    query.bindValue(":username", username);

    // 执行查询
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // 检查查询结果
    if (query.next()) {
        // 此处可以再添加密码加密解密存取功能
        QString storedPassword = query.value(0).toString();

        if (password == storedPassword) {

            //跳转到发送页面

            loginName = username;//聊天时显示的名称

            client = new Client(0);
            client->show();
            this->hide();

        } else {

            QMessageBox::information(this, "提示", "密码错误");
            //弹窗显示："密码错误!"



            qDebug() << "Incorrect password!";
        }
    } else {

        QMessageBox::information(this, "提示", "没有找到用户");
        //弹窗显示："没有找到用户！"


        qDebug() << "User not found!";
    }


    // 关闭数据库连接
    if (db.open()) {
        db.close();
        qDebug() << "Database connection closed successfully.";
    } else {
        qDebug() << "Database was not open, so no need to close.";
    }

}

void login::on_exitButton_clicked()//退出
{

    close();
}
