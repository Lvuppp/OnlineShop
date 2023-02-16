#include "serverModel.h"

ServerModel* ServerModel::_singltoneServer(nullptr);

ServerModel::ServerModel()
{
    if(!this->listen(QHostAddress::Any, _port)){
        throw std::runtime_error("Server can`t start listen!");
    }
}

void ServerModel::sendDataToClient(QTcpSocket *_clientRequest, QDataStream _out)
{

}

void ServerModel::sendDataToClient(QTcpSocket *_clientRequest, QString _out)
{
    ServerThread* thread = new ServerThread(_clientRequest, _out, this);
    connect(thread, &ServerThread::finished, thread, &ServerThread::deleteLater);
    thread->start();
}

ServerModel::~ServerModel()
{
    for(auto socket : _sockets){
        delete socket;
    }
}

ServerModel *ServerModel::getInstance()
{
    if(!_singltoneServer){
        _singltoneServer = new ServerModel;
    }

    return _singltoneServer;
}

//void ServerModel::readDataStream(QByteArray incomingRequest)
//{

//}

void ServerModel::readyToRead()
{
    QTcpSocket* incomingSocket = qobject_cast<QTcpSocket *>(sender());

    /*
        Данные приходят в виде запроса:
        TYPE_OF_REQUEST'\0'REQUEST_PARAMS
    */

    QDataStream stream;
    stream.setVersion(QDataStream::Qt_6_2);
    qint64 sizeOfRequest = 0;

    while(sizeOfRequest != incomingSocket->readBufferSize()){

    }


    qDebug("Broke data");
}

void ServerModel::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* incomingSocket = new QTcpSocket;
    incomingSocket->setSocketDescriptor(socketDescriptor);

    connect(incomingSocket, &QTcpSocket::readyRead,
            this, &ServerModel::readyToRead);
    connect(incomingSocket, &QTcpSocket::disconnected,
            this, &ServerModel::deleteLater);

    _sockets.push_back(incomingSocket);
    qDebug() << "incoming connection";

    emit incomingConnectionNotification(socketDescriptor);
}

