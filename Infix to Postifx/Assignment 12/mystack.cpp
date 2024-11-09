//***************************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 11
//  Implementations of member functions and testing the output.
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************

#include "mystack.h"
using std::boolalpha;

/* mystack (Default constructor)
*
* initializes an empty stack.
*
* @param none
*
* @return nothing
*/

mystack::mystack()
{
    // default intializing for the three private data members.
    siz = 0;
    capac = 0;
    stack = nullptr;
}

/* mystack (Copy constructor)
*
* creates a new stack as a copy of an existing one.
*
* @param const mystack& x - reference to const mystack object, stack to copy from.
*
* @return nothing
*/

mystack::mystack(const mystack& x)
{
    siz = x.siz;
    capac = x.capac;

    if (capac == 0)
    {
        stack = nullptr;
    }
    else
    {
        stack = new char[capac]; // allocate memory for the new array
        for (size_t i = 0; i < siz; i++)
        {
            stack[i] = x.stack[i]; // copy each element from the original array
        }
    }
}

/* ~mystack (Destructor)
*
* releases the memory allocated for the stack.
*
* @param none
*
* @return none
*/

mystack::~mystack()
{
    delete[] stack;
}

/* empty
*
* checks if the stack is empty based on condition.
*
* @param none
*
* @return boolean value true if the stack is empty, false otherwise.
*/

bool mystack::empty() const
{
    return siz == 0; // only retuns true if stack is empty.
}

/* size
*
* retrieves the current size of the stack.
*
* @param none
*
* @return mystack data member siz - number of elements in the stack
*/

size_t mystack::size() const
{
    return siz; // private data member
}

/* capacity
*
* retrieves the current capacity of the stack.
*
* @param none
*
* @return mystack data member capac - capacity of the stack.
*/

size_t mystack::capacity() const
{
    return capac; // private data member
}

/* operator<<
*
* overloads output stream operator to print the stack.
*
* @param ostream& os - the output stream to write to.
*
* @param const mystack& obj - reference to a const mystack object, the stack to be printed.
*
* @return ostream data member os - modified output stream.
*/

ostream& operator<<(ostream& os, const mystack& obj)
{
    
    if (obj.size() == 0) // check if stack is empty
    {
        return os;
    }

    for (size_t i = 0; i < obj.size(); i++) // iterate through stack
    {
        os << obj.stack[i];

        if (i < obj.size() - 1)
        {
            os << ", "; // add commas between elements
        }
    }

    return os;
}

/* reserve
*
* reserves memory for at least the specified number of elements.
*
* @param size_t n - the new capacity to reserve.
*
* @return nothing
*/

void mystack::reserve(size_t n)
{
    if (n <= capac)
    {
        return;
    }

    capac = n;
    char* temp; // creates temporary pointer and array
    temp = new char[capac]; // create new array to store n or capac elements.
    size_t i = 0;
    while (i < siz)
    {
        temp[i] = stack[i]; // the elements of stack are now the same elements of temp
        i++;
    }

    delete[] stack; // deletes stack and its elements.
    stack = temp; // redirects pointer to new array
}

/* operator= (overloaded assignment operator)
*
* copies one stack to another.
*
* @param const mystack& x - reference to const mystack object, the stack to be assigned.
*
* @return *this - reference to the assigned stack.
*/

mystack& mystack::operator=(const mystack& x)
{
    if (this == &x) // if assignment is the same, no more work is needed
    {
        return *this;
    }

    delete[] stack; // delete existing stack to prevent memory leak
    this->siz = x.siz; // sets actual data to x's data
    this->capac = x.capac;

    if (x.capac == 0)
    {
        stack = nullptr;
    }
    else
    {
        stack = new char[capac]; // allocate memory for the new array
        for (size_t i = 0; i < siz; i++)
        {
            stack[i] = x.stack[i]; // copy each element from the original array
        }
    }

    return *this;
}

/* push
*
* adds an element to the top of the stack.
*
* @param char value - the value to be added.
*
* @return nothing.
*/

void mystack::push(char value)
{
    if (siz == capac)
    {
        if (capac == 0)
        {
            reserve(1); // make another space current if capacity is 0
        }
        else
        {
            reserve(capac * 2); // reserve the current capacity times 2.
        }
    }

    stack[siz] = value; // copies value into stack array as the new top item
    siz++; // increments stack size.
}

/* top
*
* Retrieves the top element of the stack.
*
* @param none
*
* @return reference to the top element.
*/

const char& mystack::top() const
{
    return stack[siz - 1];
}

/* pop
*
* removes top element from the stack.
*
* @param none
*
* @return nothing
*/

void mystack::pop()
{
    siz = siz - 1;
}

/* clear
*
* clears the stack
*
* @param none
*
* @return nothing
*/

void mystack::clear()
{
    siz = 0;
}

/* main
*
* tests various functionalities of the mystack class
*
* @param none
*
* @return 0 to indicate successful completion of the program.
*/

