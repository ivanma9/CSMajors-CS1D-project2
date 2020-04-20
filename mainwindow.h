#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adminlogin.h"
#include "LoginManager.h"
#include "graphds.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QInputDialog>
#include <QSqlQueryModel>

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
    void DistantConvert(QString str)
    {
        QStringList temp = str.split("feet", QString::SkipEmptyParts);

        DistanceFT = temp[0].toInt();
        DistanceMeter = temp[1].toInt();
    }

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

    void CreateGraph();
    void ReadInfo();

private slots:
    void on_login_clicked();

    void on_DFS_clicked();

    void on_BFS_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    adminLogin loginWindow;

    GraphDS graphs;
    QList<MBLInfo> mblInfo;
};
#endif // MAINWINDOW_H
