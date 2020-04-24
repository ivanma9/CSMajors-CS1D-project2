#include "graphds.h"


GraphDS::GraphDS()
{
    numVertex = 0;
    numEdges = 0;
    reachable = false;
}
GraphDS::GraphDS(int size)
{
    airports.resize(size);
    numVertex = size;
    numEdges = 0;
    reachable = false;
}

int GraphDS::getNumVertex()
{
    //return numVertex;
    return airports.size();
}

int GraphDS::getNumEdges()
{
    //return numEdges;
    return edges.size();

}

GraphDS::~GraphDS(){}

bool GraphDS::getReachable()
{
    return reachable;
}

void GraphDS::AddAirport(QString newNode)
{
    Airport node;

    node.name = newNode;
    numVertex++;
    airports.push_back(Airport(node));
}

void GraphDS::ChangeAirportName(QString airportName, int index)
{
    airports[index].name = airportName;
}

void GraphDS::ConnectAirports(QString startPort, QString endPort, int distance, char type)
{
    int startIndex = FindAirport(startPort);
    int endIndex = FindAirport(endPort);

    if(startIndex != -1 && endIndex != -1)
    {
        //IF the indexes are found, call the other ConnectAirports(int,int,int)
//cout << "Connecting " << startPort << " to " << endPort << endl;
        ConnectAirports(startIndex, endIndex, distance, tolower(type));
    }
    else
        qDebug() << "Could not find the airports.\n";

}
void GraphDS::ConnectAirports(int startIndex, int endIndex, int distance, char type)
{
    if(FindEdges(startIndex, endIndex) == -1)
    {
        edges.push_back(Arcs(distance, startIndex, endIndex, tolower(type)));
        numEdges++;
    }
    else
        qDebug() << "\tEdge already exist.\n";


    //qDebug() << Adding
    airports[startIndex].ref.push_back(endIndex);
}

int GraphDS::FindEdges(int aPoint, int bPoint)
{
    for(int j = 0 ; j < numEdges; j++)
    {
        //Two-way Edge has both conditions. Directed Edge will only need one condition
        if((edges[j].pointA == aPoint && edges[j].pointB == bPoint)
          ||(edges[j].pointA == bPoint && edges[j].pointB == aPoint)) // remove and it creates twice the edges, only going one way
            return j;
    }

    return -1;
}

int GraphDS::FindAirport(QString target)
{
    for(int x = 0 ; x < airports.size(); x++)
        if(airports[x].name == target )
            return x;

    // IF the airport is not found
    return -1;
}


void GraphDS::refSort(int currentAirport)
{
    int edge1, edge2, temp;
    int refSize = airports[currentAirport].ref.size();

    if(refSize > 1)
    {
        for (int i = 0; i < refSize-1; i++)
        for (int j = 0; j < refSize-i-1; j++)
        {
            edge1  = FindEdges(currentAirport, airports[currentAirport].ref[j]);
            edge2  = FindEdges(currentAirport, airports[currentAirport].ref[j+1]);
            if ((edge1 != -1 || edge2 != -1) && (edges[edge1].distance > edges[edge2].distance))
                //swap(&airports[currentAirport].ref[j], &airports[currentAirport].ref[j+1]);
            {
                temp = airports[currentAirport].ref[j];
                airports[currentAirport].ref[j] = airports[currentAirport].ref[j+1];
                airports[currentAirport].ref[j+1] = temp;
            }
        }

    }
}


