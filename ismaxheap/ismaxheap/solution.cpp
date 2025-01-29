#include <iostream>
#include <iomanip>

using namespace std;

bool is_max_heap(int[], int);
/*
int main()
{
    int a1[] = {1, 2, 3, 4};
    int a2[] = {5, 3, 4, 2, 1};
    int a3[] = {100, 19, 25, 17, 3, 36, 1, 2, 7};
    int a4[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    if (!is_max_heap(a1, 4))
        cout << "Correct, this is not a max heap.\n";
    else
        cout << "Incorrect, this is not a max heap.\n";

    if (is_max_heap(a2, 5))
        cout << "Correct, this is a max heap.\n";
    else
        cout << "Incorrect, this is a max heap.\n";

    if (!is_max_heap(a3, 9))
        cout << "Correct, this is not a max heap.\n";
    else
        cout << "Incorrect, this is not a max heap.\n";

    if (is_max_heap(a4, 10))
        cout << "Correct, this is a max heap.\n";
    else
        cout << "Incorrect, this is a max heap.\n";

    return 0;
}
*/
bool is_max_heap(int a[], int n)
{
    // Check the heap property for each non-leaf node
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;  // Index of left child
        int right = 2 * i + 2; // Index of right child

        // Check if the left child exists and violates the max heap property
        if (left < n && a[i] < a[left])
            return false;

        // Check if the right child exists and violates the max heap property
        if (right < n && a[i] < a[right])
            return false;
    }
    return true; // If no violations, it's a max heap
}
