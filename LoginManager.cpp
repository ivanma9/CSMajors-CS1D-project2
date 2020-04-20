#include "LoginManager.h"

// Constructor & Dectructor
LoginManager::LoginManager() {}
LoginManager::~LoginManager() {}

// methods
LoginManager& LoginManager::instance()
{
    // create instance by lazy initialization
    // guaranteed to be destroyed
    static LoginManager instance;

    return instance;
}

bool LoginManager::createUserAccount(const User& user) const
{
    if( user.getUsername().isEmpty() || user.getPassword().isEmpty() )
    {
        qDebug() << "Cannot create a User if username or password is not provided";
        return false;
    }

    //will not be modifying internal state of AuthManager so const. Parameter also const since user cannot be modified.
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO LoginInfo (UserID, Username, Password, isAdministrator) VALUES (:userId, :username, :password, :isAdmin)");
    insertQuery.bindValue("userId", user.getId());
    insertQuery.bindValue(":username", user.getUsername());
    insertQuery.bindValue(":password", user.getPassword());
    insertQuery.bindValue(":isAdmin", user.isAdministrator() ? 1 : 0);

    if( insertQuery.exec() )
    {
        qDebug() << "User account creation succeeded!";
        return true;
    }
    else
    {
        qDebug() << "User account creation failed: " << insertQuery.lastError();
        return false;
    }
}

bool LoginManager::deleteUserAccount(int userId) const
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM LoginInfo WHERE UserID = :userId");
    deleteQuery.bindValue(":userId", userId);

    if( deleteQuery.exec() )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LoginManager::updateUserAccount(const User& user) const
{
    QSqlQuery updateQuery;

    updateQuery.prepare("UPDATE LoginInfo SET Username = :username, Password = :password, isAdministrator = :isAdmin WHERE UserID = :userId");
    updateQuery.bindValue(":username", user.getUsername());
    updateQuery.bindValue(":password", user.getPassword());
    updateQuery.bindValue(":isAdmin", user.isAdministrator() ? 1 : 0);
    updateQuery.bindValue(":userId", user.getId());

    if( updateQuery.exec() )
    {
        return true;
    }
    else
    {
        return false;
    }
}

User LoginManager::authenticate(const QString& username, const QString& password) const
{
    LoginManager::instance();
    QSqlQuery query;

    query.prepare("SELECT UserID, Username, Password, isAdministrator FROM LoginInfo WHERE username = (:Username)");
    query.bindValue(":Username", username);
    if (query.exec())
        {
            int idID = query.record().indexOf("UserID");
            int idUsername = query.record().indexOf("Username");
            int idPassword = query.record().indexOf("Password");
            int idisAdministrator = query.record().indexOf("isAdministrator");

            if (query.next())
            {

                QString dbusername = query.value(idUsername).toString();
                QString dbpassword = query.value(idPassword).toString();
                bool dbisAdministrator = query.value(idisAdministrator).toInt() == 1;
                int dbid = query.value(idID).toInt();
                if( dbpassword == password )
                {
                    return User(dbid, dbusername, dbpassword, dbisAdministrator);
                }
            }
        }
        else
        {
            qDebug() << "Error authenticating: " << query.lastError();
        }

    return NULL_USER;
}
