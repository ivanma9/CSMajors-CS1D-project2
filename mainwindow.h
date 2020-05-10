#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adminlogin.h"
#include "LoginManager.h"
#include "graphds.h"
#include "mapds.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QInputDialog>
#include <QSqlQueryModel>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QListWidgetItem>
#include <QFile>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Date
{
    int day;
    int month;
    int year;

    Date(int mmonth, int dday, int yyear)
        : day(dday), month(mmonth), year(yyear) {}

    QString Display()
    {
        QString output = "";

        output += QString::number(month) + " / " + QString::number(day) + " / " + QString::number(year);

        return output;
    }
};

struct MBLInfo
{
    QString TeamName;
    QString StadiumName;
    long long SeatingCapacity;
    QString Location;
    QString PlayingSurface;
    QString League;
    long long DateOpened;
        int DistanceFT;
        int DistanceMeter;
    QString BallparkTypology;
    QString RoofType;

    //turns the distance String from the format ### feet ###
    //and store it into the feet and meter respectively.
    /*
    void DistantConvert(QString str)
    {
        QStringList temp = str.split("feet", QString::SkipEmptyParts);

        DistanceFT = temp[0].toInt();
        DistanceMeter = temp[1].toInt();
    }
    */
    //contrustor
    MBLInfo():  TeamName(""),
                StadiumName(""),
                SeatingCapacity(0),
                Location(""),
                PlayingSurface(""),
                League(""),
                DateOpened(0),
                DistanceFT(0),
                DistanceMeter(0),
                BallparkTypology(""),
                RoofType("") {}


    QString Display()
    {
        QString output = "";
        QString spacer = " | ";

        output += "Team Name: ";
        output += TeamName;
        output += spacer;

        output += "Stadium Name: ";
        output += StadiumName;
        output += spacer;

        output += "Seating Capacity: ";
        output += QString::number(SeatingCapacity);
        output += spacer;

        output += "Location: ";
        output += Location;
        output += spacer;

        output += "Playing Surface: ";
        output += PlayingSurface;
        output += spacer;

        output += "League: ";
        output += League;
        output += spacer;

        output += "Date Opened: ";
        output += QString::number(DateOpened);
        output += spacer;

        output += "Distant (feet): ";
        output += QString::number(DistanceFT);
        output += spacer;

        output += "Distant (meter): ";
        output += QString::number(DistanceMeter);
        output += spacer;

        output += "Ballpark Typology: ";
        output += BallparkTypology;
        output += spacer;

        output += "Roof Type: ";
        output += RoofType;
        output += spacer;

        return output;

    }

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CreateGraph(); //uses graph
    void ReadInfo();    //intitallizes MLB vector
    void UpdateInfo(int);   //takes everything from MLB vector in SQL

    void setupDisplayListTab(); //nope
    void setupTeamInfoTab();    //updates the combo box in the Info & Admin Tab
    void setupCustomSelect();   //updates the combo box in the Algorithms Tab
    int GetOneLineArithmetic(QString sQry); //nope

    void UpdateCustomTable(QList<TableOutput> output); //directly prints the tablewidget in the algorithmTest

    void ReadSouvenirs();//reads from SQL for souvenirs

    void ReadTxt();

    bool teamExist(QString teamName);


private slots:
    //ADMIN LOGIN button
    void on_login_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_TeamInfo_clicked();

    void on_SelectTeam_currentIndexChanged(int index);

    void on_ModifyTable_itemChanged(QTableWidgetItem *item);

    QList<TableOutput> on_CustomDijkstra_clicked();

    void on_CustomMST_clicked();

    QList<TableOutput> on_CustomDFS_clicked();

    void on_CustomBFS_clicked();

    void on_CustomTripSelect_itemDoubleClicked(QListWidgetItem *item);

    void on_ResetTrip_clicked();

    void on_PlanTripButton_clicked();

    void on_PlanTripDijkstra_clicked();

    void on_TripTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_PrevStadium_clicked();

    void on_NextStadium_clicked();


    void on_ResetSouvenir_clicked();

    void on_BuySouvenir_clicked();

    void on_DeleteSouv_clicked();

    void on_AddSouv_clicked();

    void on_LV_Button_clicked();

private:
    Ui::MainWindow *ui;

    adminLogin loginWindow;//opens the adminLogin window, enable admin login feature

    GraphDS graphs; // holds the DistanceBetweenStadiums dataset in Graph Data Structure
    mapDS souvenirs;// holds the souvenirs dataset in a Map-Array Data Structure
    QList<MBLInfo> mblInfo; // holds the MBL Information dataset
    int infoSize;   //size of the mbl
    double totalPrice;//acumulator for $$ of all souvenirs bought

    bool modifyTable; // controls the auto changing nature of on_ModifyTable_itemChanged()

    void printTripTable(QList<TableOutput> trip);
    void showTripsStadium(int stadium);

    void showSouvenir();//test display func
    void UpdateTotalCost();// Updates TotalCost label

    int currentShown = 0; // marks the index of whats currently shown in StadiumTripInfo from howTripsStadium
};
#endif // MAINWINDOW_H
