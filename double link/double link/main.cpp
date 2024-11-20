//
//  main.cpp
//  double link
//
//  Created by hamzah subhani on 11/19/24.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}





/* PUSH in doubly linked list
 // front
 template <class T>
 void mylist<T> :: insert_front(const T& value)
 {
 
 if (empty(()
 l_back = new_node;
 
 else
 l_front-> prev = new_node;
 }
 new_node->next = l_front;
 l_front=new_node;
 l_size++;
 
 }
 
 // back
 template <class T>
 void mylist<T>::insert_end(const T& value)
 {
     node<T> *newNode = new node<T>;
     newNode->data = item;
     newNode->next = NULL;
     newNode->previous = l_back;

     if (!l_front)
         l_front = newNode;

     if (l_back)
         l_back->next = newNode;
     l_back = newNode;

     ++len;
 }
 
 /POP in doubly linked list
 template <class T>
 void mylist<T>::pop_back()
 {
 // Case 0
 if (empty())
    throw std:: underflow_error("Error - underflow on pop_back()");
 
 // Case 1: List has multiple nodes
 node <t>* del_node = l_back;
 l_back = del_node -> prev;
 
 if (l_back == nullptr)
    // Case 2: List has one node
    l_front = nullptr;
 else
    l_back -> next = nullptr;
 
 delete del_node;
 l_size --;
 
}
 
 
 1. List is empty
 2. List is not empty and we are inserting the new value as the first node
 3. List is not empty and we are inserting the new value at the middle of the list.
 4. List is not empty and we are inserting the new value at the end of the list.
 
 
 
 insert middle
 
 node <t>* trailing = nullptr;
 node <T>* p = l_front;
 while (p! nullptr && value > p-> value)
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */
