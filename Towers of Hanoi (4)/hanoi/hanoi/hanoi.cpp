//***************************************************************************
//  hanoi.cpp
//
//  CSCI 241 Assignment 4
//
//  Re create towers of hanoi with entered in values, and displaying the moves
//
//  Created by Hamzah Subhani (Z-ID: 2010017)
//
//***************************************************************************

#include <iostream>
#include <cstdlib> // needed for evaluating command line arguments

using namespace std;

void move(int n, int start, int holding, int destination); // function header

int main(int argc, char* argv[]) // checking arguments and converting argument to integer with array

{
    if (argc != 2) // should be entered value and program name
        
    {
        
    cout << "Character error " << endl;
        
    return 1; // exit with an error code
        
    }

    int n = atoi(argv[1]); // convert the command-line argument to an integer
    
    if (n <= 0)
        
    {
        cout << "Error: Number of disks must be a positive integer." << endl;
        
        return 1; // exit with an error code
    }

    move(n, 1, 3, 2); //  recursive call
    
    return 0;
}

/* void move
 *
 * moves n disks from start to destination peg using 3rd peg as placeholder peg
 *
 * @param number of disks to be moved
 *
 * @param start, starting peg which contais all the pegs to be moved
 *
 * @param holding, placeholder peg
 *
 * @param destination, peg where all disks should end up
 *
 * @return nothing
 *
 * @note uses recursive calls which resembles loop.
 */

void move(int n, int start, int holding, int destination)

{
    if (n == 1) // base case
        
    {
        
    cout << n << " " << start << "->" << destination << endl; //displaying disk number and moves
        
    return;
        
    }
    
    // using destination as a temporary peg
    move(n-1, start, destination, holding);
    
    // move the nth disk from start to destination
    cout << n << " " << start << "->" << destination << endl;
    
    // using start as a temporary peg
    move(n-1, holding, start, destination);
}
