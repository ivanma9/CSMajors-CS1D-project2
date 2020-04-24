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

    modifyTable = false; // turn off when directly modifying the admintable

    CreateGraph();
    ui->TraversalDisplay->setText(graphs.Display());

    ReadInfo();

    setupDisplayListTab();
    setupTeamInfoTab();

    modifyTable = true; // turn on when the admin table can be modified by user

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



}

void MainWindow::ReadInfo()
{
    MBLInfo newElement;
    QSqlQuery readInfo;
    readInfo.prepare("SELECT TeamName, StadiumName, SeatingCapacity, Location, PlayingSurface, League, DateOpened, DistanceToCenterFieldFT, DistanceToCenterFieldM, BallparkTypology, RoofType FROM MLBInformation");
    infoSize = 0;

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
            //newElement.DistantConvert(readInfo.value(7).toString());
            newElement.DistanceFT = readInfo.value(7).toInt();
            newElement.DistanceMeter = readInfo.value(8).toInt();
            newElement.BallparkTypology = readInfo.value(9).toString();
            newElement.RoofType = readInfo.value(10).toString();

            qDebug() << newElement.Display();
            infoSize++;
            mblInfo.push_back(newElement);
        }

    }
    else qDebug() << "Reading MLB INFO Failed: " << readInfo.lastError();

}



void MainWindow::setupDisplayListTab()
{
    /* DISPLAY REQUIREMENTS #4 - 13
     *
    4.	Display the list of all the major league team names and their corresponding stadiums names sorted by team name.
    5.	Display the list of all the major league team names and their corresponding stadiums names sorted by stadium name.
    6.	Display the list of American League team names and their corresponding stadiums names sorted by team name.
    7.	Display the list of National League team names and their corresponding stadiums names sorted by stadium name.
    8.	Display the list of stadiums and their corresponding team name sorted by park typology.  Be sure to display park typology.
    9.	Display the list of team names that have an open roof type sorted by team name.  Display the number of teams with an open roof type.
    10.	Display the list of stadiums and their corresponding team name in chronological order (oldest to newest) using date opened.   Be sure to display date opened.
    11.	Display the list of stadiums and their corresponding team names sorted by seating capacity (smallest to largest).  Be sure to display seating capacity.  Display the total capacity of all major league teams.
    12.	Display only the stadium(s) and corresponding team name(s) that has the greatest distance to center field.
    13.	Display only the stadium(s) and corresponding team name(s) that has the smallest distance to center field.
    */

    ui->comboBox->addItem("team name for All teams");               //4. DISPLAY - team name, stadium; SORT - team name; SELECT - ALL
    ui->comboBox->addItem("stadium name for All teams");            //5. DISPLAY - team name, stadium; SORT - stadium name; SELECT - ALL
    ui->comboBox->addItem("team name for American League");         //6. DISPLAY - team name, stadium; SORT - team name; SELECT - American
    ui->comboBox->addItem("stadium name for National League");      //7. DISPLAY - team name, stadium; SORT - stadium; SELECT - National

    ui->comboBox->addItem("park typology for All teams");           //8. DISPLAY - stadium, team name, typology; SORT - typology; SELECT - ALL
    ui->comboBox->addItem("team name for open roof type");          //9. DISPLAY -  team name, count(open roof type); SORT - stadium name; SELECT - open roof type == Yes
    ui->comboBox->addItem("chronological order (oldest to newest)");//10. DISPLAY - stadium, team name, open date; SORT - date opened descending; SELECT - ALL
    ui->comboBox->addItem("seating capactiy (smallest to largest)");//11. DISPLAY - stadium, team name, total capacity = sum(seating capacity); SORT - seating capacity ascending; SELECT - ALL

    ui->comboBox->addItem("greatest distance to center field");     //12. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - greatest distance to center field
    ui->comboBox->addItem("smallest distance to center field");     //13. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - smallest distance to center field

}

