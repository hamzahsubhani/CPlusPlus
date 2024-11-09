/********************************************************************
CSCI 240 - Assignment 7 - Spring semester 2024

Progammer: Hamzah Subhani
Z-ID- 2010017
Section:  2
TA:      Venkata Sai Pranit Thotakura
Date Due:  3/29/2024

Purpose: To read two sets of data representing a series of numeric measurements. The program will display the data unsorted and then sorted while displaying varous statistics about each of the data sets.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

//symbolic constants
const double END_OF_INPUT = -999.99;
const int MAX_SIZE = 20;
const int MAX_VALUES_PER_LINE = 8;


// function prototypes
int buildArray(string filename, double array[]);
void printArray(string title, double array[], int numValues);
void sortArray(double array[], int numValues);
double mean(double array[], int numValues);
double median(double array[], int numValues);
double low(double array[], int numValues);
double high(double array[], int numValues);
double standardDeviation(double array[], int numValues);

int main()
{
    double arrayA[MAX_SIZE];
    double arrayB[MAX_SIZE];
    int numValuesA, numValuesB;

    // Fill arrays A and B with text files and buildarray function
    numValuesA = buildArray("data7A.txt", arrayA);
    numValuesB = buildArray("data7B.txt", arrayB);

    // Display unsorted arrays A and B
    cout << "Unsorted Set A" << endl;
    printArray("", arrayA, numValuesA);

    cout << "\nUnsorted Set B" << endl;
    printArray("", arrayB, numValuesB);

    // Sort arrays A and B
    sortArray(arrayA, numValuesA);
    sortArray(arrayB, numValuesB);

    // Display sorted arrays A and B
    cout << "\nSorted Set A" << endl;
    printArray("", arrayA, numValuesA);

    cout << "\nSorted Set B" << endl;
    printArray("", arrayB, numValuesB);
    
    cout << endl;
    cout << fixed << setprecision(2);
    // Calculate and display statistics for Set A
    cout << "\nSet A Statistics" << endl;
    cout << endl;
    cout << "Mean:                 "  << mean(arrayA, numValuesA) << "   ";
    cout << "Median:               "  << median(arrayA, numValuesA) << endl;
    cout << "Low:                  "  << " " <<  low(arrayA, numValuesA) << "   ";
    cout << "High:                 "  << high(arrayA, numValuesA) << endl;
    cout << "Standard Deviation:   "  << standardDeviation(arrayA, numValuesA) << endl;

    // Calculate and display statistics for Set B
    cout << "\nSet B Statistics" << endl;
    cout << endl;
    cout << "Mean:                 " << mean(arrayB, numValuesB) << "   ";
    cout << "Median:               " << " " << median(arrayB, numValuesB) << endl;
    cout << "Low:                  "  << " " << low(arrayB, numValuesB) << "   ";
    cout << "High:                 " << high(arrayB, numValuesB) << endl;
    cout << "Standard Deviation:   " << standardDeviation(arrayB, numValuesB) << endl;

    // Display differences
    cout << "\nDifferences" << endl;
    cout << endl;
    cout << "Mean:                  " << (mean(arrayA, numValuesA) - mean(arrayB, numValuesB)) << endl;
    cout << "Median:                " << (median(arrayA, numValuesA) - median(arrayB, numValuesB)) << endl;
    cout << "Standard Deviation:    " << (standardDeviation(arrayA, numValuesA) - standardDeviation(arrayB, numValuesB)) << endl;
    

    return 0;
}

/***************************************************************
Function: buildArray
Use: opening the files that were added along with the main cpp file, testing if it opens and reads the information from the text files.
Arguments: a string containing the filename, an array of doubles
Returns:   number of values that were placed in the array
***************************************************************/



int buildArray(string filename, double array[])
{
    int numValues = 0;
    double value;
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Failed to open file: " << filename << endl;
        exit(-1);
    }

    
    while (infile >> value && value != END_OF_INPUT && numValues < MAX_SIZE)
    {
        array[numValues++] = value;
    }

    infile.close();
    return numValues;
}

/***************************************************************
Function: printArray
Use: displays the information in an array with 2 digits after the decimal point of every number with 8 values per line.
Arguments: a string containing the title for the values being displayed, an array of doubles that holds the data, and an integer that holds the number of values in the array
Returns:   nothing
***************************************************************/

void printArray(string title, double array[], int numValues)
{
    cout << title << endl;
    for (int i = 0; i < numValues; ++i)
    {
        cout << setw(8) << fixed << setprecision(2) << array[i];
        if ((i + 1) % MAX_VALUES_PER_LINE == 0 || i == numValues - 1)
            cout << endl;
    }
}

/***************************************************************
Function: sortArray

Use: sorts the array in ascending order using selection sort.
Arguments: array of doubles holding the data to be sorted, an integer that holds the number of values in the array

Returns:  nothing
***************************************************************/

void sortArray(double array[], int numValues)
{
    for (int i = 0; i < numValues - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < numValues; ++j)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            double temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

/***************************************************************
Function: mean

Use: Calculates the average of the numbers in the passed in array.
Arguments: an array of doubles that holds the data, an integer that holds the number of values in the array.

Returns:    calculated average as a double
***************************************************************/
double mean(double array[], int numValues)
{
    double sum = 0.0;
    for (int i = 0; i < numValues; ++i)
    {
        sum += array[i];
    }
    return sum / numValues;
}

/***************************************************************
Function: median

Use: calculates the middle value of the numbers in a passed in array
Arguments: array of doubles that holds the data, and an integer that holds the number of values in the array.

Returns:   the calculated median as a double
***************************************************************/
    // Sort the array
double median(double array[], int numValues)
{
    sortArray(array, numValues);
    if (numValues % 2 == 0)
    {
        return (array[numValues / 2] + array [numValues / 2]) / 2;
        
    }
    else
    {
        return array [numValues / 2];
    }
        
    
}


/***************************************************************
Function: low

Use: finds the smallest value in the array
Arguments: array of doubles that holds the data, and an integer that holds the number of values in the array.

Returns:   smallest value in the array as a double
***************************************************************/



double low(double array[], int numValues)
{
    return array[0];
}

/***************************************************************
Function: high

Use: finds the largest value in the array
Arguments: array of doubles that holds the data, and an integer that holds the number of values in the array.

Returns:   largest value in the array as a double
***************************************************************/

double high(double array[], int numValues)
{
    return array[numValues - 1];
}

/***************************************************************
Function: standardDeviation

Use: calculates the standard deviation of the values in the array
Arguments: an array of doubles that holds the data and an integer that holds the number of values in the array.

Returns:  calculated standard deviation of the values in the array as a double.
***************************************************************/
double standardDeviation(double array[], int numValues)
{
    double meanVal = mean(array, numValues);
    double sumSquares = 0.0;
    
    
    for (int i = 0; i < numValues; ++i)
    {
        sumSquares += pow(array[i] - meanVal, 2);
    }
    
    
    return sqrt(sumSquares / (numValues - 1));
}
