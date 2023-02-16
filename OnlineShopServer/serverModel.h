#ifndef SERVERMODEL_H
#define SERVERMODEL_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

#include "databaserequesthandler.h"
#include "sqlrequestfactory.h"
#include "serverthread.h"

class ServerModel : public QTcpServer
{
    Q_OBJECT

public:
    ServerModel(const ServerModel&) = delete;
    ServerModel operator=(const ServerModel&) = delete;

    ~ServerModel();

    static ServerModel *getInstance();

public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void readyToRead();

signals:
    void incomingConnectionNotification(qintptr socketDescriptor);

private:
    ServerModel();

    void readDataStream(QByteArray _stream);
    void sendDataToClient(QTcpSocket *_clientRequest, QDataStream _out);
    void sendDataToClient(QTcpSocket *_clientRequest, QString _out);

    DatabaseRequestHandler _requestHandler;
    QVector<QTcpSocket *> _sockets;
    const int _port = 9234;
    QByteArray _data;

    static ServerModel* _singltoneServer;


};


#endif // SERVERMODEL_H
