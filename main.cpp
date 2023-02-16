#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>
#include<QTcpSocket>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    LoginForm w;
    w.show();

    return a.exec();
}
