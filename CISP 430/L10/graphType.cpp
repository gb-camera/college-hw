//Michael Dinh - Lab 10 - CISP 430 - Huang (Spring 2020)
//File: graphType.cpp
//Implementation of graphType class

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "graphType.h"
using namespace std;

//Constructor
graphType::graphType(int size) {
	graphSize = 0; //Graph is currently empty so set to 0
	graph.resize(size); //Resize our 2D vector to size
}

//Destructor
graphType::~graphType() {
	clearGraph();
}

//isEmpty
bool graphType::isEmpty() const {
	//Simply return the state of graphSize
	return (graphSize == 0);
}

//createGraph
void graphType::createGraph() {
	//Prepare for file read
	ifstream infile;
	//Prepare appropriate input variables
	int index, vertex, adjacentVertex;
	//Clear graph if preexisting data exists
	if (graphSize != 0) { graph.clear(); }
	//Open file for reading
	infile.open("CISP430V4L10.txt");
	//Throw error message and abort if no file / read error
	if (!infile) {
		cout << "Cannot open input file." << endl;
		return;
	}
	//Read the first line as the size of the graph
	infile >> graphSize;
	//Loop for each index of the graph
	for (index = 0; index < graphSize; ++index) {
		infile >> vertex; //Read the line's first value as the corresponding vertex
		infile >> adjacentVertex; //Then read the next value as an adjacent vertex
		while (adjacentVertex != -999) { //If adjacentVertex isn't the flag value...
			graph.at(vertex).push_back(adjacentVertex); //...insert it into the vertex's adjacency list
			infile >> adjacentVertex; //Read the next adjacent vertex value
		}
	}
	//Close the file
	infile.close();
}

//clearGraph
void graphType::clearGraph() {
	graph.clear(); //Reset the 2D vector
	graphSize = 0; //Reset graphSize
}

//printGraph
void graphType::printGraph() const {
	int index; //Int to keep track of horizontal
	vector<int>::const_iterator col; //Iterator for vertical traversal of vector
	//Traverse the 2D vector, outer loop handles rows
	for (index = 0; index < graphSize; ++index) {
		cout << index << ": "; //Get the index
		//Now, we need to traverse the 2D vector's columns / adjacency lists
		//Print each element using the dereference operator
		for (col = graph.at(index).begin(); col != graph.at(index).end(); ++col){ cout << *col << " "; }
		cout << endl; //Advance to the next console line for each row
	}
	cout << endl;
}

//breadthFirstTraversal
void graphType::breadthFirstTraversal() {
	//Initialize a vector of bools for BFT
	vector<bool> visited(graphSize, false);
	//Iterate for every vertex horizontally
	for (int i = 0; i < graphSize; ++i) {
		if (!visited.at(i)) { //If we haven't visited the current vertex...
			bft(i, visited); //...perform BFT on it
		}
	}
	//Clear visited
	visited.clear();
}

//bft
void graphType::bft(int v, vector<bool> &visited) {
	//Create a queue for BFT
	queue<int> queue;
	//Push the vertex to the queue, set the visited bool to true, and print the vertex
	queue.push(v);
	visited.at(v) = true;
	cout << " " << v << " ";
	//While the queue isn't empty...
	while (!queue.empty()) {
		int x = queue.front(); //Get the front object,
		queue.pop(); //...and the pop it from the queue
		//Now we need to traverse through this vertex's adjacency list
		vector<int>::const_iterator col = graph.at(x).begin(); //Make a vertical iterator
		for (col = graph.at(x).begin(); col != graph.at(x).end(); ++col) {
			int y = *col; //Get the current adjacent vertex
			if (!visited.at(y)) { //If the corresponding bool is false...
				queue.push(y); //Push the vertex to the queue
				visited.at(y) = true; //Set the visited bool to true
				cout << " " << y << " "; //Print the vertex
			}
		}
	}
}