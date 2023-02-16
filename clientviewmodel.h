#ifndef CLIENTVIEWMODEL_H
#define CLIENTVIEWMODEL_H

#include<QObject>
#include<QTcpSocket>

class ClientViewModel : public QObject
{
    Q_OBJECT

public:
    ClientViewModel();
    ~ClientViewModel();

public slots:
    void singUpRequestToServer();

signals:
    void sendRequestToServer();

private:
    QTcpSocket *_socket;
};

#endif // CLIENTVIEWMODEL_H
