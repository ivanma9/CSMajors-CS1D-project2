#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QString>

/** @brief constants header file used for constant variables.

    Constant variables
    @author Mitchell O'Hair
    @date March 2018
    */

/** @brief
 *  So we don't change the database
    */
const int UNASSIGNED_DB_ID = -1;

/**
 * @brief Database path
    */
const QString DB_Path = ":/BaseballDatabase.db";

/**
 * @brief LOGIN_TABLE
 */
const QString LOGIN_TABLE = "LoginInfo";

/**
 * @brief MEMBER_TABLE
 */
const QString MEMBER_TABLE = "Member";

/**
 * @brief INVENTORY_TABLE
 */
const QString INVENTORY_TABLE = "Inventory";
#endif // CONSTANTS_H
