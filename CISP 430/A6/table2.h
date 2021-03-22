//table2.h
//Michael Dinh - CISP 430 - Assignment 6 - Huang (Spring 2020)
//Header file for chained hash table class

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>
#include "link2.h"

template <class RecordType>
class table {
public:
    //Member constant
    static const size_t TABLE_SIZE = 10;
    //Constructors / destructors
    table();
    table(const table& source);
    ~table();
    //Modification members
    void insert(const RecordType& entry);
    void remove(int key);
    void print(int index) const;
    void clear();
    //Overloaded operators
    void operator =(const table& source);
    //Constant members
    void find(int key, bool& found, RecordType& result) const;
    bool is_present(int key) const;
    size_t size() const { return total_records; }
private:
    Node<RecordType>* data[TABLE_SIZE];
    size_t total_records;
    //Helper members
    size_t hash(int key) const;
};

#include "table2.template"

#endif