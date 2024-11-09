//***************************************************************************
//
//  book_store.cpp
//  CSCI 241 Assignment 9 - Bookstore
//
//  Created by Hamzah Subhani (Z2010017)
//
//***************************************************************************

#include "book_store.h" // header files containing declarations for private data members and public member functions
#include <fstream> // needed for opening files
#include <cstdlib> // used for exit (-1)

/* book_store
 *
 * Initializes the number of books data member to 0.
 *
 * @param none
 *
 * @return nothing
 *
 * @note This is the default constructor.
 *
 */

book_store::book_store()
{
    numbooks = 0;
}

/* sort_isbn
 *
 * Uses insertion sort to sort the ISBN numbers in ascending order.
 *
 * @param none
 *
 * @return nothing
 *
 * @note This will be called in the read_books function.
 *
 */

void book_store::sort_isbn()
{
    for (int i = 1; i < numbooks; i++)
    {
        book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].get_isbn() > key.get_isbn())
        {
            books[j + 1] = books[j];
            j = j - 1;
        }
        books[j + 1] = key;
    }
}

/* binary_search
 *
 * Uses the binary search approach to search through a sorted array of books
 * to see if the ISBN numbers match.
 *
 * @param book books[] - array of book objects
 * @param int numbooks - number of books
 * @param string target_isbn - ISBN to match
 *
 * @return The index of the book if a matching ISBN is found; returns -1 if not found.
 *
 * @note The books array must be sorted by ISBN before calling this function
 * (call sort_isbn).
 *
 */

int book_store::binary_search(book books[], int numbooks, string target_isbn)
{
    int low = 0;
    int high = numbooks - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        string mid_isbn = books[mid].get_isbn();
        
        if (target_isbn == mid_isbn)
        {
            return mid;
        }
        if (target_isbn < mid_isbn)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return -1;
}

/* read_books
 *
 * Reads book data from a file, storing each book's ISBN, title, price, and
 * quantity in the array. After reading all the books, it sorts the array
 * by ISBN using the sort_isbn() function.
 *
 * @param string file - the name of the file containing book information
 * (ISBN, title, price, quantity).
 *
 * @return nothing.
 *
 */

void book_store::read_books(string file)
{
    ifstream infile(file);
    
    if (infile.fail())
    {
        cout << "Error: File did not open" << endl;
        exit(-1);
    }
    
    string isbn, title, price_str, quantity_str;
    float price;
    int quantity;
    
    // Loop as long as there is more data to read
    while (getline(infile, isbn, ':'))
    {
        getline(infile, title, ':');
        getline(infile, price_str, ':');
        getline(infile, quantity_str);
        
        try
        {
            price = stod(price_str); // Convert the price to a float
        }
        catch (exception &e)
        {
            cout << "Error with stod: expecting float: " << price_str << endl;
            break;
        }

        try
        {
            quantity = stoi(quantity_str); // Convert the quantity to an int
        }
        catch (exception &e)
        {
            cout << "Error with stoi: expecting integer: " << quantity_str << endl;
            break;
        }

        book new_book(isbn, title, price, quantity);
        books[numbooks] = new_book;
        numbooks++; // Increment the number of books
    }

    infile.close();
    sort_isbn();
}

/* process_orders
 *
 * Reads order data from a file and displays after meeting book inventory conditions.
 *
 * @param string file - the name of the file containing order information
 * (order_number, ISBN, quantity).
 *
 * @return nothing.
 *
 * @note If the ISBN is not found, an error message is displayed.
 *
 */

void book_store::process_orders(string file)
{
    ifstream filein(file);
    
    if (filein.fail())
    {
        cout << "Error: Orders File did not open" << endl;
        exit(-1);
    }
    
    cout << left << "Order Listing" << endl << endl;
    string order_number, isbn, quantity_str;
    int quantity;
    
    while (getline(filein, order_number, ' '))
    {
        getline(filein, isbn, ' ');
        getline(filein, quantity_str);
        
        try
        {
            quantity = stoi(quantity_str); // Convert quantity string to an int
        }
        catch (exception &e)
        {
            cout << "Error with stoi: expecting integer: " << quantity_str << endl;
            break;
        }
        
        int found = binary_search(books, numbooks, isbn);
        
        if (found != -1)
        {
            int fulfilled = books[found].fulfill_order(quantity);
            
            if (fulfilled > 0)
            {
                double ordertotal = fulfilled * books[found].get_price();
                cout << "Order #" << order_number << ": "
                     << "ISBN " << isbn << ", "
                     << fulfilled << " of " << quantity
                     << " shipped, order total $" << ordertotal << endl;
            }
        }
        else
        {
            cout << "Order #" << order_number << ": "
                 << "error - ISBN " << isbn << " does not exist" << endl;
        }
        
        filein.eof();
    }
}

/* print
 *
 * Displays the content of the current book inventory, showing ISBN, title,
 * price, and available quantity.
 *
 * @param nothing.
 *
 * @return nothing.
 *
 */

void book_store::print()
{
    cout << left << "Book Inventory Listing" << endl << endl;
    cout << setw(14) << left << "ISBN"
         << setw(44) << left << "Title"
         << setw(5) << right << "Price"
         << setw(8) << right << "Qty." << endl;
    cout << endl;
    
    for (int i = 0; i < numbooks; i++)
    {
        books[i].print();
    }
}
