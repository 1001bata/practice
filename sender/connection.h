#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>


static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../userlist.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;

    // 创建user表
    query.exec("create table user (id int primary key, "
                       "name varchar, pwd varchar)");
    query.exec("insert into user values(1, '1', '0')");
    query.exec("insert into user values(2, '马亮', '123')");
    query.exec("insert into user values(3, '孙红', '333')");



    return true;
}


#endif // CONNECTION_H
