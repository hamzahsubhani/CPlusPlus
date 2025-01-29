//***************************************************************************
//
//  bstree.h
//  CSCI 241 Assignment 17
//
//  Created by Hamzah Subhani (Z-2010017)
//
//***************************************************************************
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <queue>

using namespace std;

/* node struct
 *
 * representes single node in binary search tree
 *
 * @param K key: key for ordering nodes in the tree
 * @param V value: value associated with key
 * @param left: pointer to left child of the node
 * @param right: pointer to right child of the node
 *
 * @return nothing
 */

template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V>* left;
    node<K, V>* right;
    
    node(const K& key = K(), const V& value = V(), node<K, V>* left = nullptr, node<K, V>* right = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

template <class K, class V>
class bstree
{
private:
    node<K, V>* root;
    size_t tree_size;
    size_t height(node <K, V>* p) const;
    const node<K, V>* find (const K& key, node<K, V> *root) const;
    void preorder(node<K, V>* p) const;
    void inorder(node<K, V>* p) const;
    void postorder(node<K, V>* p) const;
    const K &min(node<K, V> *root) const;
    const K &max(node<K, V> *root) const;
public:
    bstree();
    ~bstree();
    bstree(const bstree<K, V>& x);
    bstree<K, V>& operator=(const bstree<K, V>& x);
    void clear();
    size_t size() const;
    size_t height() const;
    bool empty() const;
    const K& min () const;
    const K& max () const;
    bool insert (const K& key, const V& value);
    const node<K, V> *find(const K &key) const;
    bool remove (const K& key);
    void preorder() const;
    void inorder () const;
    void postorder() const;
    void level_order () const;
    void destroy(node<K, V>* p);
    node<K, V>* clone(node<K, V>* p);
};

/* bstree
 *
 * default initializer for the binary search tree
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
bstree<K, V>::bstree()
{
    root = nullptr;
    tree_size = 0;
}

/* ~bstree
 *
 * clears all dynamically allocated memory in the tree
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
bstree<K, V>::~bstree()
{
    clear(); // frees up all memory
}

/* bstree (copy constructor)
 *
 * creates a deep copy of the given object
 *
 * @param x: the tree to copy from
 *
 * @return nothing
 */

template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x)
{
    tree_size = x.tree_size;
    root = clone(x.root); // calls clone to copy data
}

/* clone
 *
 * creates deep copy of the subtree rooted at the given node
 *
 * @param p: pointer to root of the subtree to copy
 *
 * @return pointer to root of the cloned subtree
 */

template <class K, class V>
node<K, V>* bstree <K, V>::clone(node<K,V>* p)
{
    if (p!= nullptr)
    {
        node<K, V>* new_node = new node<K, V>; // allocate new node to copy data to
        new_node -> key = p -> key;
        new_node -> value = p -> value;
        // recursively copy all the data
        new_node -> left = clone( p -> left);
        new_node -> right = clone(p -> right);
        return new_node;
    }
    else
    {
        return nullptr; // if theres nothing to clone
    }
    
}

/* operator=
 *
 * assigns one tree to another via deep copy
 *
 * @param x: The tree to copy from.
 *
 * @return reference to the modified object
 */

template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
    if (this!= &x) // check for self assignment
    {
        clear();
        tree_size = x.tree_size;
        root = clone(x.root);
    }
    return *this; // returns reference
}

/* clear
 *
 * removes all nodes from the BST and resets it to an empty state
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>::clear()
{
    destroy(root); // resets everything
    root = nullptr;
    tree_size = 0;
}

/* destroy
 *
 * recursively deallocates memory for all nodes in the subtree rooted at p
 *
 * @param p: pointer to root of the subtree to destroy
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>:: destroy(node<K, V>* p)
{
    if (p == nullptr)
    {
        return;
    }
    
    destroy(p-> left); // recursively delete memory for all nodes and delete pointer
    destroy(p-> right);
    delete p;
    
}

/* find
 *
 * searches for a node with the given key in the tree
 *
 * @param key: key to search for
 *
 * @return pointer to found node or nullptr if not found
 */

