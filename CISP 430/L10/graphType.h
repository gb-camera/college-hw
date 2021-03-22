//Michael Dinh - Lab 10 - CISP 430 - Huang (Spring 2020)
//File: graphType.h
//Class definition of graphType

#ifndef DINHL10
#define DINHL10

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

class graphType {
public:
    bool isEmpty() const;
    //isEmpty returns true or false depending on the state of the graph's size. If graphSize =
    //0, the graph is empty, and true is returned; otherwise the function returns false.
    void createGraph();
    //createGraph will create a graph based on text file CISP430V4L10.txt, located at the 
    //same directory as the program utilizing this class. Otherwise, an error message is pushed,
    //and the function does nothing.
    void clearGraph();
    //clearGraph simply clears the graph object by resetting the 2D vector and size value.
    void printGraph() const;
    //printGraph prints the graph object by printing the vector's horizontal index (the vertex),
    //and then printing each element of the associated adjacency list vector for each vertex / index.
    void breadthFirstTraversal();
    //Performs a breadth first traversal of the graph object for each vertex in order, starting
    //from index 0 until all vertexes have been registered.
    graphType(int size = 0);
    //Constructor. Default size value is 0. Sets size variables and resizes 2D vector graph.
    ~graphType();
    //Destructor. Calls clearGraph.
protected:
	int graphSize;
	vector<vector<int>> graph; //Use a vector of vectors for adjacency list graph
private:
    void bft(int v, vector<bool> &visited);
    //Helper function for BFT function.
};
#endif