//***************************************************************************
//
//  mylist.h
//  CSCI 241 Assignment 16
//
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cstdlib>
#include <stdexcept> // used for throwing errors

using namespace std;

template <class T> // make class an element of the template
class mylist;

template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&); // stream extraction operator for template

template <class T>
struct node
{
    T value; // data at node
    node<T>* next; // points ahead
    node<T>* prev; // points behind

    node(const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr)
    {
        // setting data members to parameters
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

template <class T>
class mylist
{
public:
    node<T>* l_front; // front of list
    node<T>* l_back; // back
    size_t list_size; // size of list

    mylist();
    ~mylist();
    mylist(const mylist<T>&);
    mylist<T>& operator=(const mylist<T>&);
    void clear();
    size_t size() const;
    bool empty() const;
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool operator==(const mylist<T>& rhs) const;
    bool operator<(const mylist<T>& rhs) const;
    friend ostream& operator<< <>(ostream& os, const mylist<T>&);
};

/* mylist (Constructor)
 *
 * initializes the front and back pointers to null and list size to 0.
 *
 * @param none
 *
 * @return nothing
 */

template <class T>
mylist<T>::mylist()
{
    l_front = nullptr;
    l_back = nullptr;
    list_size = 0;
}

/* ~mylist (Destructor)
 *
 * calls clear function to delete nodes and set pointers and list size to initial state.
 *
 * @param none
 *
 * @return nothing
 */

template <class T>
mylist<T>::~mylist()
{
    clear();
}

/* clear
 *
 * deletes nodes and sets front and back pointers and list size to initial state.
 *
 * @param none
 *
 * @return nothing
 */

template <class T>
void mylist<T>::clear()
{
    node<T>* curr = l_front; // temporary pointer to traverse and delete elements
    while (curr != nullptr)
       {
           node<T>* next_node = curr->next;
           delete curr;
           curr = next_node;
       }
       l_front = l_back = nullptr; //initial states
       list_size = 0;
}

/* operator = (copy assignment operator)
 *
 * checks for self assignment and copies data from existing object to parameter using push_back
 *
 * @param const mylist<T>& x - object to copy data to
 *
 * @return *this - current instance of class on which member function was called.
 */

template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
    if (this != &x)
    {
        clear();

        node<T>* ptr = x.l_front;

        while (ptr != nullptr)
        {
            push_back(ptr->value); // copies data for object x
            ptr = ptr->next;
        }
    }

    return *this; // returns object
}

/* operator = (equality overloaded operator)
 *
 * compares two mylist objects for equality
 *
 * @param const mylist<T>& rhs - object to compare with existing object
 *
 * @return false if the values and list sizes are not the same, otherwise true
 */

template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    if (list_size != rhs.list_size)
    {
        return false;
    }

    node<T>* ptr1 = l_front;
    node<T>* ptr2 = rhs.l_front;

