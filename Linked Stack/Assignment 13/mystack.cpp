//***************************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 13
//
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************
#include "mystack.h"

/* mystack (Default constructor)
*
* initializes an empty stack
*
* @param none
*
* @return nothing
*/

mystack::mystack()
{
    stk_size = 0;
    topstack = nullptr;
}

/* clone
*
* initializes the current stack to be a copy of another stack.
*
* @param const mystack& x - const reference to the source mystack object to copy from
*
* @return nothing
*/

void mystack::clone(const mystack& x)
{
    topstack = nullptr; // start with empty stack
    node* last = nullptr;
    node* ptr = x.topstack;

    while (ptr != nullptr)
    {
        node* new_node = new node(ptr->value, nullptr); // allocate new node with node constructor

        if (last == nullptr)
        {
            topstack = new_node; // sets new node to top if its the first node
        }
        else
        {
            last->next = new_node; // set last node to new node
        }
        last = new_node; // move last to new node
        ptr = ptr->next; // move to next node in source stack
    }
}

/* mystack (Alternate constructor)
*
* initialize a new mystack object to the same values for all of its data members as the existing mystack object x
*
* @param const mystack& x - const reference to mystack object - object to copy data from
*
* @return nothing
*/

mystack::mystack(const mystack& x)
{
    topstack = nullptr;
    stk_size = x.stk_size;
    clone(x); // call clone to copy elements from x
}

/* empty
*
* checks if the stack is empty
*
* @param none
*
* @return bool - returns true if the stack is empty, otherwise false
*/

bool mystack::empty() const
{
    return stk_size == 0;
}

/* clear
*
* clears all elements from the stack, making it empty.
*
* @param none
*
* @return nothing
*/

void mystack::clear()
{
    while (!empty()) // while the stack is not empty
    {
        pop(); // remove the contents
    }
}

/* size
*
* returns the number of elements in the stack.
*
* @param none
*
* @return size_t - the number of elements in the stack
*/

size_t mystack::size() const
{
    return stk_size;
}

/* operator<<
*
* oytputs the contents of the stack using an overloaded output stream operator
*
* @param ostream& os - the output stream to write to
* @param const mystack& obj - the mystack object to output
*
* @return ostream& - reference to the output stream
*/

ostream& operator<<(ostream& os, const mystack& obj)
{
    if (obj.empty()) // check if the stack is empty
    {
        return os; // return the stream if empty
    }

    node* current = obj.topstack; // start from the top of the stack
    while (current != nullptr) //  go through linked list
    {
        os << current->value; // print the current node's value
        current = current->next; // move to next node
        
        if (current != nullptr) // only add a comma if there is a next node
        {
            os << ", "; // add comma and space
        }
    }
    return os; // return the stream (will be used for last element in stack which does not need comma)
}

/* push
*
* Adds a new element to the top of the stack.
*
* @param int value - the value to be pushed onto the stack
*
* @return nothing
*/

void mystack::push(int value)
{
    node* new_node = new node(value, topstack); // allocating new node with node constructor
    new_node -> value = value;
    new_node -> next = topstack;
    topstack = new_node; // new node is set to top of stack
    stk_size++; // increment stack size
}

/* top
*
* returns value at the top of the stack without removing it
*
* @param none
*
* @return const int& - reference to the value at the top of the stack
*/

const int& mystack::top() const
{
    return topstack->value; // return value of top node
}

/* pop
*
* removes the top element from the stack
*
* @param none
*
* @return nothing
*/

void mystack::pop()
{
    node* temp = topstack; // saves current top node in temp pointer
    topstack = topstack->next; // updates to point to next node
    delete temp; // delete temporar pointer
    stk_size--; // decrease stack size by 1
}

/* ~mystack
*
* destructor that clears the stack, freeing all allocated memory
*
* @param none
*
* @return nothing
*/

mystack::~mystack()
{
    clear(); // calls clear function
}

/* operator=
*
* overloads the assignment operator to assign one stack to another
*
* @param const mystack& x - const reference to the mystack object to copy
*
* @return mystack& - reference to the current object
*/

mystack& mystack::operator=(const mystack& x)
{
    if (this != &x) // if assignment is the same, no more work is needed
    {
        clear(); //clear current stack
    }

    stk_size = x.stk_size; // copy size form source stack
    clone(x); //copies elements from x

    return *this; // return reference to current object
}