void MainWindow::setupTeamInfoTab()
{


    //sets up fancy push button

    ui->pushButton_TeamInfo->setIcon(QIcon(":/img/displayArrow.png"));//setStyleSheet("background-image:url(:/img/displayArrow.png)");
    ui->pushButton_TeamInfo->setIconSize(QSize(ui->pushButton_TeamInfo->width(), ui->pushButton_TeamInfo->height()));
    ui->pushButton_TeamInfo->setStyleSheet("QPushButton:hover {border: blue");


    for(int i = 0; i < mblInfo.size(); i++)
    {
        ui->listWidget->insertItem(i,mblInfo[i].TeamName);
        ui->SelectTeam->insertItem(i,mblInfo[i].TeamName);
    }


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

}

void MainWindow::on_BFS_clicked()
{
    ui->TraversalDisplay->setText(graphs.DisplayBFS("Chase Field"));

}

void MainWindow::on_pushButton_clicked()
{

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


//Search button
void MainWindow::on_pushButton_2_clicked()
{
    /*
    ui->comboBox->addItem("team name for All teams");         //4. DISPLAY - team name, stadium; SORT - team name; SELECT - ALL
    ui->comboBox->addItem("stadium name for All teams");      //5. DISPLAY - team name, stadium; SORT - stadium name; SELECT - ALL
    ui->comboBox->addItem("team name for American League");         //6. DISPLAY - team name, stadium; SORT - team name; SELECT - American
    ui->comboBox->addItem("stadium name for National League");      //7. DISPLAY - team name, stadium; SORT - stadium; SELECT - National

    ui->comboBox->addItem("park typology for All teams");         //8. DISPLAY - stadium, team name, typology; SORT - typology; SELECT - ALL
    ui->comboBox->addItem("team name for open roof type");      //9. DISPLAY -  team name, count(open roof type); SORT - stadium name; SELECT - open roof type == Yes
    ui->comboBox->addItem("chronological order (oldest to newest)");   //10. DISPLAY - stadium, team name, open date; SORT - date opened descending; SELECT - ALL
    ui->comboBox->addItem("seating capactiy (smallest to largest)");      //11. DISPLAY - stadium, team name, total capacity = sum(seating capacity); SORT - seating capacity ascending; SELECT - ALL

    ui->comboBox->addItem("greatest distance to center field");         //12. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - greatest distance to center field
    ui->comboBox->addItem("smallest distance to center field");         //13. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - smallest distance to center field
    */
    ui->calc_label->clear();
    ui->calc_label_2->clear();
    ui->calc_label_3->clear();

    int selection = ui->comboBox->currentIndex();
    bool successSelect = true;
    QSqlQueryModel *model;
    QSqlQuery *qry;
    QString sQry;
    QString sQry2;


    switch(selection)
    {
        case 0:
        {
            qDebug() << "4. DISPLAY - team name, stadium; SORT - team name; SELECT - ALL";
            sQry = "SELECT TeamName, StadiumName FROM MLBInformation ORDER BY TeamName";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 1:
        {
            qDebug() <<  "5. DISPLAY - team name, stadium; SORT - stadium name; SELECT - ALL";
            sQry = "SELECT TeamName, StadiumName FROM MLBInformation ORDER BY StadiumName";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 2:
        {
            qDebug() <<  "6. DISPLAY - team name, stadium; SORT - team name; SELECT - American";
            sQry = "SELECT TeamName, StadiumName FROM MLBInformation where League = 'American' ORDER BY TeamName";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 3:
        {
            qDebug() << "7. DISPLAY - team name, stadium; SORT - stadium; SELECT - National";
            sQry = "SELECT TeamName, StadiumName FROM MLBInformation where League = 'National' ORDER BY StadiumName";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 4:
        {
            qDebug() << "8. DISPLAY - stadium, team name, typology; SORT - typology; SELECT - ALL";
            sQry = "SELECT StadiumName, TeamName, BallparkTypology FROM MLBInformation ORDER BY BallparkTypology";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 5:
        {
            qDebug() << "9. DISPLAY -  team name, count(open roof type); SORT - stadium name; SELECT - open roof type == Yes";
            sQry = "SELECT TeamName FROM MLBInformation where RoofType = 'Open' ORDER BY StadiumName";
            sQry2 = "Select count(RoofType) FROM MLBInformation where RoofType = 'Open'";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->calc_label->setText("Number of Open Roof Type Stadiums");
            ui->calc_label_3->setText("Stadiums");
            break;
        }
        case 6:
        {
            qDebug() << "10. DISPLAY - stadium, team name, open date; SORT - date opened ascending; SELECT - ALL";
            sQry = "SELECT StadiumName, TeamName, DateOpened FROM MLBInformation ORDER BY DateOpened";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            break;
        }
        case 7:
        {
            qDebug() << "11. DISPLAY - stadium, team name, total capacity = sum(seating capacity); SORT - seating capacity ascending; SELECT - ALL";
            sQry = "SELECT StadiumName, TeamName, seating capacity FROM MLBInformation ORDER BY SeatingCapacity";
            sQry2 = "Select sum(SeatingCapacity) as 'Total Capacity' FROM MLBInformation";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            ui->calc_label->setText("Total Capacity");
            ui->calc_label_3->setText("Seats");
            break;
        }
        case 8:
        {
            qDebug() << "12. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - greatest distance to center field";
            sQry = "SELECT StadiumName, TeamName, MAX(DistanceToCenterFieldFT) as 'Distance to Center Field in feet', DistanceToCenterFieldM "
                   "as 'Distance to Center Field in meters' FROM MLBInformation";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            ui->displayInfo->setColumnWidth(2, 220);
            ui->displayInfo->setColumnWidth(3, 220);
            break;
        }
        case 9:
        {
            qDebug() << "13. DISPLAY - team name, stadium; SORT - distance to center field; SELECT - smallest distance to center field";
            sQry = "SELECT StadiumName, TeamName, MIN(DistanceToCenterFieldFT) as 'Distance to Center Field in feet', DistanceToCenterFieldM "
                   "as 'Distance to Center Field in meters' FROM MLBInformation";
            ui->displayInfo->setColumnWidth(0, 200);
            ui->displayInfo->setColumnWidth(1, 200);
            ui->displayInfo->setColumnWidth(2, 220);
            ui->displayInfo->setColumnWidth(3, 220);
            break;
        }
    default:
        qDebug() << "Invalid selection";
        successSelect = false;
    }



    if(successSelect)
    {
        qDebug() << "AFTER SWTICH:  " << sQry;

        model = new QSqlQueryModel();
        qry = new QSqlQuery();

        qry->prepare(sQry);

        if(qry->exec())
        {
            model->setQuery(*qry);
            ui->displayInfo->setModel(model);

            qDebug() << "Row: " << model->rowCount();
        }
        else
            qDebug() << "Displaying Failed: " << model->lastError();
        \

        if (!sQry2.isEmpty())
        {
            QString arithmetic = QString::number(GetOneLineArithmetic(sQry2));
            ui->calc_label_2->setText(arithmetic);
        }
        else
            qDebug() << "no sQry2";

    }
    else
    {
        qDebug() << "no query";
    }

}

int MainWindow::GetOneLineArithmetic(QString sQry2)
{
    int calc = -1;

    QSqlQuery qry;
    qry.prepare(sQry2);
    qry.exec();

    if(qry.next())
    {
        calc= qry.value(0).toInt();
    }

    return calc;
}

void MainWindow::on_pushButton_TeamInfo_clicked()
{
    ui->textEdit->clear();
    // 3.	Display all the information related to only one particular baseball team (Stadium name, Seating capacity, Location, Playing surface, Team name, League, Date opened, Distance to center field, Ballpark typology, Roof type). Do not display information related to the other MLB teams.

    int currRow = ui->listWidget->currentRow();
    qDebug() << currRow;

    if(currRow != -1)
    {
        // output += mblInfo[i].Display() + "\n";
        // ui->tempDisplayINFO->setText(output);
        ui->textEdit->setFontPointSize(40);
        ui->textEdit->setFontUnderline(true);

        ui->textEdit->insertPlainText(mblInfo[currRow].TeamName);
        ui->textEdit->setFontPointSize(24);

        ui->textEdit->setAlignment(Qt::AlignCenter);
        ui->textEdit->insertPlainText("\nStadium:");
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->insertPlainText(" " +mblInfo[currRow].StadiumName);
        ui->textEdit->setFontPointSize(20);
        ui->textEdit->insertPlainText("\n\nSeating Capacity: " +QString::number(mblInfo[currRow].SeatingCapacity)+ " seats");
        ui->textEdit->setAlignment(Qt::AlignLeft);  //align starting from prev line
        ui->textEdit->insertPlainText("\nLocation: " +mblInfo[currRow].Location);

        ui->textEdit->insertHtml("<br>");
        ui->textEdit->setFontPointSize(18);
        ui->textEdit->insertPlainText("\nPlaying Surface: " +mblInfo[currRow].PlayingSurface);
        ui->textEdit->insertPlainText("\nLeague: " +mblInfo[currRow].League+ " League");
        ui->textEdit->insertHtml("<br>");
        ui->textEdit->setFontPointSize(18);

        ui->textEdit->insertPlainText("\nOpening Date: " +QString::number(mblInfo[currRow].DateOpened));
        ui->textEdit->insertPlainText("\nDistance to Center Field: " +QString::number(mblInfo[currRow].DistanceFT) + " feet (" + QString::number(mblInfo[currRow].DistanceMeter) + "meters)");

        ui->textEdit->insertPlainText("\nPark Typology: " +mblInfo[currRow].BallparkTypology);
        ui->textEdit->insertPlainText("\nRoof Type: " +mblInfo[currRow].League);

    }
    else
    {
        qDebug() << "No row selected";
    }

}

void MainWindow::on_SelectTeam_currentIndexChanged(int index)
{
    modifyTable = false;

    QTableWidgetItem *nodes; //adds in the data
//QSpinBox *numberBox;
    QStringList headers;
    headers << "Name" << "Stadium" << "Seating"
            << "Location" << "Playing Surface" << "League"
            << "Date Opened" << "Distance in feet" << "Distance in Meters"
            << "Ballpark Typology" << "Roof Type";

    //resets the table
    ui->ModifyTable->setRowCount(11);
    ui->ModifyTable->setColumnCount(1);
    ui->ModifyTable->setColumnWidth(0,500);

    //prints in the data into teh table
    ui->ModifyTable->setHorizontalHeaderLabels(QStringList("Double-click to modify an item"));
    ui->ModifyTable->setVerticalHeaderLabels(headers);

    //Sets TeamName
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].TeamName);
    ui->ModifyTable->setItem(0,0, nodes);


    //Sets StadiumName
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].StadiumName);
    ui->ModifyTable->setItem(1,0, nodes);

    //Sets SeatingCapacity
    nodes = new QTableWidgetItem();
    nodes -> setText(QString::number(mblInfo[index].SeatingCapacity));
    ui->ModifyTable->setItem(2,0, nodes);

//    //This uses a number spinbox to show and change the number
//    //Sets SeatingCapacity
//    numberBox = new QSpinBox;
//    numberBox->setRange(0, 10000000);
//    numberBox->setValue(mblInfo[index].SeatingCapacity);
//    ui->ModifyTable->setCellWidget(2,0, numberBox);

    //Sets Location
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].Location);
    ui->ModifyTable->setItem(3,0, nodes);

    //Sets PlayingSurface
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].PlayingSurface);
    ui->ModifyTable->setItem(4,0, nodes);

    //Sets League
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].League);
    ui->ModifyTable->setItem(5,0, nodes);

    //Sets DateOpened
    nodes = new QTableWidgetItem();
    nodes -> setText(QString::number(mblInfo[index].DateOpened));
    ui->ModifyTable->setItem(6,0, nodes);

    //Sets DistanceFT
    nodes = new QTableWidgetItem();
    nodes -> setText(QString::number(mblInfo[index].DistanceFT));
    ui->ModifyTable->setItem(7,0, nodes);

    //Sets DistanceMeter
    nodes = new QTableWidgetItem();
    nodes -> setText(QString::number(mblInfo[index].DistanceMeter));
    ui->ModifyTable->setItem(8,0, nodes);

    //Sets BallparkTypology
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].BallparkTypology);
    ui->ModifyTable->setItem(9,0, nodes);

    //Sets League
    nodes = new QTableWidgetItem();
    nodes -> setText(mblInfo[index].RoofType);
    ui->ModifyTable->setItem(10,0, nodes);

    modifyTable = true;

}

