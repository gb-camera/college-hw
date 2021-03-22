//Michael Dinh - CISP 430 - Lab 8 - Huang (Spring 2020)
//Driver file for the binaryTree and binarySearchTree classes

//Given specifications:
//1. Declare an integer bSearchTreeType object.
//2. Allow user to input numbers or -999 to end the inputting.
//3. The inputted numbers are stored in the bSearchTreeType object.
//4. Display the bSearchTreeType object’s nodes in inorder.
//5. Display the bSearchTreeType object’s nodes in preorder.
//6. Display the bSearchTreeType object’s nodes in postorder.
//7. Display the object’s height.
//8. Display the object’s number of nodes.
//9. Display the object’s number of leaves.

#include <iostream>
#include "binarySearchTree.h"
using namespace std;

int main() {
	//Initialize the search tree
	bSearchTreeType<int> h;
	//Start the program dialogue
	cout << "Enter numbers, ending with -999:" << endl;
	//Initialize an int variable for input
	int userInput = 0;
	//We want to keep adding nodes to the tree while there is still input and the current input isn't -999
	while (cin >> userInput && userInput != -999) { //This method will ignore all whitespace, so one-line input or multiple line input is valid
		//Insert the node into the tree
		h.insert(userInput);
	}
	cout << endl;
	//Perform an inorder traversal display
	cout << "Tree nodes in inorder: ";
	h.inorderTraversal();
	cout << endl;
	//Perform a preorder traversal display
	cout << "Tree nodes in preorder: ";
	h.preorderTraversal();
	cout << endl;
	//Perform a postorder traversal display
	cout << "Tree nodes in postorder: ";
	h.postorderTraversal();
	cout << endl;
	//Display the tree's height
	cout << "Tree Height: " << h.treeHeight() << endl;
	//Display the tree's node count
	cout << "Number of Nodes: " << h.treeNodeCount() << endl;
	//Display the tree's leaves count
	cout << "Number of Leaves: " << h.treeLeavesCount() << endl;
	//Program end
	cout << endl;
	system("PAUSE");
	return 0;
}