//pqueue1.cpp - pqueue1.h Implementation File
//Implements the PriorityQueue class using a linked list
//Michael Dinh - CISP 430 - Assignment 4 - Huang (Spring 2020)

#include "pqueue1.h" //Header file

//Constructor
PriorityQueue::PriorityQueue() {
	//Initialize the queue with zero items
	many_nodes = 0;
	head_ptr = NULL;
}

//Copy constructor
PriorityQueue::PriorityQueue(const PriorityQueue& source) {
	//Special case if the source queue is empty
	if (source.head_ptr == NULL) {
		many_nodes = 0;
		head_ptr = NULL;
	}
	//Otherwise we need to copy the list
	else {
		//First we make a new list
		head_ptr = new Node;
		head_ptr->link = NULL;
		//No toolkit functions; use iterators to copy
		Node* dest = head_ptr;
		Node* sour = source.head_ptr;
		//Loop through the source and create new nodes to match in the destination
		for (size_t i = 0, nodes = source.many_nodes; i < nodes - 1; ++i) {
			//Copy all of the non-pointer private members
			dest->data = sour->data;
			dest->priority = sour->priority;
			//Create a new node
			dest->link = new Node;
			//Advance the iterators
			dest = dest->link;
			sour = sour->link;
		}
		//Once we hit the end, we don't need to make another node
		//We only need to copy over non-pointer data
		dest->data = sour->data;
		dest->priority = sour->priority;
		dest->link = NULL;
	}
	//Finally set the # of nodes
	many_nodes = source.many_nodes;
}

//Destructor
PriorityQueue::~PriorityQueue() {
	//We need to iterate through the queue and deallocate memory
	Node *prev, *current = head_ptr;
	while (current != NULL) { //Until we iterate past the queue...
		prev = current; // Store the node to be deleted
		current = current->link; //Advance the stored node
		delete prev; //Delete the non-advanced node
	}
}

//Public members
void PriorityQueue::insert(const Item& entry, unsigned int priority) {
	//We want to store the items in the queue in order of priority
	//Iterate through the queue until we reach an appropriate place to insert our node
	Node* before, * insert, * after;
	before = NULL;
	after = head_ptr;
	//Check the priority of each node until we find the appropriate location
	while ((after != NULL) && (priority <= after->priority)) {
		before = after;
		after = after->link;
	}

	//Four possibilities: our list is empty (and thus we make a new head node),
	//the item to insert has highest priority (and thus we insert it before the head),
	//the item to insert has lowest priority (and thus we insert at the end),
	//or the item has average priority (and thus we insert it between two nodes)
	//Cases 1 and 2 are special cases, while cases 3 and 4 are standard insertion procedure

	if (before == NULL) { //First iterator never changed
		//Either no head or need to insert before head
		if (after == NULL) { //If our head_ptr led us to null, we have no head
			//Create the head
			head_ptr = new Node;
			head_ptr->link = NULL;
			insert = head_ptr;
		}
		else { //Otherwise the head_ptr led us to another node, so we need to insert before the head
			before = new Node;
			before->link = head_ptr;
			head_ptr = before;
			insert = head_ptr;
		}
	}
	else { //Otherwise the nodes have led us to locations where we can do standard inserts
		insert = new Node;
		before->link = insert;
		insert->link = after;
	}
	//Since our insert node was purposefully left blank, we can now fill it with given data
	insert->data = entry;
	insert->priority = priority;
	++many_nodes; //Finally increment the node count
}

PriorityQueue::Item PriorityQueue::get_front() {
	//We need to check if the size is greater than zero
	if (many_nodes > 0) {
		//Since we're taking the node of highest priority, and since our list
		//is already in order of greatest to lowest priority, we simply retrive
		//the head node's data and then delete it
		Node* head = head_ptr;
		head_ptr = head_ptr->link; //Advance the head
		Item value = head->data; //Get the data to return
		delete head; //Delete the previous head
		--many_nodes; //Decrement node count
		return value; //Return the value
	}
	//Otherwise return 0 as a default case
	return 0;
}

//Overloaded operator
void PriorityQueue::operator =(const PriorityQueue& source) {
	//As usual, deal with self-assignment
	if (this == &source) { return; }
	//We need to delete the destination's queue
	Node* sour, * dest;
	dest = head_ptr;
	while (dest != NULL) {
		sour = dest; //Store node to delete
		dest = dest->link; //Advance stored node
		delete sour; //Delete stored node
	}
	//Either the list is empty or the list has items
	if (source.head_ptr == NULL) {
		//If our source was empty, simply set the head pointer to null
		head_ptr = NULL;
	}
	//Otherwise we need to copy all elements
	else {
		dest = head_ptr = new Node; //Make a new list
		sour = source.head_ptr; //Set iterators
		//Loop through the source and create new nodes to match
		for (size_t i = 0, nodes = source.many_nodes; i < nodes - 1; ++i) {
			//Copy non-pointer values
			dest->data = sour->data;
			dest->priority = sour->priority;
			//Make the next node
			dest->link = new Node;
			//Advance the iterators
			dest = dest->link;
			sour = sour->link;
		}
		//Again, once we hit the end we need to stop making nodes
		dest->data = sour->data;
		dest->priority = sour->priority;
		dest->link = NULL;
	}
	//Finally set # of nodes;
	many_nodes = source.many_nodes;
}