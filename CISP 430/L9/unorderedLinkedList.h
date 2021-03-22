//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//File: unorderedLinkedList.h
//Added comments and made adjustments to avoid compile issues with VS2019

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;
 
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
	using linkedListType<Type>::first;
	using linkedListType<Type>::last;
    using linkedListType<Type>::count;

public:
    bool search(const Type& searchItem) const;
    //Searches the unordered linked list for a defined item of the user-defined type.
    //Returns true if found, and returns false if not found.
    void insertFirst(const Type& newItem);
    //Inserts a new node at the front of the linked list.
    void insertLast(const Type& newItem);
    //Inserts a new node at the end of the linked list.
    void deleteNode(const Type& deleteItem);
    //Deletes a specific node from the linked list.
};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    //Create an iterator and a bool
    nodeType<Type> *current; 
    bool found = false;
    //Set the iterator to the head
    current = first; 
    //Traverse through the list
    while (current != nullptr && !found)    
        if (current->info == searchItem) //If we find our man, set found to true
            found = true;
        else //Otherwise advance the link
            current = current->link; 
    //Return the bool
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    //Create a node to insert
    nodeType<Type> *newNode; 
    newNode = new nodeType<Type>; 
    //Set the node's information and insert it at the front
    newNode->info = newItem;    
    newNode->link = first;
    first = newNode;
    //Increase the count                      
    count++;
    //If our list was empty, set the node to also be last
    if (last == nullptr)
        last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    //Create a new node to insert
    nodeType<Type> *newNode; 
    newNode = new nodeType<Type>; 
    //Set the node's information
    newNode->info = newItem;  
    newNode->link = nullptr;     
    //If our list is empty, we can just set it as the head                          
    if (first == nullptr)
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else //Otherwise, insert at the end
    {
        last->link = newNode;
        last = newNode;
        count++;
    }
}


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    //Set two iterators and a bool
    nodeType<Type> *current; 
    nodeType<Type> *trailCurrent; 
    bool found;

    //Check if the list is empty first
    if (first == nullptr)     
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //If the head is the object to delete...
        {
            current = first; //Set current to first
            first = first->link; //Advance the list
            count--; //Reduce the count
            if (first == nullptr) //If the list is now empty, we should set last appropriately
                last = nullptr;
            delete current; //Return the memory to the heap
        }
        else //Otherwise we need to go node hunting
        {
            found = false; //Set the bool to false
            trailCurrent = first; //Set our trail to first...
            current = first->link; //...and our current to the next node
                                   
            //While we haven't reached the end and haven't found our man yet...
            while (current != nullptr && !found)
            {
                if (current->info != deleteItem) //If the item isn't the one to delete, advance the iterators
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else //Otherwise set found to true
                    found = true;
            }

            if (found) //If we've found our guy...
            {
                trailCurrent->link = current->link; //Fuse the nodes
                count--; //Decrement the count
                
                //If the last node is equal to the node for deletion...
                if (last == current)
                    last = trailCurrent; //Make the previous node the last node
                //Return memory to the heap
                delete current;  
            }
            else //Otherwise the node to find does not exist, so we can end our search
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }
    }
}


#endif
