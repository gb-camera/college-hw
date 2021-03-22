// File: stats.cpp
// Class implemented: statistician

// Michael Dinh - CISP 430 (Huang) - Spring 2020

#include "stats.h" //Header
#include <cassert> //Required for assert function
#include <iostream> //Header dependency

namespace CISP430_A1{
    statistician::statistician(){
        //Initialize all values to 0
        count = 0;
        total = 0;
        largest = 0;
        tiniest = 0;
    }
    void statistician::next(double r){
        //Add r to the total
        total += r;
        //Use a branch to avoid misreads of smallest/largest value with initialized 0
        //If the count is 0, only 1 value is in the sequence collectively, meaning that value is both the maximum and the minimum
        if(count == 0){
            tiniest = r;
            largest = r;
        }
        //If the count is 1 or greater, another value is entering the sequence, meaning that a value can no longer be both a max. and a min., so the function should branch accordingly
        else if(r < tiniest && count != 0){
            tiniest = r;
        }
        else if(r > largest && count != 0){
            largest = r;
        }
        //Increase the count by 1
        count += 1;
    }
    void statistician::reset(){
        //Reset all values to initialized state
        count = 0;
        total = 0;
        largest = 0;
        tiniest = 0;
    }
    double statistician::mean() const{
        //Assert required here
        assert(length() > 0);
        //Mean is sum of values divided by number of values
        double mean = total / count;
        return mean;
    }
    double statistician::minimum() const{
        //Assert required here
        assert(length() > 0);
        return tiniest;
    }
    double statistician::maximum() const{
        //Assert required here
        assert(length() > 0);
        return largest;
    }
    statistician operator +(const statistician& s1, const statistician& s2){
        //Special conditions if one of the stat. objects are empty
        if (s1.length() == 0){
            return s2;
        }
        if (s2.length() == 0){
            return s1;
        }
        //Create a new object and transfer values as appropriate
        statistician results;
        results.count = s1.count + s2.count;
        results.total = s1.total + s2.total;
        //Branch to choose an appropriate minimum value
        if(s1.tiniest < s2.tiniest){
            results.tiniest = s1.tiniest;
        }
        else{
            results.tiniest = s2.tiniest;
        }
        //Branch to choose an appropriate maximum value
        if(s1.largest > s2.largest){
            results.largest = s1.largest;
        }
        else{
            results.largest = s2.largest;
        }
        return results;
    }
    statistician operator *(double scale, const statistician& s){
        
        //Special condition if the stat. object is empty
        if(s.length() == 0){
            return s;
        }
        //Again, create a new object and transfer values as appropriate
        statistician results;
        //Two branches depending on if the scalar is positive or negative
        //If given a positive (or 0) scalar, simply scale all appropriate values by the scalar
        if(scale >= 0){
            results.count = s.count;
            results.total = s.total * scale;
            results.tiniest = s.tiniest * scale;
            results.largest = s.largest * scale;
            return results;
        }
        //If given a negative scalar, swap the minimum and maximum values
        else if(scale < 0){
            results.count = s.count;
            results.total = s.total * scale;
            results.tiniest = s.largest * scale;
            results.largest = s.tiniest * scale;
            return results;
        }
        //Default return to avoid error
        else{
            return results;
        }
    }
    bool operator ==(const statistician& a1, const statistician& a2){
        //Special condition if lengths are not equal
        if(a1.length() != a2.length()){
            return false;
        }
        //Special condition if both stat. objects are empty
        if(a1.length() == 0 && a2.length() == 0){
            return true;
        }
        //Otherwise lengths are equal, so other values should be checked
        else{
            return ((a1.mean() == a2.mean()) && (a1.sum() == a2.sum()) && (a1.minimum() == a2.minimum()) && (a1.maximum() == a2.maximum()));
        }
    }
}