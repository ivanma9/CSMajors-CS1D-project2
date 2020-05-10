#ifndef GRAPHDS_H
#define GRAPHDS_H

#include <iostream>		// cin, cout
#include <iomanip>		// setw(), fixed etc.
#include <QString>		// string class
#include <sstream>		// ostringstream, stringstream :
#include <QDebug>

//Standard Library
#include <QVector>
#include <QQueue>

//template <class Swappin>
//void swap(Swappin *xp, Swappin *yp)
//{
//    Swappin temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}

struct Arcs
{
    int distance;
    int pointA, pointB;
    char edgeType; //'b' = Back Edge; 'd' = Discovery Edge; 'c' = Cross Edge, 'f' = Foward Edge;

    Arcs(int dist, int a, int b, char ty) : distance(dist), pointA(a), pointB(b), edgeType(ty) {}

    bool operator == (Arcs compareTo)
    {
        bool qeuals;
        qeuals = (this->pointA == compareTo.pointA && this->pointB == compareTo.pointB)
                 //|| (this->pointA == compareTo.pointB && this->pointB == compareTo.pointA)
                 ;
        return qeuals;
    }
};

struct Airport
{
    QString name;
    QVector<int> ref; //ref the airport's edges


};

struct TableOutput
{
    QString stadiums;
    int mileage;

    TableOutput() : stadiums("stad"), mileage(0){}
    TableOutput(QString stad, int miles) : stadiums(stad), mileage(miles) {}

    //returns stadiums and mileage "Stadium, ##"
    QString Display(){ return stadiums + ", " + QString::number(mileage);}
};

class GraphDS
{
    QVector<Airport> airports;	//vector of the vectices: Airport
    QVector<Arcs> edges; //Vector of edge lines
    int numVertex;
    int numEdges;

    bool reachable;
    QVector<Arcs> disEdges; // displays the discovered edges IN ORDER of discover

    int FindClosest(int,  QVector<int>&, int&); // take the airport and finds the closest from its refs

    void Traverse(int, QVector<bool>&, QQueue<QString>&, int&);

    void Breadth(int, QVector<bool>&, QQueue<Airport>&, int&);



public:
    GraphDS();
    GraphDS(int);

    ~GraphDS();

    void AddAirport(QString);

    void ChangeAirportName(QString, int);

    void ConnectAirports(QString, QString endPort, int, char = 'b');
    void ConnectAirports(int, int endIndex, int, char = 'b');

    int FindEdges(int, int);
    int FindAirport(QString);

    void refSort(int);

    QString Display();
    void DisplayEdges();

    QList<TableOutput> DisplayDFS(QString);

    QList<TableOutput> DisplayBFS(QString);

    void reverseGraph();

    bool getReachable();

    int getNumVertex();

    int getNumEdges();

    //QString printArr(int arr[], int arrWeight[], int n);
    QList<TableOutput> PrimMST();
    QList<TableOutput> Djikstra(QString startStadium);


};

#endif // GRAPHDS_H
