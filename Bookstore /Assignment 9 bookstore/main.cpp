//*************************************************************************
//
// main.cpp
// CSCI 241 Assignment 9
//
// Created by Hamzah Subhani (z2010017)
//
//*************************************************************************

#include <iostream>
#include "book_store.h"

using std::cout;
using std::endl;

int main()
{
    book_store store;

    store.read_books("/Applications/CS projects/Assignment 9 bookstore/Assignment 9 bookstore/books.txt");

    store.print();

    cout << endl;

    store.process_orders("/Applications/CS projects/Assignment 9 bookstore/Assignment 9 bookstore/orders.txt");

    cout << endl;

    store.print();

    return 0;
}
