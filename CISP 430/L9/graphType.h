//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//File: graphType.h
//Added comments

#ifndef H_graph
#define H_graph

#include <iostream>
#include <fstream>
#include <iomanip> 
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

using namespace std;

class graphType
{
public:
    bool isEmpty() const;
	//isEmpty returns true or false depending on the state of the graph's size; if
    //0, the graph is empty and true is returned, otherwise the function returns false
    void createGraph();
    //createGraph will create a graph based on text file CISP430V4L9.txt, located at the 
    //same directory as the program utilizing this class. Otherwise, an error message is pushed,
    //and the function does nothing.
    void clearGraph();
    //clearGraph simply clears the graph object by calling destroyList for each linked list 
    //in the array.
    void printGraph() const;
    //printGraph prints the graph object by calling each array index's linked list's 
    //print function.
    void depthFirstTraversal();
    //Performs a depth first traversal of the graph object for each vertex in order, starting
    //from index 0 until all vertexes have been registered.
    void dftAtVertex(int vertex);
    //Performs a depth first traversal of the graph object starting from the specified vertex and
    //will only capture vertexes connected to it.
    void breadthFirstTraversal();
    //Performs a breadth first traversal of the graph object for each vertex in order, starting
    //from index 0 until all vertexes have been registered.
    graphType(int size = 0); 
    //Constructor. Default size value is 0.
    ~graphType();
    //Destructor. Calls clearGraph function.
protected:
    int maxSize;    
    int gSize;      
    unorderedLinkedList<int> *graph; 
private:
    void dft(int v, bool visited[]);
    //Helper function for both depth first traversal functions.
};

bool graphType::isEmpty() const
{
    //Simple return the state of gSize
    return (gSize == 0);
}

void graphType::createGraph()
{
    //Prepare for file read
    ifstream infile;
    char fileName[50];
    
    //Prepare appropriate input variables
    int index;
    int vertex;
    int adjacentVertex;

    //If data exists, we need to clear it before we create our new graph
    if (gSize != 0)	
        clearGraph();

    //Open the file for read
	infile.open("CISP430V4L9.txt");

    //If we can't read the file, throw an error and abort
    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    //Read the first line as the size of the graph
    infile >> gSize;	

    //Loop for each index of the graph
    for (index = 0; index < gSize; index++)
    {
        infile >> vertex; //Read the line's first value as the corresponding vertex
        infile >> adjacentVertex; //Then read the next value as an adjacent vertex

        while (adjacentVertex != -999) //If this vertex isn't the flag value...
        {
            graph[vertex].insertLast(adjacentVertex); //...insert it into the vertex's linked list
            infile >> adjacentVertex; //Read the next adjacent vertex value
        } 
    } 
    //Close the file
    infile.close();
} 

void graphType::clearGraph()
{
    int index;
    //Loop for each list in the graph object
    for (index = 0; index < gSize; index++)
        graph[index].destroyList(); //Clear all lists
    //Set gSize to 0
    gSize = 0;
} 


void graphType::printGraph() const
{
    int index;
    //Loop for each list in the graph object
    for (index = 0; index < gSize; index++)
    {
        cout << index << " ";
        graph[index].print(); //Call linked list print
        cout << endl;
    }

    cout << endl;
} 

void graphType::depthFirstTraversal()
{
    //Create an array of booleans for the DFT
    bool *visited; 
	visited = new bool[gSize];

    int index;

    //Initialize all bools in the array to false
    for (index = 0; index < gSize; index++) 
        visited[index] = false;
	
    //Loop for each list in the graph object
    for (index = 0; index < gSize; index++)	
        if (!visited[index]) //If the corresponding list in the visited array is false...
            dft(index,visited); //Perform DFT on it
    
    delete [] visited; //Return memory to the heap
} 

void graphType::dft(int v, bool visited[])
{
    visited[v] = true; //First make the corresponding bool in the visited array true
    cout << " " << v << " ";  //Print out the vertex

    linkedListIterator<int> graphIt; //Create an iterator to iterate through the vertex's adjacents

    //Loop through the adjacent vertexes
    for (graphIt = graph[v].begin(); graphIt != graph[v].end();
                                     ++graphIt)
    {
        int w = *graphIt; //Set w to the current vertex
        if (!visited[w]) //If the corresponding bool in visited is false...
            dft(w, visited); //...perform DFT on the vertex in question
    } 
} 

void graphType::dftAtVertex(int vertex)
{
    //Again, create an array of booleans for the DFT
    bool *visited;
    visited = new bool[gSize];
    //Initialize all bools in the array to false
    for (int index = 0; index < gSize; index++)
        visited[index] = false;
    //Start DFT from said vertex
    dft(vertex, visited);
    //Return memory to the heap
    delete [] visited;
} 


void graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue; //Create a queue for BFT
    //Create an array of bools for our BFT
    bool *visited;
    visited = new bool[gSize];
    //Initialize all bools to false
    for (int ind = 0; ind < gSize; ind++)
        visited[ind] = false;	

    //Create an iterator for each 
    linkedListIterator<int> graphIt;

    //For each list in the graph object...
    for (int index = 0; index < gSize; index++)
        if (!visited[index]) //If the corresponding bool is false...
        {
            queue.addQueue(index); //Push the vertex to the queue
            visited[index] = true; //Set visited bool to true
            cout << " " << index << " "; //Print the vertex

            while (!queue.isEmptyQueue()) //If the queue isn't empty...
            {
                int u = queue.front(); //Get the front object
                queue.deleteQueue(); //Delete the queue

                for (graphIt = graph[u].begin(); 
                     graphIt != graph[u].end(); ++graphIt) //Loop through adjacent vertices
                {
                    int w = *graphIt; //Set new int w to the current adjacent vertex
                    if (!visited[w]) //If the corresponding bool is false...
                    {
                        queue.addQueue(w); //Push the vertex to the queue
                        visited[w] = true; //Set visited bool to true
                        cout << " " << w << " "; //Print the vertex
                    }
                }
            } 
        }
	//Return memory to the heap
    delete [] visited;
} 

//Constructor
graphType::graphType(int size)
{
    maxSize = size; //Set maxSize to the passed size
    gSize = 0; //Set current gSize to 0 since the graph has yet to be created
    graph = new unorderedLinkedList<int>[size]; //Create a new unordered linked list of our passed size
}

//Destructor
graphType::~graphType()
{
    clearGraph(); //Simply call clearGraph
}

#endif