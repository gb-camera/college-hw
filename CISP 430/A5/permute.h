#pragma once
//Michael Dinh - Assignment 5 - CISP 430 - Huang (Spring 2020)
//File: permute.h
//Classes provided: permute (stores two strings, permuting the first and storing all possibilites into a linked list) and node (for the linked list)

//Node class items:
//Constructor: Node(string data, Node *p)
//	Postcondition: A node object is initialized with the data string passed and is linked to another node, p.
//Public member: Node* linkAdv()
//	Postcondition: Returns the linked node.
//Public member std::string getData()
//	Postcondition: Returns node's associated data.

//Permute class items:
//Constructor: Permute(string first, string second)
//	Postcondition: A permute object is initialized, with its' string members defined. permutation() is then called to handle the 
//	remaining operations.
//Destructor: ~Permute()
//	Postcondition: All nodes are deleted.
//Public member: void permutation()
//	Precondition: The permute object in question must be initialized.
//	Postcondition: All possible permutations of the first string are stored in the linked list, and total is updated with the
//	total number of permutations. This must be done recursively.
//Public member: void print()
//	Postcondition: All elements in the linked list are pushed to the terminal.
//Private member: void swapLetters(int char1, int char2)
//	Postcondition: Two characters' positions have been swapped.
//Private member: void permuteHelper(int position)
//	Helper function for the recursive permutation function.

#ifndef __DINHA5__
#define __DINHA5__

#include <iostream>

class Node {
public:
	//Constructor
	Node(std::string data, Node* p) { this->data = data; this->p = p; }
	Node* linkAdv() { return p; }
	std::string getData() { return data; }
private:
	std::string data;
	Node* p;
};

class Permute {
public:
	Permute(std::string first, std::string second);
	void permutation();
	void print();
private:
	void swapLetters(int char1, int char2);
	void permuteHelper(int position);
	Node* firstNode, * lastNode;
	std::string firstString, secondString;
	int total;
};

#endif