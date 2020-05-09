#include "dbManager.h"

dbManager::dbManager()
{
    bulkDB = QSqlDatabase::addDatabase("QSQLITE");
    bulkDB.setDatabaseName(DB_Path);

    if( QFile::exists(DB_Path) )
    {
        if (!bulkDB.open()) //be careful, SQLITE will create the db if it doesn't exist and return true.
        {
            qDebug() << "Error: could not open connection to database.";
        }
        else
        {
            qDebug() << "Database connection opened.";
        }
    }
    else
    {
        qDebug() << "Cannot open database because the DB Path does not exist.";
    }
}

dbManager::~dbManager()
{
    if (bulkDB.isOpen())
    {
        bulkDB.close();
    }
    qDebug() << "Destroying Databasemanager";
}

bool dbManager::isOpen() const
{
    return bulkDB.isOpen();
}

dbManager& dbManager::instance()
{
    static dbManager dmInstance;

    return dmInstance;
}
