//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//File: CISP430V4L9.cpp
//Added comments

#include <iostream>
#include <fstream>
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
	cout << "Depth First Traversal: ";
	
	//Perform the traversal (this function also prints results to the console)
	myGraph.depthFirstTraversal();
	
	//Ending sequence
	cout << endl <<endl;
	system("PAUSE");
	return 0;
}