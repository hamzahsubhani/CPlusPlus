#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <cstdlib>


using namespace std;

struct node
{
    
    int value;
    node* next;
    
    
    node (int value, node* next = nullptr)
    {
        this->value = value;
        this -> next = next;
    }
};

class mystack
{
private:
    node* topstack;
    size_t stk_size = 0;
    
    
    
public:
    mystack();
    mystack(const mystack& );
    ~mystack();
    mystack& operator=(const mystack& );
    size_t size() const;
    bool empty() const;
    void clear();
    const int& top() const;
    void push (int);
    void pop();
    friend ostream& operator<<(ostream& , const mystack& );
    void clone(const mystack& );
};
    
 

#endif

