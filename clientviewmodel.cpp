#include "clientviewmodel.h"

ClientViewModel::ClientViewModel()
{
    _socket = new QTcpSocket;

    try {
        _socket->connectToHost("192.168.0.113",9234);
        if (_socket->waitForConnected(1000))
             qDebug("Connected!");

    } catch (QTcpSocket::SocketError) {
        throw QTcpSocket::SocketError();
    }
}

ClientViewModel::~ClientViewModel()
{
    delete _socket;
}

void ClientViewModel::singUpRequestToServer()
{
    QByteArray data;
    QDataStream out(&data,QDataStream::Qt_6_2);
    _socket->write(data);
}
