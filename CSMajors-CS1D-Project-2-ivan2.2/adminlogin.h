#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "User.h"
#include "LoginManager.h"

namespace Ui {
class adminLogin;
}

class adminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = nullptr);
    ~adminLogin();

    bool getValid();
    void logout();

private slots:
    void on_pwEdit_returnPressed();

    void on_pwEdit_textEdited(const QString &arg1);

    void on_OK_clicked();

    void on_cancel_clicked();

private:
    Ui::adminLogin *ui;

    bool validPW;
};

#endif // ADMINLOGIN_H
