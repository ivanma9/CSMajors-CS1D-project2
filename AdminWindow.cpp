#include "AdminWindow.h"
#include "ui_AdminWindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_PushButton_BackTMain_clicked()
{
    MainWindow* mainWindow = new MainWindow(this);
    this->close();
    mainWindow->show();
}
