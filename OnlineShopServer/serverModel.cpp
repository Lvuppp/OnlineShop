#include "serverModel.h"

ServerModel* ServerModel::_singltoneServer(nullptr);

ServerModel::ServerModel()
{
    if(!this->listen(QHostAddress::Any, _port)){
        throw std::runtime_error("Server can`t start listen!");
    }
}

ServerModel::~ServerModel()
{

}

ServerModel *ServerModel::getInstance()
{
    if(!_singltoneServer){
        _singltoneServer = new ServerModel;
    }

    return _singltoneServer;
}

void ServerModel::readDataStream(QDataStream stream)
{
    /*
        Данные приходят в виде запроса:
        TYPE_OF_REQUEST'\0'
    */

    while(true){

    }

    qDebug("Broke data");
}

void ServerModel::readyToRead()
{
    QTcpSocket* incomingSocket = qobject_cast<QTcpSocket *>(sender());

//    _databaseModel = QSqlRelationalTableModel( )
}

void ServerModel::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* incomingSocket = new QTcpSocket;
    incomingSocket->setSocketDescriptor(socketDescriptor);

    connect(incomingSocket, &QTcpSocket::readyRead, this, &ServerModel::readyToRead);
    connect(incomingSocket, &QTcpSocket::disconnected, this, &ServerModel::deleteLater);

    qDebug() << "incoming connection";
    _sockets.push_back(incomingSocket);

    emit incomingConnectionNotification(socketDescriptor);
}


