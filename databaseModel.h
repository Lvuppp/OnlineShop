#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlDatabase>

class DatabaseModel
{

public:
    DatabaseModel();
    bool openConnection();

private:
    QSqlDatabase database;
};

#endif // DATABASEMODEL_H