    while (ptr1 != nullptr)
    {
        if (ptr1->value != ptr2->value)
        {
            return false; // If any values differ, the lists are not equal
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true; // if all conditions are met they are equal
}

/* operator < (less than overloaded operator)
 *
 * compares two mylist objects to see if one is less than the other
 *
 * @param const mylist<T>& rhs - object to compare with existing object
 *
 * @return true if existing objects, values and nodes are less than the right hand side, otherwise false
 */

template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
    node<T>* ptr = l_front; // temporary pointers to traverse original list and rhs list
    node<T>* ptr2 = rhs.l_front;

    while (ptr != nullptr && ptr2 != nullptr) // traverse list to see if one is less than the other
    {
        if (ptr->value > ptr2->value)
        {
            return false;
        }

        if (ptr->value < ptr2->value)
        {
            return true;
        }

        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    return (ptr == nullptr && ptr2 != nullptr);
}

/* mylist (copy assignment operator)
 *
 * compares two mylist objects to see if one is less than the other
 *
 * @param const mylist<T>& rhs - object to compare with existing object
 *
 * @return true if existing objects, values and nodes are less than the right hand side, otherwise false
 */

template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    // reset elements
    l_front = nullptr;
    l_back = nullptr;
    list_size = 0;
    if (x.l_front == nullptr)
    {
        return;
    }
    node<T>* ptr = x.l_front;
    while (ptr != nullptr)
    {
        push_back(ptr->value); // copy elements to x from original object
        ptr = ptr->next;
    }
}

/* front (non-const)
 *
 * retrieves reference to first element in list and throws underflow_error exception if list is empty.
 *
 * @param none
 *
 * @return T& - reference to the first element in the list
 */

template <class T>
T& mylist<T>::front()
{
    if (!empty())
    {
        return l_front->value;
    }
    else
    {
        throw underflow_error("underflow exception on call to front()"); // if list is empty
    }
}

/* front (const)
 *
 * retrieves const reference to first element in list and throws underflow_error exception if list is empty.
 *
 * @param none
 *
 * @return const T& - const reference to the first element in the list
 */

template <class T>
const T& mylist<T>::front() const
{
    if (!empty())
    {
        return l_front->value;
    }
    else
    {
        throw underflow_error("underflow exception on call to front()"); // if list is empty
    }
}

/* back (const)
 *
 * retrieves const reference to last element in list and throws underflow_error exception if list is empty.
 *
 * @param none
 *
 * @return const T& - const reference to the last element in the list
 */

template <class T>
const T& mylist<T>::back() const
{
    if (!empty())
    {
        return l_back->value;
    }
    else
    {
        throw underflow_error("underflow exception on call to back()"); // if list is empty
    }
}

/* back (non-const)
 *
 * retrieves reference the last element in list and throws underflow_error exception if list is empty.
 *
 * @param none
 *
 * @return T& - reference to the last element in the list
 */

template <class T>
T& mylist<T>::back()
{
    if (!empty())
    {
        return l_back->value;
    }
    else
    {
        throw underflow_error("underflow exception on call to back()"); // if list is empty
    }
}

/* push_back
 *
 * adds new element to back of list.
 *
 * @param const T& value - value to be added to back
 *
 * @return nothing
 */

template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value, l_back, nullptr); // allocate new node

    new_node->prev = l_back;

    if (empty())
    {
        l_front = new_node; // add to front if first element
    }
    else
    {
        l_back->next = new_node;
    }

    l_back = new_node;

    list_size++; // list increases after element is added
}

/* push_front
 *
 * adds new element to front of list.
 *
 * @param const T& value - the value to be added to the front
 *
 * @return nothing
 */

template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value, l_front, nullptr);

    new_node->next = l_front;

    if (empty())
    {
        l_back = new_node;// add to back if first element
    }
    else
    {
        l_front->prev = new_node;
    }

    l_front = new_node;

    list_size++; //  list increases after element is added
}

/* pop_back
 *
 * removes last element in the list and throws an underflow_error exception if the list is empty
 *
 * @param none
 *
 * @return nothing
 */

template <class T>
void mylist<T>::pop_back()
{
    // Case 0
    if (empty())
    {
        throw std::underflow_error("underflow exception on call to pop_back()"); // if list is empty
    }

    // Case 1: List has multiple nodes
    node<T>* del_node = l_back;
    l_back = del_node->prev;

    if (l_back == nullptr)
    {
        // Case 2: List has one node
        l_front = nullptr;
    }
    else
    {
        l_back->next = nullptr;
    }

    delete del_node;
    list_size--;
}

/* pop_front
 *
 * removes the first element in the list and throws an underflow_error exception if the list is empty.
 *
 * @param none
 *
 * @return nothing
 */

template <class T>
void mylist<T>::pop_front()
{
    if (empty()) // if list is empty
    {
        throw std::underflow_error("underflow exception on call to pop_front()");
    }

    node<T>* del_node = l_front;
    l_front = del_node->next;
    if (l_front == nullptr)
    {
        // Case 2: List has one node
        l_back = nullptr;
    }
    else
    {
        l_front->prev = nullptr;
    }

    delete del_node; // do not need del_node anymore
    list_size--; // decrease size after element is removed
}

/* size
 *
 * retrieves the number of elements in the list.
 *
 * @param none
 *
 * @return size_t - the number of elements in the list
 */

template <class T>
size_t mylist<T>::size() const
{
    return list_size;
}

/* empty
 *
 * Checks whether the list is empty.
 *
 * @param none
 *
 * @return true if the list is empty, false otherwise
 */

template <class T>
bool mylist<T>::empty() const
{
    return list_size == 0;
}

/* operator<< (stream insertion operator)
 *
 * overloads the << operator to print all elements in the list separated by spaces
 *
 * @param ostream& os - the output stream to write to
 * @param const mylist<T>& obj - the list object to be printed
 *
 * @return ostream& - the modified output stream
 */

template <class T>
ostream& operator<<(ostream& os, const mylist<T>& obj)
{
    node<T>* curr = obj.l_front;

    while (curr != nullptr) // traverse linked list
    {
        os << curr->value << " ";
        curr = curr->next;
    }
    return os;
}

#endif
