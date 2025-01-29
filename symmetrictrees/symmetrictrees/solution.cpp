#include <iostream>
#include "node.h"

using namespace std;


bool is_mirror(node* t1, node* t2)
{
    // If both nodes are nullptr, they are symmetric
    if (t1 == nullptr && t2 == nullptr) {
        return true;
    }

    // If one of the nodes is nullptr and the other isn't, they are not symmetric
    if (t1 == nullptr || t2 == nullptr) {
        return false;
    }

    // Check if the current nodes are the same and their subtrees are mirrors
    return (is_mirror(t1->left, t2->right) && is_mirror(t1->right, t2->left));
}

bool symmetric(node* t1, node* t2)
{
    return is_mirror(t1, t2);
    
}

