#include "User.h"

const QString& User::getUsername() const
{
    return username;
}

const QString& User::getPassword() const
{
    return password;
}

bool User::isAdministrator() const
{
    return isAdmin;
}

int User::getId() const
{
    return id;
}

void User::setId(int newId)
{
    id = newId;
}

void User::setUsername(const QString& uname)
{
    username = uname;
}

void User::setPassword(const QString& pass)
{
    password = pass;
}

void User::setAdministrator(bool isAdministrator)
{
    isAdmin = isAdministrator;
}

User::User()
    :User(UNASSIGNED_DB_ID, "", "", false)
{
}

User::User(const User& user)
    :User(user.id, user.username, user.password, user.isAdmin)
{
}

User::User(int dbId, const QString& uname, const QString& pass, bool isAdministrator)
    :id(dbId), username(uname), password(pass), isAdmin(isAdministrator)
{
}

User::User(const QString& uname, const QString& pass, bool isAdministrator)
    :User(UNASSIGNED_DB_ID, uname, pass, isAdministrator)
{
}

bool User::operator ==(const User& user) const
{
    return username.compare(user.username) == 0 &&
           password.compare(user.password) == 0 &&
           id == user.id;
}

bool User::operator !=(const User& user) const
{
    return !(*this == user);
}

User& User::operator =(const User& user)
{
    if( this != &user )
    {
        username = user.username;
        password = user.password;
        id = user.id;
        isAdmin = user.isAdmin;
    }

    return *this;
}


QString User::toString() const
{
    QString output;

    output = output % "Username: " % username %
                    "\nPassword: " % password %
                    "\nDB Id:    " + id;

    return output;
}
