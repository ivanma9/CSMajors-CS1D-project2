#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase myDB;

    ui->UsersTabs->setCurrentIndex(0);
    ui->UsersTabs->removeTab(1);
    ui->login->setText("Admin Login");

    if(QSqlDatabase::contains()) {
        myDB = QSqlDatabase::database(QLatin1String(QSqlDatabase::defaultConnection), false);
    }
    else {
        myDB = QSqlDatabase::addDatabase("QSQLITE");
    }
    myDB.setDatabaseName("BaseballDatabase.db");
    myDB.open();

    CreateGraph();
    ui->TraversalDisplay->setText(graphs.Display());

    ReadInfo();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateGraph()
{
    QStringList airportNames;
    QSqlQuery readGraph;
    readGraph.prepare("SELECT OriginatedStadium, DestinationStadium, Distance FROM DistanceBetweenStadiums");

    qDebug() << "Creating Graph";

    if(readGraph.exec())
    {
        while(readGraph.next())
        {
            airportNames << readGraph.value(0).toString();
        }
        airportNames.removeDuplicates();
        qDebug() << "number of vertex: "<< airportNames.size();

        //Create the vertices
        for(int i = 0; i < airportNames.size(); i++)
        {
            qDebug() << airportNames[i];

            graphs.AddAirport(airportNames[i]);
        }

    }
    else qDebug() << "Create Graph Failed: " << readGraph.lastError();

    if(readGraph.exec())
    {
        //Create the edges
        while(readGraph.next())
        {
            graphs.ConnectAirports(readGraph.value(0).toString(),
                                   readGraph.value(1).toString(),
                                   readGraph.value(2).toInt());
        }

        qDebug() << "Total Vertices: "<< graphs.getNumVertex();
        qDebug() << "Total Edges: "<< graphs.getNumEdges();

    }
    else qDebug() << "Create Graph Failed: " << readGraph.lastError();

    //Storing Other Info
    if(readGraph.exec())
    {
        //Create the edges
        while(readGraph.next())
        {
            graphs.ConnectAirports(readGraph.value(0).toString(),
                                   readGraph.value(1).toString(),
                                   readGraph.value(2).toInt());
        }

        qDebug() << "Total Vertices: "<< graphs.getNumVertex();
        qDebug() << "Total Edges: "<< graphs.getNumEdges();

    }
    else qDebug() << "Create Graph Failed: " << readGraph.lastError();

}

void MainWindow::ReadInfo()
{
    MBLInfo newElement;
    QSqlQuery readInfo;
    readInfo.prepare("SELECT TeamName, StadiumName, SeatingCapacity, Location, PlayingSurface, League, DateOpened, DistanceToCenterField, BallparkTypology, RoofType FROM MLBInformation");

    if(readInfo.exec())
    {
        while(readInfo.next())
        {
            newElement.TeamName = readInfo.value(0).toString();
            newElement.StadiumName = readInfo.value(1).toString();
            newElement.SeatingCapacity = readInfo.value(2).toLongLong();
            newElement.Location = readInfo.value(3).toString();
            newElement.PlayingSurface = readInfo.value(4).toString();
            newElement.League = readInfo.value(5).toString();
            newElement.DateOpened = readInfo.value(6).toLongLong();
            newElement.DistantConvert(readInfo.value(7).toString());
            newElement.BallparkTypology = readInfo.value(8).toString();
            newElement.RoofType = readInfo.value(9).toString();

            qDebug() << newElement.Display();

            mblInfo.push_back(newElement);
        }

    }
    else qDebug() << "Reading MLB INFO Failed: " << readInfo.lastError();

}

void MainWindow::on_login_clicked()
{
    if(ui->login->text() == "Admin Login")
    {
        loginWindow.exec();


        if(loginWindow.getValid())
        {
             QMessageBox::information(this, "Login", "Welcome to the Administrator Page");
             ui->UsersTabs->addTab(ui->Admin, "Admin");
             ui->UsersTabs->setCurrentIndex(1);
             ui->login->setText("Logout");
        }
    }
    else if(ui->login->text() == "Logout")
    {
        loginWindow.logout();
        ui->UsersTabs->setCurrentIndex(0);
        ui->UsersTabs->removeTab(1);
        ui->login->setText("Admin Login");
        QMessageBox::information(this, tr("Logged out"),
                             "You have successfully logged out.");

    }


}


void MainWindow::on_DFS_clicked()
{
    ui->TraversalDisplay->setText(graphs.DisplayDFS("Chase Field"));
    //graphs.DisplayDFS("Chase Field");

}

void MainWindow::on_BFS_clicked()
{
    ui->TraversalDisplay->setText(graphs.DisplayBFS("Chase Field"));
    //ui->TraversalDisplay->setText(graphs.Display());

}

void MainWindow::on_pushButton_clicked()
{
    QString output;

    for(int i = 0; i < mblInfo.size(); i++)
        output += mblInfo[i].Display() + "\n";
    ui->tempDisplayINFO->setText(output);

    QSqlQueryModel *model;
    QSqlQuery *qry;

    model = new QSqlQueryModel();
    qry = new QSqlQuery();


    qry->prepare("SELECT * FROM MLBInformation");

    if(qry->exec())
    {
        model->setQuery(*qry);
        ui->displayInfo->setModel(model);
        qDebug() << "Row: " << model->rowCount();
    }
    else qDebug() << "Displaying Failed: " << model->lastError();




}
