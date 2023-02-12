#include "databaserequesthandler.h"

DatabaseRequestHandler::DatabaseRequestHandler()
{
    _database = QSqlDatabase::addDatabase("QPSQL");

    _database.setDatabaseName("OnlineShop");
    _database.setPassword("135798");
    _database.setHostName("localhost");
    _database.setPort(5432);
    _database.setUserName("postgres");

    _database.open();

    if(_database.isOpenError())
        throw std::runtime_error("Can`t open database connection!");


    getTablesFromDatabase();
}

void DatabaseRequestHandler::getTablesFromDatabase()
{
    try{
        _accountsTable.setTable("accounts");
    }
    catch(...){
        throw std::runtime_error("Can`t get tables");
    }
}
