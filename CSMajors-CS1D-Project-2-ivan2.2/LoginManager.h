#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H
#include "User.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant> //need for bindValue call.
#include <QDebug>
class LoginManager
{
public:

    static LoginManager& instance();


    LoginManager(LoginManager const&) = delete;     // Don't forget to disable copy

    void operator=(LoginManager const&) = delete;   // Don't forget to disable copy


    bool createUserAccount(const User& user) const; // will not be modifying internal state of AuthManager so const. Parameter also const since user cannot be modified.

    bool deleteUserAccount(int userId) const;

    bool updateUserAccount(const User& user) const;


    User authenticate(const QString& username, const QString& password) const;
private:

    LoginManager();  //forbid creation outside class


    ~LoginManager(); // forbid to delete instance outside
};

#endif // LOGINMANAGER_H
