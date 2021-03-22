//Header file: myStack.h
//Template definitions added
//Michael Dinh - CISP 430 - Lab 6 - Huang (Spring 2020)

#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;

//*************************************************************
// This class specifies the basic operation on a stack as an 
// array.
//*************************************************************

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>& otherStack); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0;

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //    otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //    otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem is
      //    added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //    terminates; otherwise, the top element of the stack
      //    is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top element is
      //    removed from the stack.

    bool operator==(const stackType<Type>& otherStack) const;

    stackType(int stackSize = 100); 
      //Constructor
      //Create an array of the size stackSize to hold 
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base address 
      //   of the array, stackTop = 0, and maxStackSize = stackSize

    stackType(const stackType<Type>& otherStack); 
      //Copy constructor

    ~stackType(); 
      //Destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //    elements is deleted.

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list; //pointer to the array that holds the stack elements

    void copyStack(const stackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and assigned
      //    to this stack.
};

//Template definitions are as follows

//Constructor
template <class Type>
stackType<Type>::stackType(int stackSize) {
    //Error validation; if stackSize < 0, use default case
    if (stackSize < 0) { maxStackSize = 100; }
    //Else stackSize is valid and should be assigned to maxStackSize
    else { maxStackSize = stackSize; };
    //The stack is utilizing static arrays so initialize a static array based on the given argument
    list = new Type[maxStackSize];
    //Initialize the stack
    stackTop = 0;
}

//Copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
    //Since this is copying otherStack to the target constructor, we can use our private copy function
    copyStack(otherStack);
}

//Destructor
template <class Type>
stackType<Type>::~stackType() {
    //Clear the array
    delete[] list;
}

//Public members
template <class Type>
void stackType<Type>::initializeStack() {
    //Set stackTop to 0
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const {
    //If stackTop = 0, stack is empty
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const {
    //If stackTop = maxStackSize, stack is full
    return(stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem) {
    //Check for stack being full (which will also check if the stack exists)
    if (isFullStack()) {
        cout << "Potential stack overflow! Returning." << endl;
        return;
    }
    //Add the newItem to the top of the stack, increment stackTop
    list[stackTop] = newItem;
    stackTop++;
}

template <class Type>
Type stackType<Type>::top() const {
    //Check for stack being empty (which will also check if the stack exists)
    //In this function alone, an empty stack terminates
    assert(!isEmptyStack());
    //If the assertion passes just return the element pointed to by stackTop
    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop() {
    //Check for stack being empty (which will also check if the stack exists)
    if (isEmptyStack()) {
        cout << "Stack is empty! Returning." << endl;
        return;
    }
    //We can simply decrement stackTop and ignore the previous top element
    stackTop--;
}

//Private member
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) {
    //Clear original array
    delete[] list;
    //Copy otherStack's parameters to target stack
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    //Make a new array using new parameters
    list = new Type[maxStackSize];
    //Copying otherStack to the target stack
    for (int i = 0; i < stackTop; ++i) {
        list[i] = otherStack.list[i];
    }
}

//Overloaded operators
template <class Type>
const stackType<Type>& stackType<Type>::operator= (const stackType<Type>& otherStack) {
    //Again, this is only copying one stack to another; use the private copyStack member
    //Self-assignment check
    if (this != &otherStack) { copyStack(otherStack); }
    return *this;
}

template <class Type>
bool stackType<Type>::operator== (const stackType<Type>& otherStack) const {
    //Two stacks are only equal if their arrays, stackTop, and maxStackSize parameters are equal
    //First check the non-dynamic members
    if (stackTop != otherStack.stackTop || maxStackSize != otherStack.maxStackSize) { return false; }
    //Now loop through each array and check if their members are equal
    for (int i = 0; i < stackTop; ++i) {
        if (list[i] != otherStack.list[i]) { return false; }
    }
    //If everything passes, return true
    return true;
}

#endif