/*
int main()
{
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    cout << boolalpha;

    const mystack s1;
    
    cout << "Testing empty stack\n\n";
    
    cout << "stack: " << s1 << endl;
    cout << "capacity(): " << s1.capacity() << endl;
    cout << "size(): " << s1.size() << endl;
    cout << "empty(): " << s1.empty() << endl << endl;

    mystack s2;
    
    cout << "Testing push() and top()\n\n";
    for (int i = 0; i < 7; i++)
        s2.push(letters[i]);
    
    cout << "stack: " << s2 << endl;
    cout << "capacity(): " << s2.capacity() << endl;
    cout << "size(): " << s2.size() << endl;
    cout << "empty(): " << s2.empty() << endl;
    cout << "top(): " << s2.top() << endl << endl;

    mystack s3;

    cout << "Testing pop() and top()\n\n";
    for (int i = 0; i < 7; i++)
        s3.push(letters[i]);
    
    for (int i = 0; i < 3; i++)
        s3.pop();
    
    cout << "stack: " << s3 << endl;
    cout << "capacity(): " << s3.capacity() << endl;
    cout << "size(): " << s3.size() << endl;
    cout << "empty(): " << s3.empty() << endl;
    cout << "top(): " << s3.top() << endl << endl;

    mystack s4;

    cout << "Testing clear()\n\n";
    for (int i = 0; i < 12; i++)
        s4.push(letters[i]);

    cout << "stack: " << s4 << endl;
    cout << "capacity(): " << s4.capacity() << endl;
    cout << "size(): " << s4.size() << endl;
    cout << "empty(): " << s4.empty() << endl << endl;

    s4.clear();
    
    cout << "stack: " << s4 << endl;
    cout << "capacity(): " << s4.capacity() << endl;
    cout << "size(): " << s4.size() << endl;
    cout << "empty(): " << s4.empty() << endl << endl;

    cout << "Testing copy constructor...\n\n";

    cout << "Testing copying empty stack\n\n";

    mystack s5;
    mystack s6(s5);
    
    cout << "stack: " << s5 << endl;
    cout << "capacity(): " << s5.capacity() << endl;
    cout << "size(): " << s5.size() << endl;
    cout << "empty(): " << s5.empty() << endl << endl;

    cout << "stack: " << s6 << endl;
    cout << "capacity(): " << s6.capacity() << endl;
    cout << "size(): " << s6.size() << endl;
    cout << "empty(): " << s6.empty() << endl << endl;

    cout << "Testing copying non-empty stack\n\n";

    for (int i = 0; i < 12; i++)
        s5.push(letters[i]);

    cout << "stack: " << s5 << endl;
    cout << "capacity(): " << s5.capacity() << endl;
    cout << "size(): " << s5.size() << endl;
    cout << "empty(): " << s5.empty() << endl << endl;

    mystack s7(s5);

    cout << "stack: " << s7 << endl;
    cout << "capacity(): " << s7.capacity() << endl;
    cout << "size(): " << s7.size() << endl;
    cout << "empty(): " << s7.empty() << endl << endl;

    cout << "Testing for shallow copy\n\n";

    s5.clear();

    cout << "stack: " << s5 << endl;
    cout << "capacity(): " << s5.capacity() << endl;
    cout << "size(): " << s5.size() << endl;
    cout << "empty(): " << s5.empty() << endl << endl;

    cout << "stack: " << s7 << endl;
    cout << "capacity(): " << s7.capacity() << endl;
    cout << "size(): " << s7.size() << endl;
    cout << "empty(): " << s7.empty() << endl << endl;

    cout << "Testing copy assignment operator...\n\n";

    cout << "Testing assigning empty stack to empty stack\n\n";

    mystack s8;
    mystack s9;
    
    cout << "stack: " << s8 << endl;
    cout << "capacity(): " << s8.capacity() << endl;
    cout << "size(): " << s8.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    cout << "stack: " << s9 << endl;
    cout << "capacity(): " << s9.capacity() << endl;
    cout << "size(): " << s9.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    cout << "Testing assigning non-empty stack\n\n";

    for (int i = 0; i < 12; i++)
        s8.push(letters[i]);

    cout << "stack: " << s8 << endl;
    cout << "capacity(): " << s8.capacity() << endl;
    cout << "size(): " << s8.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    mystack s10;
    for (int i = 12; i < 20; i++)
        s10.push(letters[i]);

    cout << "stack: " << s10 << endl;
    cout << "capacity(): " << s10.capacity() << endl;
    cout << "size(): " << s10.size() << endl;
    cout << "empty(): " << s10.empty() << endl << endl;

    s10 = s8;

    cout << "stack: " << s8 << endl;
    cout << "capacity(): " << s8.capacity() << endl;
    cout << "size(): " << s8.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    cout << "stack: " << s10 << endl;
    cout << "capacity(): " << s10.capacity() << endl;
    cout << "size(): " << s10.size() << endl;
    cout << "empty(): " << s10.empty() << endl << endl;
    
    cout << "Testing for shallow copy\n\n";

    s8.clear();

    cout << "stack: " << s8 << endl;
    cout << "capacity(): " << s8.capacity() << endl;
    cout << "size(): " << s8.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    cout << "stack: " << s10 << endl;
    cout << "capacity(): " << s10.capacity() << endl;
    cout << "size(): " << s10.size() << endl;
    cout << "empty(): " << s10.empty() << endl << endl;

    cout << "Testing chained assignment\n\n";
    s8 = s9 = s10;
    
    cout << "stack: " << s8 << endl;
    cout << "capacity(): " << s8.capacity() << endl;
    cout << "size(): " << s8.size() << endl;
    cout << "empty(): " << s8.empty() << endl << endl;

    cout << "stack: " << s9 << endl;
    cout << "capacity(): " << s9.capacity() << endl;
    cout << "size(): " << s9.size() << endl;
    cout << "empty(): " << s9.empty() << endl << endl;

    cout << "stack: " << s10 << endl;
    cout << "capacity(): " << s10.capacity() << endl;
    cout << "size(): " << s10.size() << endl;
    cout << "empty(): " << s10.empty() << endl;

    return 0;
}
*/



