#include "adminlogin.h"
#include "ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
    validPW = false;
    ui->errorText->hide();
    //ui->errorText->setStyleSheet("font:10");
}

adminLogin::~adminLogin()
{
    delete ui;
}

bool adminLogin::getValid()
{
    return validPW;
}

void adminLogin::logout()
{
    validPW = false;

}

void adminLogin::on_pwEdit_returnPressed()
{
    on_OK_clicked();
}

void adminLogin::on_pwEdit_textEdited(const QString &arg1)
{
    ui->errorText->hide();
}

void adminLogin::on_OK_clicked()
{
    User temp;
    QString password;

    password = ui->pwEdit->text();
    ui->pwEdit->clear();

    if(password == "admin")
    {
        validPW = true;
        this->close();
    }
    else ui->errorText->show();


    //SQL Database Login Method
//    temp = LoginManager::instance().authenticate("admin", password);


//    if(temp != NULL_USER)
//    {
//        validPW = true;
//        this->close();
//    }
//    else
//    {
//        ui->errorText->show();
//    }
}

void adminLogin::on_cancel_clicked()
{
    ui->pwEdit->clear();
    this->close();
    ui->errorText->hide();
}
