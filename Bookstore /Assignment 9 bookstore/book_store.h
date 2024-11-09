//
//  book_store.h
//  Assignment 9 bookstore
//
//  Created by hamzah subhani on 10/8/24.
//
#ifndef BOOK_STORE_H
#define BOOK_STORE_H
#include "book.h"
using namespace std;
class book_store
{
private:
    book books[30];
    int numbooks;
    
public:
    book_store();
    void read_books(string);
    void process_orders(string);
    void print();
    void sort_isbn();
    friend class book;
    int binary_search (book [], int, string);

};



#endif
