#include "serverthread.h"



ServerThread::ServerThread(QTcpSocket *socket, const QString &request, QObject *parent):
    QThread(parent), _request(request), _socket(socket)
{

}

void ServerThread::run(){

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << _request;

    _socket.write(block);
}