template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
    node<K, V>* p = root;
    while (p!= nullptr && key!= p-> key)
    {
        if (key < p -> key) // go left if key is less than what is being evaluated
        {
            p = p -> left;
        }
        else
        {
            p = p -> right; // go right instead
        }
    }
    return p; // return pointer
}

/* empty
 *
 * checks if tree is empty
 *
 * @param none
 *
 * @return true if the tree is empty false if not
 */

template <class K, class V>
bool bstree<K, V>::empty() const
{
    return tree_size == 0; // if empty return true
}

/* height
 *
 * retrieves height of tree by calling private recursive function
 *
 * @param none
 *
 * @return height of tree
 */

template <class K, class V>
size_t bstree<K, V>:: height() const
{
   return height(root); // private call needed
}

/* height (helper function)
 *
 * recursively computes the height of the subtree rooted at p
 *
 * @param p: pointer to the root of the subtree
 *
 * @return height of the subtree
 */

template <class K, class V>
size_t bstree<K, V>::height(node <K, V>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    
    size_t l_height = height(p -> left); // recursive calls
    size_t r_height = height(p -> right);
    
    if (l_height > r_height)
        return l_height + 1;
    else
        return r_height + 1;
}

/* size
 *
 * retrieves number of nodes in the tree
 *
 * @param none
 *
 * @return number of nodes in the tree
 */

template <class K, class V>
size_t bstree<K, V>::size() const
{
    return tree_size;
}

/* preorder
 *
 * preforms a preorder traversal of the tree by calling private recursive function
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root); //recursive call
}

/* preorder (helper function)
 *
 * recursively performs preorder traversal of subtree rooted at p
 *
 * @param p: pointer to the root of the subtree
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>::preorder(node<K, V>* p) const
{
    if (p!= nullptr)
    {
        cout << p->key << ": " << p->value << endl; // print each value at node
        preorder(p-> left);
        preorder(p-> right);
    }
    
}

/* inorder
 *
 * preforms inorder traversal of the tree by calling private recursive function
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>:: inorder() const
{
    inorder(root); // recursive call
}

/* inorder (helper function)
 *
 * recursively performs inorder traversal of subtree rooted at p
 *
 * @param root: pointer to the root of the subtree
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* p) const
{
    if (p!= nullptr)
    {
        inorder(p->left);
        cout << p->key << ": " << p->value << endl; // print each value at node
        inorder(p->right);
    }
}

/* postorder
 *
 * preforms postorder traversal of the tree by calling private recursive function
 *
 * @param none
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>:: postorder () const
{
    postorder(root); // recursive call
}

/* postorder (helper function)
 *
 * recursively performs postorder traversal of subtree rooted at p
 *
 * @param root: pointer to the root of the subtree
 *
 * @return nothing
 */

template <class K, class V>
void bstree<K, V>::postorder(node<K, V>* p) const
{
    if (p!= nullptr)
    {
        postorder(p -> left);
        postorder(p -> right);
        cout << p->key << ": " << p->value << endl; // print each value at node
    }
}

/* bstree<K, V>::level_order
 *
 * preforms iterative level-order traversal of the tree
 *
 * @param none
 *
 * @return none
 */

template <class K, class V>
void bstree<K, V>::level_order() const
{
    node<K, V>* p;
    queue<node<K, V>*> q; // create queue to store nodes
    
    if (root == nullptr)
        return;
    
    q.push(root); // push values to root of tree
    
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->key << ": " << p->value << endl; // print each value at node
        
        if (p -> left!= nullptr)
            q.push(p -> left);
        
        if (p -> right!= nullptr)
            q.push(p -> right);
    }
}

/* min
 *
 * retrieves the minimum key in the tree by calling private recursive function
 *
 * @param nothing
 *
 * @return constant reference to the smallest key in the tree
 */

