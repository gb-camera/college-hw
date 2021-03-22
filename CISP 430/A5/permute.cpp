//Michael Dinh - Assignment 5 - CISP 430 - Huang (Spring 2020)
//Implementation of permute class

#include "permute.h"
#include <string>
using namespace std;

//Constructor
Permute::Permute(std::string first, std::string second) {
	firstString = first;
	secondString = second;
	firstNode = lastNode = NULL;
	total = 0; //permutation() will handle this
	permutation();
}

//Permutation wrapper
void Permute::permutation() {
	//If the total != 0, permutation() has already been called for the object
	//If the first and second strings are empty, there exists no possible permutation
	//In both cases we can simply return
	if (total > 0 || (firstString == "" && secondString == "")) { return; }
	//Otherwise we can proceed
	else { permuteHelper(0); }
}

//Print function
void Permute::print() {
	//Create an iterator to traverse the linked list
	Node* printIterator = firstNode;

	//Print the header to the specifications of the test program
	cout << "String 1 for this object is: " << firstString << endl;
	cout << "String 2 for this object is: " << secondString << endl;
	//First possible case: no permutation at all
	if (total == 0) { cout << "There is no permutation."; }
	//Otherwise permutation exists
	else {
		cout << "The total possible permutation is " << total << endl;
		//If only one possibility, print "That is:"
		if (total == 1) { cout << "That is:"; }
		//Otherwise, print "They are:"
		else { cout << "They are:"; }
	}

	//Print the actual list
	//The specifications are as follows:
	//	- If total < 100: the permutations are printed four to a row
	//	- Else: the permutations are printed nine to a row

	//Determine row count
	unsigned int rowCount;
	if (total < 100) { rowCount = 4; }
	else { rowCount = 9; }
	//Initialize a counter to keep track of which element we're on in the row
	int counter = -1;
	//Iterate until we hit the end of the list
	while (printIterator != NULL) {
		//Increment the counter
		++counter;
		//Example for four rows: First element is 0, second is 1, third is 2, fourth is 3
		//If we hit element #4, we've hit the first element of our second row, and so we must line break
		if ((counter % rowCount) == 0) { cout << endl; }
		cout << printIterator->getData() << secondString << " "; //Print the permutation and append the second string
		printIterator = printIterator->linkAdv(); //Advance the iterator
	}
}

//Swap function
void Permute::swapLetters(int char1, int char2) {
	//Simple char swap function
	char temp = firstString[char1];
	firstString[char1] = firstString[char2];
	firstString[char2] = temp;
}

//Permutation outline
//The total # of permutations for any given string is n! (n factorial), where n is the number of letters in the string
//Given a three letter string, total # of permutations is 3! = 3 * 2 * 1 = 6

//Example: "cat"
//Three initial possibilities: First letter doesn't get swapped, first letter swapped for second letter, first letter swapped for third (1 <-> 1, 1 <-> 2, 1 <-> 3)
//cat, act, tac

//Two following possibilities: Second letter doesn't get swapped, second letter gets swapped for third letter (2 <-> 2, 2 <-> 3)
//Branch 1 "cat": cat, cta
//Branch 2 "act": act, atc
//Branch 3 "tac": tac, tca

//One following possibility: Third letter doesn't get swapped (3 <-> 3)
//The results of the prior are the results here: cat, cta, act, atc, tac, tca

//For the recursive function: n initial operations, then n - 1, then so on and so forth until we hit 1 operation (in which no letters are swapped)

//For reference:
//	- 1! = 1 (one branch, no swaps)
//	- 2! = 2 (two branches, one swap each/max)
//	- 3! = 6 (three branches, two swaps each/max)
//	- 4! = 24 (four branches, three swaps each/max)
//	- 5! = 120 (five branches, four swaps each/max)
//	- 6! = 720 (six branches, five swaps each/max)

//permuteHelper function
void Permute::permuteHelper(int position) {
	//Exit condition if all swaps have been performed (i.e. a permutation has been completed)
	if (position == firstString.length()) {
		firstNode = new Node(firstString, firstNode); //Insert new permutation at the head
		if (total == 0) { lastNode = firstNode; } //If the list was previously empty, first element does double duty
		++total; //Increment total
	}
	else { //Keep swapping otherwise
		for (int i = position; i < firstString.length(); ++i) {
			swapLetters(position, i); //Swap next possible character
			permuteHelper(position + 1); //Continute until the end of the string
			swapLetters(position, i); //Backtrack the swap
		}
	}
}