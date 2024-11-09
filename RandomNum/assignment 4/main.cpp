// Name: Hamzah Subhani
// * Z-ID: 2010017
// * CSCI 240-0002
// * TA: Amy Byrnes
// * Assignment #4
// * Due Date: 2/23/2024
// * Purpose : This program is meant to Generate random numbers with a seed to srand and form them into columns, as well as show the even numbers, odd numbers, and numbers over 200.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#define TOTAL_VALUES_SET1 45
#define TOTAL_VALUES_SET2_MAX 75
#define TOTAL_VALUES_SET3_MAX 50
#define MINIMUM_VALUE 0.0
#define MAXIMUM_VALUE 300.0
#define VALUES_PER_LINE 7
//these are all the required symbolic constants

using namespace std;

int main() {
    srand(33);
    int num;

    // Set 1 using for loop
    cout << "Set 1 has exactly " << TOTAL_VALUES_SET1 << " values" << endl;
    int oddCountSet1 = 0;
    for (int i = 1; i <= TOTAL_VALUES_SET1; i++) {
        num = rand();
        cout << setw(12) << num; // all 3 sets will have this format so they are all aligned

        if (num % 2 != 0) {
            oddCountSet1++; //counting amount of odd numbers in columns to be displayed
        }

        // display 7 values per line for each column
        if (i % VALUES_PER_LINE == 0) {
            cout << endl;
        }
    }
    cout << endl;

    cout << "\nThere are " << oddCountSet1 << " odd numbers in Set 1" << endl;
    cout << endl;

    // Set 2 using while loop
    int totalValuesSet2 = rand() % TOTAL_VALUES_SET2_MAX + 1;
    int i = 1;
    cout << "Set 2 has exactly " << totalValuesSet2 << " values" << endl;
    int evenCountSet2 = 0;
    while (i <= totalValuesSet2) {
        num = rand();
        cout << setw(12) << num;

        if (num % 2 == 0) {
            evenCountSet2++; //counting amount of even numbers in columns to be displayed
        }

        // display 7 values per line
        if (i % VALUES_PER_LINE == 0 || i == totalValuesSet2) {
            cout << endl;
        }

        i++;
    }

    cout << "\nThere are " << evenCountSet2 << " even numbers in Set 2" << endl;
    cout << endl;

    // Set 3 using do-while loop
    int totalValuesSet3 = rand() % TOTAL_VALUES_SET3_MAX + 1;
    cout << "Set 3 has exactly " << totalValuesSet3 << " values" << endl;
    i = 1;
    int numOver200 = 0; //counts the numbers that are over 200 to be displayed
    do {
        double randomDouble = (rand() / (RAND_MAX + 1.0)) * (MAXIMUM_VALUE - MINIMUM_VALUE) + MINIMUM_VALUE;// generates a random double number between 0 and 300
        cout << fixed << setprecision(1) << setw(12) << randomDouble; //displays random number with 1 digit after the decimal point

        if (randomDouble > 200) {
            numOver200++;
        }

        // Display 7 values per line
        if (i % VALUES_PER_LINE == 0 || i == totalValuesSet3) {
            cout << endl;
        }

        i++;
    } while (i <= totalValuesSet3);
    cout << endl;
    cout << "There are " << numOver200 << " numbers greater than 200 in Set 3" << endl;
    cout << endl;
    return 0;
}