QString GraphDS::Display()
{
    int index, aPoint, bPoint, refPoint, refSize;
    QString output = "";

    output += "Displaying the graph. Every Vertex and each of its ref edges\n";
    output += "Total Vertices: " + QString::number(numVertex) + "\n";
    output += "Total Edges: " + QString::number(numEdges) + "\n";

    for(int i = 0 ; i < numVertex; i++)
    {
        refSort(i);
        refSize = airports[i].ref.size();
        output += "Index: " + QString::number(i) + " | " + QString::number(airports[i].ref.size()) + " refs | " ;
        for(int j = 0 ; j < refSize; j++)
            output += QString::number(airports[i].ref[j]) + ", ";
        output += "\n" + airports[i].name + " connects to " + "\n";

        for(int j = 0 ; j < refSize; j++)
        {
            refPoint = airports[i].ref[j];
            //index = airports[i].edges[j];
            index = FindEdges(i,refPoint);
            if(index != -1)
            {

                aPoint= edges[index].pointA;
                bPoint= edges[index].pointB;
                output += "     " + airports[refPoint].name
                        + " (" + QString::number(aPoint) +","+ QString::number(bPoint) + ") - "
                        + QString::number(edges[index].distance);
                output += "\n";

            }
            else
                qDebug() << "This edge doesn't exist\n";

        }output += "\n";
    }

    return output;
}
QString GraphDS::DisplayDFS(QString startingAt)
{
    int startIndex = FindAirport(startingAt);
    int refSize, citiesTravelled;
    QString output = "";

    if(startIndex != -1)
    {	// Airport is found
        //Any Initializations
        QVector<bool> visit (numVertex, false); // flag that is parallel with airports vector
        QQueue<QString> ports;
        int travelled = 0;
        refSize = airports.size();
        for(int i = 0 ; i < refSize; i++)
            refSort(i);

        //resets the edge types to a back edge
        for(int i = 0 ; i < edges.size(); i++)
            edges[i].edgeType = 'b';
        disEdges.clear();

        //The Traversal
        Traverse(startIndex, visit, ports, travelled);

        //Displaying the trip
        output += "DFS Trip. Starting trip at ";

        refSize = ports.size();
        for(citiesTravelled = 0 ; citiesTravelled < refSize; citiesTravelled++)
        {
            output += ports.front();
            if(citiesTravelled+1 < refSize)
               output += " --> ";
            ports.pop_front();
        }
        output += "\n\nCities visited: " + QString::number(citiesTravelled) + "\n";
        reachable = citiesTravelled == numVertex;
//        if(citiesTravelled == numVertex)
//            qDebug() << "\t***This is POTENTIALLY a strongly connected graph! It visits all " << numVertex << " vertices***\n"<< endl;
//        else
//            qDebug() << "\t***This is potentially NOT a strongly connected graph! It only can visit " << citiesTravelled << " vertices, starting from " << airports[startIndex].name << ".\n***";

        output += "Total Distance = " + QString::number(travelled) + "\n";

        //DisplayEdges();
    }
    else qDebug() << "Could not find the airport. Could not run the traversal\n";

    return output;
}
void GraphDS::Traverse(int currentAirport, QVector<bool>& visited, QQueue<QString>& output, int& travel)
{
    int next, distanceAdd;

    output.push_back(airports[currentAirport].name);
    visited[currentAirport] = true;

    for(int j = 0 ; j < airports[currentAirport].ref.size(); j++)
    {	//Look thru all the current airport's refs
        next = airports[currentAirport].ref[j];

        if(!visited[next])
        {
            distanceAdd = FindEdges(currentAirport,next);
            if(distanceAdd != -1)
            {
                edges[distanceAdd].edgeType = 'd';
                disEdges.push_back(edges[distanceAdd]);
                travel += edges[distanceAdd].distance;
            }

            Traverse(next, visited, output, travel);
        }
        else
        {
            distanceAdd = FindEdges(currentAirport,next);
            if(distanceAdd != -1)
            {
                QQueue<QString> tempOutput;
                QVector<QString> tempVect;
                tempOutput = output;
                //convert to vector
                while(!tempOutput.empty())
                {
                    tempVect.push_back(tempOutput.front());
                    tempOutput.pop_front();
                }
                int currentIndex = -1;
                int nextIndex = -1;
                for (int z = 0; z < tempVect.size(); z++)
                {
                    if (currentAirport == FindAirport(tempVect[z]))
                    {
                    currentIndex = z;
                    }
                    if (next == FindAirport(tempVect[z]))
                    {
                    nextIndex = z;
                    }
                }

                 //Forward edge - if next is a greater index (more deep indescendants than current)

                if (currentIndex < nextIndex)
                {
                    edges[distanceAdd].edgeType = 'f';
                }

                else
                {
                    if(currentIndex - nextIndex == 1)	//CROSS EDGE
                    {
                        edges[distanceAdd].edgeType = 'c';
                    }
                    else //Back edge - if next is a lesser index(earlier ancestor than current)
                    {
                        edges[distanceAdd].edgeType = 'b';
                    }
                }
            }//end if
        }//end else
    }//end forloop
}

