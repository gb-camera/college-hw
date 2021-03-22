//Michael Dinh - CISP 430 - Lab 9 - Huang (Spring 2020)
//Header file: queueADT.h 
//Added comments
 
#ifndef H_queueADT
#define H_queueADT

//Virtual base class, so all of the following functions are templates 
//for use in a different class (namely the linkedQueue class)

template <class Type>
class queueADT 
{
public:
    virtual bool isEmptyQueue() const = 0;
    virtual bool isFullQueue() const = 0;
    virtual void initializeQueue() = 0;
    virtual Type front() const = 0;
    virtual Type back() const = 0;
    virtual void addQueue(const Type& queueElement) = 0;
    virtual void deleteQueue() = 0;
};

        
#endif