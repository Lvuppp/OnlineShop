#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>
#include<QTcpSocket>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTcpSocket *socket = new QTcpSocket;

    socket->connectToHost("192.168.0.113",9234);

    LoginForm w;
    w.show();

    delete socket;
    return a.exec();
}
