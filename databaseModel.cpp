#include "databaseModel.h"

DatabaseModel::DatabaseModel()
{
    database = QSqlDatabase::addDatabase("QPSQL");

    database.setDatabaseName("InternetShop");
    database.setPassword("1111");
    database.setHostName("localhost");
    database.setPort(5432);
    database.setUserName("postgres");
}

bool DatabaseModel::openConnection()
{
    return database.open();
}
