//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//File: linkedList.h
//Added comments
 
#ifndef H_LinkedListType
#define H_LinkedListType
 
#include <iostream>
#include <cassert>

using namespace std;
 
//NodeType contains a data member "info" of a defined type, and then a link to another node.

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
public:
   linkedListIterator();
    //Constructor for the linked list iterator class.
   linkedListIterator(nodeType<Type> *ptr);
   //Copy constructor for the linked list iterator class.
   Type operator*();
   //Overloaded dereferencing operator for the linked list iterator class.
   //Simply returns the data member located at info.
   linkedListIterator<Type> operator++();    
   //Overloaded ++ operator for the linked list iterator class.
   //Advances the node link chain.
   bool operator==(const linkedListIterator<Type>& right) const; 
   //Overloaded == operator for the linked list iterator class.
   bool operator!=(const linkedListIterator<Type>& right) const; 
   //Overloaded != operator for the linked list iterator class.
private:
   nodeType<Type> *current; 
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr; //Set the current pointer to null since it hasn't been assigned yet
}

template <class Type>
linkedListIterator<Type>::
                  linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr; //Simply copy the source pointer to the current pointer
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info; //Simply return the info member to dereference
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()   
{
    //Advance the link
    current = current->link;
    //Return the newly advanced link
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==
               (const linkedListIterator<Type>& right) const
{
    return (current == right.current); //Simply return the comparison between the two pointers
}

template <class Type>
bool linkedListIterator<Type>::operator!=
                 (const linkedListIterator<Type>& right) const
{    return (current != right.current); //Simply return the comparison between the two pointers
}


template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
                         (const linkedListType<Type>&);  
    //Overloaded = operator for the linked list class.
    void initializeList(); 
    //Initializes list.
    bool isEmptyList() const;
    //Checks if the list is empty.
    void print() const;
    //Prints all data elements of the linked list.
    int length() const;
    //Returns the length of the linked list.
    void destroyList();
    //Destroys the list.
    Type front() const; 
    //Precondition: front is not null.
    //Returns the data member stored at front.
    Type back() const; 
    //Precondition: back is not null.
    //Returns the data member stored at back.
    virtual bool search(const Type& searchItem) const = 0;
    //Template function left undefined.
    virtual void insertFirst(const Type& newItem) = 0;
    //Template function left undefined.
    virtual void insertLast(const Type& newItem) = 0;
    //Template function left undefined.
    virtual void deleteNode(const Type& deleteItem) = 0;
    //Template function left undefined.
    linkedListIterator<Type> begin();
    //Creates a linked list iterator starting at the linked list's head pointer.
    linkedListIterator<Type> end();
    //Creates a linked list iterator starting at the linked list's rear pointer.
    linkedListType(); 
    //Constructor for the linked list class.
    linkedListType(const linkedListType<Type>& otherList); 
    //Copy constructor for the linked list class.
    ~linkedListType();   
    //Destructor for the linked list class.
protected:
    int count;   
    nodeType<Type> *first; 
    nodeType<Type> *last;  
private: 
    void copyList(const linkedListType<Type>& otherList); 
    //Copies a source linked list to a destination linked list.
};


template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return(first == nullptr); //Simply return whether or not the head pointer is null
}

template <class Type>
linkedListType<Type>::linkedListType() 
{
    //Set pointers to null
    first = nullptr;
    last = nullptr;
    //Set count to 0
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    //Iterate through the list with a different pointer and delete each node individually
    nodeType<Type> *temp;   
    while (first != nullptr)  
    {
        temp = first;        
        first = first->link; 
		delete temp;   
    }
    //Set the last pointer to null
    last = nullptr; 
    //Reset the count
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //Call destroyList
}

template <class Type>
void linkedListType<Type>::print() const
{
    //Iterate through the list with a different pointer
    nodeType<Type> *current; 
    current = first;    
    //While the iterator isn't null...
    while (current != nullptr) 
    {
        cout << current->info << " "; //Print out its' data member
        current = current->link; //Advance the link
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count; //Simply return count
}  

template <class Type>
Type linkedListType<Type>::front() const
{   
    assert(first != nullptr); //Make sure the first pointer is not null
    //Return first's info
    return first->info; 
}

template <class Type>
Type linkedListType<Type>::back() const
{   
    assert(last != nullptr); //Make sure the last pointer is not null
    //Return last's info
    return last->info; 
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first); //Create an LLI using the first pointer
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr); //Create an LLI using the last pointer (which will be null)
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList) 
{
    //Create a source iterator and a new node for copy assistance
    nodeType<Type> *newNode; 
    nodeType<Type> *current; 

    //Clear out the destination list
    if (first != nullptr) 
       destroyList();

    //If our source is empty, we don't need to do much
    if (otherList.first == nullptr) 
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    //Otherwise we need to copy the list
    else
    {
        //Set the iterator to the other list's header
        //Set destination's count to source's count
        current = otherList.first;                
        count = otherList.count;
        
        //Create a new head node
        first = new nodeType<Type>;  

        //Copy the source iterator to the current
        first->info = current->info; 
        first->link = nullptr;        
        
        //Make last equal to first
        last = first;              
        
        //Advance the iterator
        current = current->link;     
                                     
        //While our iterator hasn't reached the end...
        while (current != nullptr)
        {
            //Repeat the process using newNode as our insert
            newNode = new nodeType<Type>;  
            newNode->info = current->info; 
            newNode->link = nullptr;       
                                        
            last->link = newNode;  
            last = newNode;        
                                   
            current = current->link;   
                                       
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType() 
{
   destroyList(); //Simply call destroyList
}

template <class Type>
linkedListType<Type>::linkedListType
                      (const linkedListType<Type>& otherList)
{
   	first = nullptr; //Prepare for copy by making first null
    copyList(otherList); //Simply call copyList
}

        
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList)
{ 
    if (this != &otherList) //Self-assignment check
    {
        copyList(otherList); //Simply call copyList
    }
    //Return the new copy
    return *this; 
}

#endif
