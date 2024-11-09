#include "book.h"  // Include the header file for the book class
#include <iostream> // For input/output

using namespace std;

int main() {
    // Test the default constructor
    book default_book;  // Create a book using the default constructor
    cout << "Testing default constructor:" << endl;
    default_book.print();  // Print the details of the book
    cout << endl << endl;

    // Test the alternate constructor
    book custom_book("978-3-16-148410-0", "The C++ Programming Language", 59.99, 10);  // Create a book with parameters
    cout << "Testing alternate constructor:" << endl;
    custom_book.print();  // Print the details of the book
    cout << endl << endl;

    // Test the get_isbn() method
    cout << "Testing get_isbn() method:" << endl;
    cout << "ISBN: " << custom_book.get_isbn() << endl;
    cout << endl;

    // Test the get_price() method
    cout << "Testing get_price() method:" << endl;
    cout << "Price: $" << custom_book.get_price() << endl;
    cout << endl;

    // Test the fulfill_order() method (successful order)
    cout << "Testing fulfill_order() method (successful order):" << endl;
    int quantity_to_order = 5;
    int shipped_quantity = custom_book.fulfill_order(quantity_to_order);
    cout << "Ordered: " << quantity_to_order << ", Shipped: " << shipped_quantity << endl;
    cout << "Updated book info after fulfilling order:" << endl;
    custom_book.print();  // Print the updated details of the book
    cout << endl;

    // Test the fulfill_order() method (order more than available)
    cout << "Testing fulfill_order() method (ordering more than available stock):" << endl;
    quantity_to_order = 10;
    shipped_quantity = custom_book.fulfill_order(quantity_to_order);
    cout << "Ordered: " << quantity_to_order << ", Shipped: " << shipped_quantity << endl;
    cout << "Updated book info after fulfilling order:" << endl;
    custom_book.print();  // Print the updated details of the book
    cout << endl;

    return 0;  // Indicate successful execution
}
