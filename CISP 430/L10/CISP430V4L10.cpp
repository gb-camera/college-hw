//Michael Dinh - Lab 10 - CISP 430 -  Huang (Spring 2020)
//File: CISP430V4L10.cpp
//Driver file for graphType class

#include <iostream>
#include "graphType.h" 
using namespace std;

int main()
{
	//This is the main driver file
	//Initialize a graphType object with size 50
	graphType myGraph(50);

	//Call createGraph() to process the text file
	myGraph.createGraph();

	//Prepare for display output
	cout << endl << endl;
	cout << "Breadth First Traversal: ";

	//Perform the traversal (this function also prints results to the console)
	myGraph.breadthFirstTraversal();

	//Ending sequence
	cout << endl << endl;
	system("PAUSE");
	return 0;
}