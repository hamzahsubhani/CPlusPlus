//***************************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 11
//  Class header file which contain data members and method prototypes.
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstdlib> // used for size_t

using namespace std;

class mystack
{
private:
    // these data members will be utilized in the constructors and destructors.
    char* stack;
    size_t capac;
    size_t siz;
public:
    // the description for each of these member functions will be explained in mystack.cpp
    mystack();
    mystack(const mystack& );
    ~mystack();
    mystack& operator=(const mystack& );
    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    void clear();
    void reserve(size_t);
    const char& top() const;
    void push (char);
    void pop();
    friend ostream& operator<<(ostream& , const mystack& );
};













#endif
