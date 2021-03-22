//File: sequence2.cpp
//Class implemented: sequence

//Michael Dinh - CISP 430 (Huang) - Spring 2020

#include <cassert> //Required for assert function
#include <algorithm> //Required for copy function
#include "sequence2.h" //Header

namespace CISP430_A2{
    //Constructor
    sequence::sequence(size_type entry){
        //Allocate memory and set capacity based on the value of entry (either based on user input or the default argument which is the CAPACITY constant of 30), then set used to 0
        data = new value_type[entry];
        capacity = entry;
        used = 0;
    }
    //Copy constructor
    sequence::sequence(const sequence& entry){
        //Check if copying to self
        if(this != &entry){
            //Copy data from source to destination
            //Allocate memory based on source, then copy all data from source
            data = new value_type[entry.capacity];
            std::copy(entry.data, entry.data + entry.used, data);
            //Copy other private member functions from source to destination
            capacity = entry.capacity;
            used = entry.used;
            //If there is an item active in the source, it should be active in the destination as well
            if(entry.is_item()){
                current_index = entry.current_index;
            }
        }
    }
    //Modification member functions are as follows
    //Start function
    void sequence::start(){
        //Check if sequence is valid (i.e. the capacity should be greater than 0)
        if(size() > 0){
            //If valid, initialize current index to 0
            current_index = 0;
        }
    }
    //Advance function
    void sequence::advance(){
        //Check if the sequence is currently active (i.e. there exists an active "current" item)
        assert(is_item());
        //If active, advance the current index by 1
        ++current_index;
    }
    //Insert function
    void sequence::insert(const value_type& entry){
        //Check if the sequence is at capacity first
        if(size() == capacity){
            //If the sequence is at capacity, resize the sequence
            resize(capacity + CAPACITY);
        }
        //Check if the sequence is not active
        if(!is_item()){
            //If not active, set the current index to 0 to insert at the beginning of the sequence
            current_index = 0;
        }
        //Since we want the item to be inserted BEFORE the current item for this function, every item up to the current one inclusive should be moved to the right by one
        for(size_type i = used; i > current_index; --i){
            data[i] = data[i - 1];
        }
        //The new item will take the place of the current item since we're inserting it in its' place
        data[current_index] = entry;
        //Increment used by one since there is a new element
        ++used;
    }
    //Attach function
    void sequence::attach(const value_type& entry){
        //Again, check if the sequence is at capacity first
        if(size() == capacity){
            //Again, if the sequence is at capacity, resize the sequence
            resize(capacity + CAPACITY);
        }
        //Again, check if the sequence is not active
        if(!is_item()){
            //If not active, set the current index to used - 1 to attach at the end of the sequence
            current_index = used - 1;
        }
        //Advance the current index by 1 to attach
        ++current_index;
        //Since we want the item to be attached AFTER the starting item for this function, every item up to the new current item inclusive should be moved to the right by one
        for(size_type i = used; i > current_index; --i){
            data[i] = data[i - 1];
        }
        //The new item will take the place of the new current item since we're attaching it in its' place
        data[current_index] = entry;
        //Increment used by one since there is a new element
        ++used;
    }

    //Remove current function
    void sequence::remove_current(){
        //Check if there is a current active item
        assert(is_item());
        //Since we want to remove the current item, every item to its right should be moved over by one, and the one to its immediate right should replace it
        for(size_type i = current_index; i < used - 1; ++i){
            data[i] = data[i + 1];
        }
        //Decrement used by one since an element was removed
        --used;
    }
    //Resize function
    void sequence::resize(size_type size){
        //Check if the intended capacity to resize is greater than the original capacity
        if(size > used){
            //Create a new array of the user defined size
            value_type *newData = new value_type[size];
            //Copy all data from the original array to the new array
            std::copy(data, data + used, newData);
            //Delete the original array now that all values are copied
            delete [] data;
            //Assign the new array to data and adjust capacity appropriately
            data = newData;
            capacity = size;
        }
    }
    //Operator overloads are as follows
    void sequence::operator =(const sequence& entry){
        //Check for self-assignment
        if(this == &entry){
            return;
        }
        //Create a new array to copy source data over
        value_type *newData = new value_type[entry.capacity];
        //Copy over the data
        std::copy(entry.data, entry.data + entry.used, newData);
        //Delete the original array
        delete [] data;
        //Assign the new data to data
        data = newData;
        //Set all other private members to that of the source array
        used = entry.used;
        capacity = entry.capacity;
        //If there is an item active in the source, it should be active here as well
        if(entry.is_item()){
            current_index = entry.current_index;
        }
        //Else if not, just set the current index to the end of the array
        else{
            current_index = used;
        }
    }
    //Constant member functions are as follows
    //Size function
    //Need to use the scope resolution operator for size_type
    sequence::size_type sequence::size() const{
        //Since size is equal to number of elements in the sequence, i.e. number of spaces in the array used, just return used
        return used;
    }
    //Is item function
    bool sequence::is_item() const{
        //Since this should check whether or not the current index has an active item, just check if the index is within range from 0 to used
        return(current_index >= 0 && current_index < used);
    }
    //Current function
    //Need to use the scope resolution operator for value_type
    sequence::value_type sequence::current() const{
        //Since this function simply returns the active item's data, first make sure that there IS an active item
        assert(is_item());
        //If true, return the data
        return data[current_index];
    }
    //Destructor
    sequence::~sequence(){
        //Nothing special here, just delete the data
        delete [] data;
    }
}