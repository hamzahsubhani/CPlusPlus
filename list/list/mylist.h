#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
 
using namespace std;

template <class T>
class mylist;

template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

template <class T>
struct node
{
    T value;
    node<T>* next;
    node<T>* prev;
    
    node(const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr)
        {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
};

template <class T>
class mylist
{
private:
    
public:
    node<T>* l_front;
    node<T>* l_back;
    size_t list_size;
    
    mylist();
    ~mylist();
    mylist(const mylist<T>& );
    mylist<T>& operator=(const mylist<T>& );
    void clear();
    size_t size() const;
    bool empty() const;
    const T& front () const;
    T& front();
    const T& back() const;
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool operator == (const mylist<T>& rhs) const;
    bool operator < (const mylist<T>& rhs) const;
    friend ostream& operator<< <>(ostream& os, const mylist<T>&);
    
    
};

template <class T>
mylist<T>::mylist()
{
    l_front = nullptr;
    l_back = nullptr;
    list_size = 0;
}

template <class T>
mylist<T>::~mylist()
{
    clear();
}
template <class T>
void mylist<T>::clear()
{
    while(list_size == 0)
        pop_back();
}

template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    
    node<T>* curr = l_front;
    while (curr!= nullptr) // traverse linked list
    {
        push_back(x);
        curr = curr -> next;
    }
}

template <class T>
T& mylist<T>::front()
{
    if (!empty())
        return l_front->value;
    else
        throw underflow_error("Underflow Error");
}

template <class T>
const T& mylist<T>::front() const
{
    if (!empty())
        return l_front -> value;
    else
        throw underflow_error("Underflow Error");
}

template <class T>
const T& mylist<T>::back() const
{
    if (!empty())
        return l_back -> value;
    else
        throw underflow_error("Underflow Error");
}

template <class T>
T& mylist<T>::back()
{
    if (!empty())
        return l_back -> value;
    else
        throw underflow_error("Underflow Error");
}

template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value, l_back, nullptr);
    
    new_node -> prev = l_back;
    
    if (empty())
    {
        l_front = new_node;
    }
    else
    {
        l_back ->next = new_node;
    }
    
    l_back = new_node;
        
    list_size++;
}

template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value, l_front, nullptr);
    
    new_node -> next = l_front;
    
    if (empty())
    {
        l_back = new_node;
    }
    else
    {
        l_front -> prev = new_node;
    }
    
    l_front = new_node;
        
    list_size++;
  
}

template <class T>
void mylist<T>::pop_back()
{
// Case 0
if (empty())
   throw std:: underflow_error("Error - underflow on pop_back()");

// Case 1: List has multiple nodes
node <T>* del_node = l_back;
l_back = del_node -> prev;

if (l_back == nullptr)
   // Case 2: List has one node
   l_front = nullptr;
else
   l_back -> next = nullptr;

delete del_node;
list_size --;

}

template <class T>
size_t mylist<T>::size() const
{
    return list_size;
}

template <class T>
bool mylist<T>::empty() const
{
    return list_size == 0;
}

template <class T>
ostream &operator<<(ostream &os, const mylist<T> &obj)
{
    node<T>* curr = obj.l_front;
    
    while (curr!= NULL) // traverse linked list
    {
        os << curr-> value << " ";
        curr = curr -> next;
    }
    return os;
}

#endif
















