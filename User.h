#ifndef USER_H
#define USER_H

#include "Constants.h"
#include <QStringBuilder>
#include <QString>

class User
{
private:
    int id;            /*!< id */
    QString username;  /*!< username */
    QString password;  /*!< password */
    bool isAdmin;      /*!< isAdmin (administrator status) */

public:
    /**
       * @brief getUsername - get username
       * @return username
       */
    const QString& getUsername() const;

    /**
       * @brief getPassword - get password
       * @return password
       */
    const QString& getPassword() const;

    /**
       * @brief isAdministrator - gets the administrator status
       * @return isAdmin
       */
    bool isAdministrator() const;

    /**
       * @brief getId - gets employee ID number
       * @return id
       */
    int getId() const;

    /**
       * @brief setUsername - changes username to user specified
       * @param uname
       */
    void setUsername(const QString& uname);

    /**
       * @brief setPassword - changes password to user specified
       * @param pass
       */
    void setPassword(const QString& pass);

    /**
       * @brief setAdministrator - changes administrator status to user specified
       * @param isAdministrator
       */
    void setAdministrator(bool isAdministrator);
    void setId(int newId);

    /**
       * @brief User - default constructor
       */
    User();

    /**
       * @brief User - constructor w/ parameters
       * @param user - employee record
       */
    User(const User& user);

    /**
       * @brief User - constructor w/ parameters
       * @param dbId - database id number
       * @param uname - username
       * @param pass - passsword
       * @param isAdministrator - administrator status
       */
    User(int dbId, const QString& uname, const QString& pass, bool isAdministrator);

    /**
       * @brief User - constructor w/ parameters
       * @param uname - username
       * @param pass - password
       * @param isAdministrator - administrator status
       */
    User(const QString& uname, const QString& pass, bool isAdministrator);

    /**
       * @brief operator == overloading the equal operator
       * @param user - employee record
       * @return bool to determine if its equal or not
       */
    bool operator ==(const User& user) const;

    /**
       * @brief operator != overloading the does not equal operator
       * @param user - employee record
       * @return  bool to determine if its not equal
       */
    bool operator !=(const User& user) const;

    /**
       * @brief operator = overload the assignment operator
       * @param user - employee record
       * @return employee record if its equal
       */
    User& operator =(const User& user);

    /**
       * @brief toString - changes to string
       * @return
       */
    QString toString() const; //cannot return QString& const because I can't return stack variable.
};

const User NULL_USER;
#endif // USER_H