void GraphDS::DisplayEdges()
{
    int total, count, i;
    //backEdges		disEdges
    total = count = 0;
qDebug() << "Displaying all "<< edges.size() <<" edges & its types:\nDiscovery Edges:\n";
    for(int i = 0 ; i < disEdges.size(); i++)
    {
        qDebug() << "\t" << airports[disEdges[i].pointA].name << " to " << airports[disEdges[i].pointB].name << " (" << disEdges[i].pointA << "," << disEdges[i].pointB << ")" << endl;
        total += disEdges[i].distance;
    }

    qDebug() << "Number of Discovery Edges: "<< disEdges.size()<< endl;
    qDebug() << "Total Distance: " << total << endl <<endl;

    qDebug() << "Cross Edges:\n"; count = 0;
    for(i = 0 ; i < edges.size(); i++)
    {
        //cout << "Discovery Edge: " << airports[disEdges[i].pointA].name << " to " << airports[disEdges[i].pointB].name << "(" << disEdges[i].pointA << "," << disEdges[i].pointB << ")" << endl;
        if(edges[i].edgeType == 'c')
        {
            qDebug() << "\t" << airports[edges[i].pointA].name << " to " << airports[edges[i].pointB].name << " (" << edges[i].pointA << "," << edges[i].pointB << ")" << endl;
            count++;
        }
    }
    qDebug() << "Number of Cross Edges: "<< count<< endl << endl;

    qDebug() << "Back Edges:\n"; count = 0;
    for(i = 0 ; i < edges.size(); i++)
    {
        //cout << "Discovery Edge: " << airports[disEdges[i].pointA].name << " to " << airports[disEdges[i].pointB].name << "(" << disEdges[i].pointA << "," << disEdges[i].pointB << ")" << endl;
        if(edges[i].edgeType == 'b')
        {
            qDebug() << "\t" << airports[edges[i].pointA].name << " to " << airports[edges[i].pointB].name << " (" << edges[i].pointA << "," << edges[i].pointB << ")" << endl;
            count++;
        }
    }
    qDebug() << "Number of Back Edges: "<< count<< endl << endl;

    qDebug() << "Foward Edges:\n"; count = 0;
    for(i = 0 ; i < edges.size(); i++)
    {
        //cout << "Discovery Edge: " << airports[disEdges[i].pointA].name << " to " << airports[disEdges[i].pointB].name << "(" << disEdges[i].pointA << "," << disEdges[i].pointB << ")" << endl;
        if(edges[i].edgeType == 'f')
        {
            qDebug() << "\t" << airports[edges[i].pointA].name << " to " << airports[edges[i].pointB].name << " (" << edges[i].pointA << "," << edges[i].pointB << ")" << endl;
            count++;
        }
    }
    qDebug() << "Number of Foward Edges: "<< count<< endl << endl;

}

