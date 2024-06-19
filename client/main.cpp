#include "login.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection()) return 1;

    login w;
    w.show();
//    Client w;
//    w.show();
    return a.exec();
}
