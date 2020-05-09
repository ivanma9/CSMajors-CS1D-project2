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
    else if(startIndex == -1)
        qDebug() << "Could not find the start airport." << startPort << " to " << endPort;
    else if(endIndex == -1)
        qDebug() << "Could not find the end airport." << endPort << " from " << startPort;
    else
        qDebug() << "Could not find the airports.";



}
void GraphDS::ConnectAirports(int startIndex, int endIndex, int distance, char type)
{
    if(FindEdges(startIndex, endIndex) == -1)
    {
        edges.push_back(Arcs(distance, startIndex, endIndex, tolower(type)));
        numEdges++;
    }
    else
        qDebug() << "\tEdge already exist";


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
QList<TableOutput> GraphDS::DisplayDFS(QString startingAt)
{
    int startIndex = FindAirport(startingAt);
    int refSize, citiesTravelled;
    QList<TableOutput> output;

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

////Displaying the trip
//output += "DFS Trip. Starting trip at ";

        refSize = ports.size();
        //PRINTS the vertex
        for(citiesTravelled = 0 ; citiesTravelled < refSize; citiesTravelled++)
        {
            output.push_back(TableOutput(ports.front(),0));
            ports.pop_front();
        }
        //TOTAL distance
        output.push_back(TableOutput("Total Distance",travelled));


//output << "\n\nCities visited: " + QString::number(citiesTravelled) + "\n";
//reachable = citiesTravelled == numVertex;
//        if(citiesTravelled == numVertex)
//            qDebug() << "\t***This is POTENTIALLY a strongly connected graph! It visits all " << numVertex << " vertices***\n"<< endl;
//        else
//            qDebug() << "\t***This is potentially NOT a strongly connected graph! It only can visit " << citiesTravelled << " vertices, starting from " << airports[startIndex].name << ".\n***";


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

QList<TableOutput> GraphDS::DisplayBFS(QString startingLoc)
{
    int currentAirport = FindAirport(startingLoc);
    int citiesTravelled = 1;
    QList<TableOutput> output;
    QString temp;


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
//levelBFS[currentAirport] = 0;
        BFS.push_back(currentAirport);
        visit[currentAirport] = true;
//output += "BFS Trip. Starting trip at ";
//output << airports[currentAirport].name + " --> ";

        while(!BFS.empty())//loop ends when the tranversal visits all cities
        {   qDebug() << " @ "<< airports[currentAirport].name;
            for( j = 0 ; j < airports[currentAirport].ref.size(); j++)
            {	//Look thru all the current airport's refs
                refPoint = airports[currentAirport].ref[j];

                if(!visit[refPoint] )
                {
                    output.push_back(TableOutput(airports[refPoint].name,0));
                    citiesTravelled++;
                    BFS.push_back(refPoint);
//levelBFS[refPoint] = levelBFS[currentAirport] + 1;
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
        //TOTAL distance
        output.push_back(TableOutput("Total Distance",travelled));


        //OLD PRINTING BELOW
//        int maxlevel = levelBFS[0];
//        for(int a = 1; a < levelBFS.size(); a++)
//        {
//            if(maxlevel < levelBFS[a])
//                maxlevel = levelBFS[a];
//        }
//        QVector<int> levelMatrix[maxlevel+1]; //for marking BFS levels
////output << "Displaying BFS " + QString::number(maxlevel) + " levels: ";
//        for(int a = 0; a <= maxlevel; a++)//at level a
//        {
////output += "Level " + QString::number(a) + ": ";
//            for(int b = 0; b < levelBFS.size(); b++)//scans all the levels
//            {
//                if(levelBFS[b] == a)
//                {
//                    levelMatrix[a].push_back(b);
//                    output << airports[b].name;
//                }
//            }
//        }
//output += "\nCities visited: " + QString::number(citiesTravelled) + "\n\n";
//        //Creating Cross Edges
//        for(int a = 0; a <= maxlevel; a++)//at level a
//        {
//            for(int b = 1; b < levelMatrix[a].size(); b++)//at level a
//            {
//                ConnectAirports(levelMatrix[a][0],levelMatrix[a][b], 0, 'c');
//            }
//        }
//        DisplayEdges();

    }// if(currentAirport != -1) // airport not found
    else qDebug() << "Could not find the airport.\n";

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


// A structure to represent a node in adjacency list
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head; // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode {
    int v;
    int key;
};

// Structure to represent a min heap
struct MinHeap {
    int size; // Number of heap nodes present currently
    int capacity; // Capacity of min heap
    int* pos; // This is needed for decreaseKey()
    struct MinHeapNode** array;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int key)
{
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// A utilit function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        // The nodes to be swapped in min heap
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int key)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its key value
    minHeap->array[i]->key = key;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap* minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

// A utility function used to print the constructed MST
//QString GraphDS::printArr(int arr[], int arrWeight[], int n)
//{
//    QString output;
//    int totalMileage = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        totalMileage += arrWeight[i];
//        output += airports[arr[i]].name + " - " + airports[i].name + "\t\t\t\t\tMileage:  " + QString::number(arrWeight[i]) + '\n';
//    }
//    return output + "\n\n Total Mileage: " + QString::number(totalMileage);
//}


// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
QList<TableOutput> GraphDS::PrimMST()
{
    QList<TableOutput> output;

    //intializing graph
    struct Graph * graph = createGraph(numVertex);
    qDebug() << numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        addEdge(graph, edges[i].pointA, edges[i].pointB, edges[i].distance);
    }


    int V = graph->V; // Get the number of vertices in graph
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut

    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap)) {
        // Extract the vertex with minimum key value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    int totalMileage = 0;
    for (int i = 1; i < V; ++i)
    {
        totalMileage += key[i];
        output.push_back(TableOutput((airports[parent[i]].name + " - " +airports[i].name), key[i]));
    }
    output.push_back(TableOutput( "Total Mileage: " ,totalMileage));

    return output;
}

QList<TableOutput> GraphDS::Djikstra(QString startStadium)
{
    QList<TableOutput> output;

    int src = FindAirport(startStadium);

    //intializing graph
    struct Graph * graph = createGraph(numVertex);
    qDebug() << numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        addEdge(graph, edges[i].pointA, edges[i].pointB, edges[i].distance);
    }
    int V = graph->V;// Get the number of vertices in graph
    int dist[V];      // dist values used to pick minimum weight edge in cut

    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for (int v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    // Make dist value of src vertex as 0 so that it is extracted first
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                                          pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;

                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    int totalMileage = 0;
    for (int i = 0; i < V; ++i)
    {
        totalMileage += dist[i];
        output.push_back(TableOutput((airports[i].name), dist[i]));
    }
    output.push_back(TableOutput( "Total Mileage: " ,totalMileage));

    return output;
}
