//
//  book.h
//  Assignment 9 bookstore
//
//  Created by hamzah subhani on 10/8/24.
//
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <iomanip>
using namespace std;
class book
{
    string isbn;
    string title;
    float price;
    int quantity;
    
public:
    book();
    book(const string&, const string&, float, int);
    string get_isbn();
    float get_price();
    int fulfill_order(int);
    void print();
};

#endif
