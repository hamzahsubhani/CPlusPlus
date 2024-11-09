//***************************************************************************
//
//  book.cpp
//  CSCI 241 Assignment 9 - Bookstore
//
//  Created by Hamzah Subhani (Z2010017)
//
//***************************************************************************

#include "book.h" // Using header file which has declarations for member functions and constructor

/* book
 *
 * Initializes 4 private data members from the book class to "none" and "default" before reading input.
 *
 * @param none
 *
 * @return nothing
 *
 * @note This is the default constructor.
 *
 */

book::book()
{
    isbn = "None";
    title = "None";
    price = 0.0;
    quantity = 0;
}

/* book (alternate constructor)
 *
 * Initializes 4 private data members to the parameters of this constructor.
 *
 * @param const string& isbn - reference to string constant ISBN number
 * @param const string& title - reference to string constant title of book
 * @param float price - price of the book
 * @param int quantity - quantity of books in stock
 *
 * @return nothing
 *
 * @note Uses this-> to provide distinction between parameters and member variables.
 *
 */

book::book(const string& isbn, const string& title, float price, int quantity)
{
    this->isbn = isbn; // this-> will be used for distinction between local and member variables
    this->title = title;
    this->price = price;
    this->quantity = quantity;
}

/* get_isbn
 *
 * Returns the isbn member variable.
 *
 * @param none
 *
 * @return string - ISBN number
 *
 * @note Returns the DATA MEMBER, not to be confused with the parameter of the default constructor.
 *
 */

string book::get_isbn()
{
    return isbn;
}

/* get_price
 *
 * Returns the price member variable.
 *
 * @param none
 *
 * @return float - price in float data type
 *
 * @note Returns the DATA MEMBER, not to be confused with the parameter of the default constructor.
 *
 */

float book::get_price()
{
    return price;
}

/* fulfill_order
 *
 * Uses logic to determine whether the order can be fulfilled based on the book quantity.
 *
 * @param int quantity - representing ship quantity
 *
 * @return int - quantity of this book that the bookstore is actually able to ship at this time.
 *
 */

int book::fulfill_order(int quantity)
{
    int shipquantity; // Variable to represent how much will actually be shipped

    if (quantity < 0) // Cannot ship books if none are asked for
    {
        shipquantity = 0;
        return shipquantity;
    }
    else if (quantity <= this->quantity) // If amount ordered is less than or equal to what is available in stock
    {
        shipquantity = quantity;
        this->quantity -= quantity; // Change stock based on this order
        return shipquantity;
    }

    shipquantity = this->quantity;
    this->quantity = 0;
    return shipquantity;
}

/* print
 *
 * Prints the contents of each book to the console.
 *
 * @param none
 *
 * @return nothing
 *
 */

void book::print()
{
    cout << setw(14) << left << isbn;
    cout << setw(44) << left << title;
    cout << setw(5) << right << fixed << setprecision(2) << price;
    cout << setw(6) << right << quantity << endl;
}