// any changes to the table will be applied onto the stored data
void MainWindow::on_ModifyTable_itemChanged(QTableWidgetItem *item)
{
    if(modifyTable)
    {
        modifyTable = false;
        QSqlQuery updateQuery;

        int selected = ui->SelectTeam->currentIndex();
        int rowAt = ui->ModifyTable->currentRow();
        int convertNum;

        switch(rowAt)
        {
           case 0: // TeamName was changed
            mblInfo[selected].TeamName = ui->ModifyTable->item(0,0)->text();
            ui->listWidget->item(selected)->setText(mblInfo[selected].TeamName);
            ui->SelectTeam->setItemText(selected, mblInfo[selected].TeamName);

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET TeamName = :teamname WHERE itemID = :index");
            updateQuery.bindValue(":teamname", mblInfo[selected].TeamName);
            updateQuery.bindValue(":index", selected+1);

           break;

           case 1: // StadiumName was changed
            mblInfo[selected].StadiumName = ui->ModifyTable->item(1,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET StadiumName = :stadiumname WHERE itemID = :index");
            updateQuery.bindValue(":stadiumname", mblInfo[selected].StadiumName);
            updateQuery.bindValue(":index", selected+1);

           break;

           case 2: // SeatingCapacity was changed
            if((convertNum=(ui->ModifyTable->item(2,0)->text()).toInt()))
                mblInfo[selected].SeatingCapacity = convertNum;
            else
            {
                QMessageBox::warning(this, tr("Invalid Seating Capacity"),
                                          "Cannot read the input. Can only put in a number.\n\nPlease try again!");
                ui->ModifyTable->item(2,0)->setText(QString::number(mblInfo[selected].SeatingCapacity));
            }

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET SeatingCapacity = :seatingcapacity WHERE itemID = :index");
            updateQuery.bindValue(":seatingcapacity", mblInfo[selected].SeatingCapacity);
            updateQuery.bindValue(":index", selected+1);

           break;

           case 3: // Location was changed
            mblInfo[selected].Location = ui->ModifyTable->item(3,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET Location = :location WHERE itemID = :index");
            updateQuery.bindValue(":location", mblInfo[selected].Location);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 4: // PlayingSurface was changed
            mblInfo[selected].PlayingSurface = ui->ModifyTable->item(4,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET Location = :location WHERE itemID = :index");
            updateQuery.bindValue(":location", mblInfo[selected].Location);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 5: // League was changed
            mblInfo[selected].League = ui->ModifyTable->item(5,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET Location = :location WHERE itemID = :index");
            updateQuery.bindValue(":location", mblInfo[selected].Location);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 6: // DateOpened was changed
            if((convertNum=(ui->ModifyTable->item(6,0)->text()).toInt()))
                mblInfo[selected].DateOpened = convertNum;
            else
            {
                QMessageBox::warning(this, tr("Invalid Date Opened"),
                                          "Cannot read the input. Can only put in a number.\n\nPlease try again!");
                ui->ModifyTable->item(6,0)->setText(QString::number(mblInfo[selected].SeatingCapacity));
            }

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET DateOpened = :dateopened WHERE itemID = :index");
            updateQuery.bindValue(":dateopened", mblInfo[selected].DateOpened);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 7: // DistanceFT was changed
            if((convertNum=(ui->ModifyTable->item(7,0)->text()).toInt()))
                mblInfo[selected].DistanceFT = convertNum;
            else
            {
                QMessageBox::warning(this, tr("Invalid Distance in feet"),
                                          "Cannot read the input. Can only put in a number.\n\nPlease try again!");
                ui->ModifyTable->item(7,0)->setText(QString::number(mblInfo[selected].SeatingCapacity));
            }

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET DistanceToCenterFieldFT = :distanceft WHERE itemID = :index");
            updateQuery.bindValue(":distanceft", mblInfo[selected].DistanceFT);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 8: // DistanceMeter was changed
            if((convertNum=(ui->ModifyTable->item(8,0)->text()).toInt()))
                mblInfo[selected].DistanceMeter = convertNum;
            else
            {
                QMessageBox::warning(this, tr("Invalid Distance in meters"),
                                          "Cannot read the input. Can only put in a number.\n\nPlease try again!");
                ui->ModifyTable->item(8,0)->setText(QString::number(mblInfo[selected].SeatingCapacity));
            }
            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET DistanceToCenterFieldM = :distancemeter WHERE itemID = :index");
            updateQuery.bindValue(":distancemeter", mblInfo[selected].DistanceMeter);
            updateQuery.bindValue(":index", selected+1);
           break;

           case 9: // BallparkTypology was changed
            mblInfo[selected].BallparkTypology = ui->ModifyTable->item(9,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET BallparkTypology = :ballparktypology WHERE itemID = :index");
            updateQuery.bindValue(":ballparktypology", mblInfo[selected].BallparkTypology);
            updateQuery.bindValue(":index", selected+1);
           break;


           case 10: // RoofType was changed
            mblInfo[selected].RoofType = ui->ModifyTable->item(10,0)->text();

            //SQL Update
            updateQuery.prepare("UPDATE MLBInformation SET RoofType = :rooftype WHERE itemID = :index");
            updateQuery.bindValue(":rooftype", mblInfo[selected].RoofType);
            updateQuery.bindValue(":index", selected+1);
           break;

        }

        //Executes the update from one of the case.
        if(! updateQuery.exec())
            qDebug() << "updateQuery NOT executed: "
                     << updateQuery.lastError();
        updateQuery.clear();

        modifyTable = true;
    }
}

void MainWindow::UpdateInfo(int index)
{

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE MLBInformation SET TeamName = :teamname, StadiumName = :stadiumname, SeatingCapacity = :seatingcapacity, Location = :location, PlayingSurface = :playingsurface, League = :league, DateOpened = :dateopened, DistanceToCenterFieldFT = :distanceft, DistanceToCenterFieldM = :distancemeter, BallparkTypology = :ballparktypology, RoofType = :rooftype WHERE itemID = :index");

    updateQuery.bindValue(":teamname", mblInfo[index].TeamName);
    updateQuery.bindValue(":stadiumname", mblInfo[index].StadiumName);
    updateQuery.bindValue(":seatingcapacity", mblInfo[index].SeatingCapacity);
    updateQuery.bindValue(":location", mblInfo[index].Location);
    updateQuery.bindValue(":playingsurface", mblInfo[index].PlayingSurface);
    updateQuery.bindValue(":league", mblInfo[index].League);
    updateQuery.bindValue(":dateopened", mblInfo[index].DateOpened);
    updateQuery.bindValue(":distanceft", mblInfo[index].DistanceFT);
    updateQuery.bindValue(":distancemeter", mblInfo[index].DistanceMeter);
    updateQuery.bindValue(":ballparktypology", mblInfo[index].BallparkTypology);
    updateQuery.bindValue(":rooftype", mblInfo[index].RoofType);
    updateQuery.bindValue(":index", index+1);

    if( updateQuery.exec() )
    {
        qDebug() << "UpdateInfo() Succuessful! ";
    }
    else
    {
        qDebug() << "UpdateInfo NOT succuessful! "
                 << updateQuery.lastError();
    }

    updateQuery.clear();
}