template <class K, class V>
const K& bstree<K, V>::min () const
{
    return min(root); // recursive call
}

/* min (helper function)
 *
 * finds the minimum key in a subtree
 *
 * @param root: pointer to the root of subtree
 *
 * @return constant reference to the smallest key in the subtree
 */

template <class K, class V>
const K& bstree<K, V>::min(node<K, V> *root) const
{
    node <K, V>* p = root;
    
    while (p -> left!= nullptr)
    {
        p = p -> left;
    }
    
    return p-> key;
}

/* max
 *
 * retrieves maximum key in tree by calling private recursive function
 *
 * @param none
 *
 * @return constant reference to the largest key in the tree
 */

template <class K, class V>
const K& bstree<K, V>:: max() const
{
    return max(root); // recursive call
}

/* max (helper function)
 *
 * finds the maximum key in a subtree
 *
 * @param root: pointer to the root of subtree
 *
 * @return constant reference to the largest key in the subtree
 */

template <class K, class V>
const K& bstree<K, V>::max(node<K, V> *root) const
{
    node <K, V>* p = root;
    
    while (p -> right!= nullptr)
    {
        p = p -> right;
    }
    return p -> key;
}

/* insert
 *
 * inserts key-value pair into the tree
 *
 * @param key: key to insert
 * @param value: associated value
 *
 * @return true if insertion was successful false if key already exists
 */

template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
    node <K, V>* p = root;
    node <K, V>* parent = nullptr;
    // start at root of tree
    while (p!= nullptr && key!= p -> key) // search for duplicate key
    {
        parent = p;
        if (key < p -> key)
        {
            p = p -> left;
        }
        else
        {
            p = p -> right;
        }
    }
    if (p!= nullptr) // If duplicates are disallowed, signal that insertion has failed.
        return false;
    
    node<K, V>* new_node = new node<K, V>(key, value, nullptr, nullptr); // allocate new node
    if (parent == nullptr)
        root = new_node;
    else
    {
        if ( new_node -> key < parent -> key)
            parent -> left = new_node;
        else
        {
            parent -> right = new_node;
        }
    }
    tree_size ++;
    return true;  // If duplicates are disallowed, signal that insertion has succeeded.
}

/* bstree<K, V>::remove
 *
 * removes key-value pair from the binary search tree
 *
 * @param key: key to remove
 *
 * @return true if removal was successful, false if key does not exist
 */

template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    node<K,V>* p;
    node<K,V>* parent;
    node<K,V>* replace;
    node<K,V>* replace_parent;
    
    // start at the root of the tree and search for the key to delete.
    p = root;
    parent = nullptr;
    
    while (p!= nullptr && key!= p -> key)
    {
        parent = p;
        if (key < p -> key)
        {
            p = p -> left;
        }
        else
        {
            p = p -> right;
        }
        
    }
    
    if (p == nullptr) // if node to delete was not found, signal failure
        return false;
    
    if (p -> left == nullptr) // has no children, replace p with right child OR has no left child but has right child. replace p with right child
        
    {
        replace = p -> right;
    }
    else if ( p -> right == nullptr) // has left child but no right child
    {
        replace = p -> left;
    }
    else // p has two children
    {
        replace_parent = p;
        replace = p -> left;
        while (replace -> right!= nullptr)
        {
            replace_parent = replace;
            replace = replace -> right;
        }
        if (replace_parent!= p)
            // If we were able to go to the right, make the replacement node's
            // left child the right child of its parent. Then make the left child
            // of p the replacement's left child.
        {
            replace_parent -> right = replace -> left;
            replace -> left = p -> left;
        }
        replace -> right = p -> right;
    }
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if ( p -> key < parent -> key)
        {
            parent -> left = replace;
        }
        
        else
        {
            parent -> right = replace;
        }
    }
    // Delete the node, decrement the tree size, and signal success.
    tree_size--;
    return true;
}


#endif
