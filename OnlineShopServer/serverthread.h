#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include<QThread>
#include<QTcpSocket>

#include"request.h"

class ServerThread : public QThread
{
    Q_OBJECT

public:
    ServerThread(QTcpSocket* socket, const QString& request, QObject *parent);

//    ServerThread(QTcpSocket currentClientSocket,
//                 Request* request, QObject *parent);

    void run() override;

private:
    QString _request;
    QTcpSocket _socket;
};

#endif // SERVERTHREAD_H
