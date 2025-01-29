#include <iostream>
using namespace std;
int sum(int n);

int sum(int n)
{
    if (n == 1)
        return 1;
    
    return n + sum(n - 1);
}
// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) // Base case for factorial
        return 1;
    else
        return n * factorial(n - 1); // Recursive case
}

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Recursive function to count nodes in a linked list
int countNodes(Node* head) {
    if (head == nullptr) { // Base case: end of the list
        return 0;
    }
    // Recursive case: count the current node and the rest of the list
    return 1 + countNodes(head->next);
}

int main() {
    // Part 1: Calculate factorial
    int n = 10;
    int result = factorial(n); // Store the result of the factorial
    cout << "The factorial of " << n << " is " << result << endl; // Print the result

    // Part 2: Create a linked list and count nodes
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    int totalNodes = countNodes(head);
    cout << "Total nodes in the linked list: " << totalNodes << endl;

    // Clean up allocated memory (optional but good practice)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    
    int g = 5;
    cout << sum(g) << endl;
    return 0;
}