QString GraphDS::DisplayBFS(QString startingLoc)
{
    int currentAirport = FindAirport(startingLoc);
    int citiesTravelled = 1;
    QString output = "";


    if(currentAirport != -1)
    {	// Airport is found
        //Any Initializations
        QVector<bool> visit (numVertex, false); // flag that is parallel with airports vector
        QVector<int>levelBFS(numVertex, 0);
        QQueue<int> BFS;
        int level, refPoint, addIndex, j;
        int travelled = 0;
        for(int i = 0 ; i < airports.size(); i++)
            refSort(i);

        //resets the edge types to a back edge
        for(int i = 0 ; i < edges.size(); i++)
            edges[i].edgeType = 'b';
        disEdges.clear();

        //The Traversal
        level = 0;
        levelBFS[currentAirport] = 0;
        BFS.push_back(currentAirport);
        visit[currentAirport] = true;
        output += "BFS Trip. Starting trip at ";
        output += airports[currentAirport].name + " --> ";

        while(!BFS.empty())//loop ends when the tranversal visits all cities
        {   qDebug() << " @ "<< airports[currentAirport].name;
            for( j = 0 ; j < airports[currentAirport].ref.size(); j++)
            {	//Look thru all the current airport's refs
                refPoint = airports[currentAirport].ref[j];

                if(!visit[refPoint] )
                {
                    output += airports[refPoint].name;
                    citiesTravelled++;
                    if(j+1 < airports[currentAirport].ref.size())
                        output += " --> ";
                    BFS.push_back(refPoint);
                    levelBFS[refPoint] = levelBFS[currentAirport] + 1;
                    visit[refPoint] = true;

                    //mark edge
                    addIndex = FindEdges(currentAirport,refPoint);
                    if(addIndex != -1)
                    {
                        edges[addIndex].edgeType = 'd';
                        disEdges.push_back(edges[addIndex]);
                        travelled += edges[addIndex].distance;
                    }

                }
//                else
//                {
//                    addIndex = FindEdges(currentAirport,refPoint);
//                    if(addIndex != -1)
//                        edges[addIndex].edgeType = 'b';

//                }

            }//end for-loop

            BFS.pop_front();
            if(!BFS.empty())
            currentAirport = BFS.first();


        }


        int maxlevel = levelBFS[0];


        for(int a = 1; a < levelBFS.size(); a++)
        {
            if(maxlevel < levelBFS[a])
                maxlevel = levelBFS[a];
        }
        QVector<int> levelMatrix[maxlevel+1]; //for marking BFS levels

        output += "\n\nDisplaying BFS " + QString::number(maxlevel) + " levels: ";
        for(int a = 0; a <= maxlevel; a++)//at level a
        {
             output += "\nLevel " + QString::number(a) + ": ";
            for(int b = 0; b < levelBFS.size(); b++)//scans all the levels
            {
                if(levelBFS[b] == a)
                {
                    levelMatrix[a].push_back(b);
                    output += airports[b].name + ", ";
                }
            }


        }

         output += "\nCities visited: " + QString::number(citiesTravelled) + "\n\n";
         output += "Total Distance = " + QString::number(travelled) + "\n\n";


//        //Creating Cross Edges
//        for(int a = 0; a <= maxlevel; a++)//at level a
//        {
//            for(int b = 1; b < levelMatrix[a].size(); b++)//at level a
//            {
//                ConnectAirports(levelMatrix[a][0],levelMatrix[a][b], 0, 'c');
//            }
//        }

//        DisplayEdges();

    }
    else output = "Could not find the airport.\n";

    return output;
}

void GraphDS::reverseGraph()
{
    int temp;
    qDebug() << "Reversing Edges:\n";
    for(int i = 0; i < edges.size(); i++)
    {
        //swap(edges[i].pointA, edges[i].pointB);

        temp = edges[i].pointA;
        edges[i].pointA = edges[i].pointB;
        edges[i].pointB = temp;
    }

    for(int i = 0; i < airports.size(); i++)
    {
        airports[i].ref.clear();
        airports[i].ref.resize(0);
        for(int x = 0; x < edges.size(); x++)
        {
            if(edges[x].pointA == i)
            {
                airports[i].ref.push_back(edges[x].pointB);
            }
        }

    }

}
