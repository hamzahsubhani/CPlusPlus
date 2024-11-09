#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int linearSearch(double[], int, int);
int binarySearch(double[], int, int);

int main()
{
    double array[10] = {4, 2, 6, 1, 8, 9, 23, 1, 33, 12};
    
    int size = 10; // Size of the array
    int target = 23; // The target value to search for
    
    // Sort the array before performing binary search
    

    // Print sorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Linear Search: " << linearSearch(array, size, target) << endl;
    
    cout << endl;
    sort(array, array + size);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    
    cout << endl;

   
    cout << "Binary Search: " << binarySearch(array, size, target) << endl;

    return 0;
}

int linearSearch(double array[], int n, int key)
{
    for (int i = 0; i < n; ++i) { // search through the list
        if (key == array[i]) { // if the key is equal to the current element
            return i; // return the index
        }
    }
    return -1; // if element is not found, return -1
}

int binarySearch(double array[], int n, int key)
{
    
    int low = 0;
    int high = n - 1;

    while (low <= high) { // search through the array
        int mid = (low + high) / 2; // calculate midpoint to compare with key
        if (key == array[mid])
        {
            return mid; // key found
        }
        
        if (key < array[mid])
        {
            high = mid - 1; // search in the left half
        } else {
            low = mid + 1; // search in the right half
        }
    }

    return -1; // if not found, return -1
}
