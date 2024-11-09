//***************************************************************************
//
//  merge_sort.cpp
//  CSCI 241 Assignment 7
//  Sort numbers using mergesort algorithm
//  Created by Hamzah Subhani
//  Z-ID: 2010017
//  Allman style documentation
//***************************************************************************
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using std::vector;

/*  build_array
 *
 *  Reads a series of doubles from the standard input stream using cin.
 *
 *  @param double array[], used to store the read doubles.
 *
 *  @return int, number of doubles read into the array.
 */

int build_array(double array[])
{
    int n = 0; // initialize numbers read variable

    while (cin >> array[n]) // while reading the numbers
    {
        n++; // increment n
    }

    return n; // return values read
}

/*  print_array
 *
 *  Prints the read doubles of the array with a fixed width of 8 characters per line.
 *
 *  @param double array[], used to store the read doubles.
 *
 *  @param int n, amount of doubles in the array.
 *
 *  @return nothing.
 */

void print_array(double array[], int n)
{
    cout << fixed << setprecision(2); // print numbers 2 spots after decimal

    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << array[i];

        if ((i + 1) % 8 == 0) // print 8 numbers per line
        {
            cout << endl;
        }
    }

    if (n % 8 != 0) // print endline for organization
    {
        cout << endl;
    }
}

/*  partition
 *
 *  Merges two sorted sections of numbers and stores them in a vector temp to be copied to the original array.
 *
 *  @param double array[], used to store the read doubles.
 *
 *  @param int start, starting index of the array.
 *
 *  @param int mid, middle index of the array.
 *
 *  @param int end, ending index of the array.
 *
 *  @return nothing.
 */

void partition(double array[], int start, int mid, int end)
{
    vector<double> temp(end - start + 1); // declaring temp to store the sorted values
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) // the following swaps will occur to make sure the halves are joined in ascending order.
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            i = i + 1;
        }
        else
        {
            temp[k] = array[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= mid)
    {
        temp[k] = array[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= end)
    {
        temp[k] = array[j];
        j = j + 1;
        k = k + 1;
    }

    for (int y = 0; y < k; y++) // copying the temp sorted numbers to the original array
    {
        array[start + y] = temp[y];
    }
}

/*  merge
 *
 *  Recursively divides the array and merges them back together in a sorted manner.
 *
 *  @param double array[], used to store the read doubles.
 *
 *  @param int start, starting index of the array.
 *
 *  @param int end, ending index of the array.
 *
 *  @return nothing.
 */

void merge(double array[], int start, int end)
{
    if (start < end) // base case
    {
        int mid = (start + end) / 2; // mid point initialization
        merge(array, start, mid); // recursive calls
        merge(array, mid + 1, end);
        partition(array, start, mid, end);
    }
}

/*  merge_sort
 *
 *  Initiates the merge sort algorithm on the entire array.
 *
 *  @param double array[], used to store the read doubles.
 *
 *  @param int n, number of doubles in the array.
 *
 *  @return nothing.
 */

void merge_sort(double array[], int n)
{
    merge(array, 0, n - 1); // function call
}
