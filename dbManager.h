#ifndef dbManager_H
#define dbManager_H

#include "mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QFile>

class dbManager
{
public:
    /**
     * @brief instance - connects to the database
     * @return the instance of the database
     */
    static dbManager& instance();

    /**
     * @brief dbManager - deletes the copy constructor
     */
    dbManager(const dbManager&) = delete; //delete copy constructor

    /**
     * @brief operator = (deletes the = operator)
     */
    void operator =(const dbManager&) = delete; //delete = operator

    /**
     * @brief isOpen - checks if the database is open
     * @return a bool if its open or not (1 or 0 )
     */
    bool isOpen() const;
private:
    /**
     * @brief dbManager - default constructor
     */
    dbManager();

    /**
     * @brief dbManager - default destructor
     */
    ~dbManager();

    /**
     * @brief bulkDB - default database
     */
    QSqlDatabase bulkDB;
};

#endif // dbManager_H
