#ifndef DATABASEREQUESTHANDLER_H
#define DATABASEREQUESTHANDLER_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>

class DatabaseRequestHandler
{
public:
    DatabaseRequestHandler();


private:

    void getTablesFromDatabase();

    QSqlDatabase _database;    
    QSqlRelationalTableModel _accountsTable;

};

#endif // DATABASEREQUESTHANDLER_H
