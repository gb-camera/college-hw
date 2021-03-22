//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//File: linkedQueue.h
//Added comments and implemented copy constructor, overloaded = operator, and destructor
  
#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert> 
#include "queueADT.h"

using namespace std;

template <class Type>
class linkedQueueType: public queueADT<Type>
{
public:
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&); 
    //Overloaded = operator for the linked queue class.
    bool isEmptyQueue() const;
    //Checks if the queue is empty by returning the status of the head pointer.
    bool isFullQueue() const;
    //Checks if the queue is full. 
    //Currently just returns false for some reason?
    void initializeQueue();
    //Initializes the queue.
    Type front() const;
    //Precondition: queueFront is not null.
    //Returns the info found at queueFront.
    Type back() const;
    //Precondition: queueRear is not null.
    //Returns the info found at queueRear.
    void addQueue(const Type& queueElement);
    //Adds a node to the queue at the rear.
    void deleteQueue();
    //Precondition: The node is not empty.
    //"Pops" the front element of the queue, makes the second link the new head, and so on.
    //If the head was the only element in the queue, the queue is now empty.
    linkedQueueType(); 
    //Constructor for the linked queue class.
    //Sets both queueFront and queueRear to null.
    linkedQueueType(const linkedQueueType<Type>& otherQueue); 
    //Copy constructor for the linked queue class.
    ~linkedQueueType(); 
    //Destructor for the linked queue class.
private:
    nodeType<Type> *queueFront;  
    nodeType<Type> *queueRear;  
};

template<class Type>
linkedQueueType<Type>::linkedQueueType() 
{
    //Set both queueFront and queueRear to null
    queueFront = nullptr; 
    queueRear = nullptr;  
} 

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == nullptr); //Simply return the state of the queueFront pointer
} 

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} 

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    //Create temporary holder pointer
    nodeType<Type> *temp;
    //If queueFront isn't already null, we want to delete it (thus severing the other links)
    while (queueFront != nullptr)  
    {
        temp = queueFront;
        queueFront = queueFront->link;  
        delete temp;    
    }
    //Set queueRear to null
    queueRear = nullptr;  
} 

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    //Create and allocate a new node
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;  
    //Add non-pointer information and set the link to null
    newNode->info = newElement; 
    newNode->link = nullptr;  
    //If the front of the queue is already null, this will be the only element
    if (queueFront == nullptr) 
    {
        queueFront = newNode; 
        queueRear = newNode;
    }
    else //Otherwise we need to add it to the end of the queue
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != nullptr); //Make sure that the pointer is declared
    return queueFront->info; 
} 

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= nullptr); //Make sure that the pointer is declared
    return queueRear->info;
} 

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    //Create temporary holder pointer
    nodeType<Type> *temp;
    //If the queue isn't empty...
    if (!isEmptyQueue())
    {
        temp = queueFront;  //Set our temp to the front element
        queueFront = queueFront->link; //Advance the queue
        //Obliterate the temp pointer and delete the front element
        delete temp;    

        if (queueFront == nullptr) //If queueFront is null, that means our queue is now empty
            //So we should set the rear to null as well
            queueRear = nullptr;   
    }
    else //Otherwise the queue's already empty so don't do anything
        cout << "Cannot remove from an empty queue" << endl;
}

//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
    //We need to iterate through the queue and deallocate memory
    nodeType<Type>* prev, * current = queueFront;
    while (current != NULL) { //Until we iterate past the queue...
        prev = current; // Store the node to be deleted
        current = current->link; //Advance the stored node
        delete prev; //Delete the non-advanced node
    }
} 

//Overloaded operator
template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                    (const linkedQueueType<Type>& otherQueue)
{
    //This code asssumes that we have no member that tracks # of nodes, 
    //and that there exists a data member called "info" in each node (according to this header's other functions)

    //As usual, deal with self-assignment
    if (this == &otherQueue) { return; }
    //We need to delete the destination's queue
    nodeType<Type>* sour, * dest;
    dest = queueFront;
    while (dest != NULL) {
        sour = dest; //Store node to delete
        dest = dest->link; //Advance stored node
        delete sour; //Delete stored node
    }
    //Either the list is empty or the list has items
    if (otherQueue.queueFront == NULL) {
        //If our source was empty, simply set the head pointer to null
        queueFront = NULL;
    }
    //Otherwise we need to copy all elements
    else {
        dest = queueFront = new nodeType<Type>; //Make a new list
        sour = otherQueue.queueFront; //Set iterators
        //Loop through the source and create new nodes to match
        while(sour->link != NULL) {
            //Copy non-pointer values
            dest->info = sour->info;
            //Make the next node
            dest->link = new nodeType<Type>;
            //Advance the iterators
            dest = dest->link;
            sour = sour->link;
        }
        //Again, once we hit the end we need to stop making nodes
        dest->info = sour->info;
        dest->link = NULL;
    }
} 

//Copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
                 (const linkedQueueType<Type>& otherQueue) 
{
    //Again, this code asssumes that we have no member that tracks # of nodes, 
    //and that there exists a data member called "info" in each node (according to this header's other functions)

    //Special case if the source queue is empty
    if (otherQueue.queueFront == NULL) {
        queueFront = NULL;
    }
    //Otherwise we need to copy the list
    else {
        //First we make a new list
        queueFront = new nodeType<Type>;
        queueFront->link = NULL;
        //No toolkit functions; use iterators to copy
        nodeType<Type>* dest = queueFront;
        nodeType<Type>* sour = otherQueue.queueFront;
        //Loop through the source and create new nodes to match in the destination
        while(sour->link != NULL) {
            //Copy all of the non-pointer private members
            dest->info = sour->info;
            //Create a new node
            dest->link = new nodeType<Type>;
            //Advance the iterators
            dest = dest->link;
            sour = sour->link;
        }
        //Once we hit the end, we don't need to make another node
        //We only need to copy over non-pointer data
        dest->info = sour->info;
        dest->link = NULL;
    }
}

#endif
