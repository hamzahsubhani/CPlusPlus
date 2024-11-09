//***************************************************************************
//
// queens.cpp
// CSCI 241 Assignment 5
// Arrange Queens on a chessboard (2D array) with conditions
// Created by Hamzah Subhani ZID- 2010017
//
//***************************************************************************/
#include <iostream>
#include <iostream>

using namespace std;

bool Check(int[8][8], int); // function header

int main()

{
    
        int board [8][8] = {0}; // initializing array with 0's
    
        if (Check (board, 0))
    
        {
    
        for (int i = 0; i < 8; i++)
        
        {
        
        for ( int j = 0; j < 8; j++)
            
        {
            
        cout << board [i][j] << " "; // display board if function returns true
            
        }
            
        cout << endl;
            
        }
    
        }
    
}

/* bool Check
 
 * Places a Queen on the chess board(2D Array) based on several proximity conditions
 *
 * @param board, an array of integers used to sort through
 
 * @param row - integer data type to be searched for queens
 *
 * @return true if the conditions are met, false if not.
 *
 * @note a recursive process is used to backtrack if case is not met
 
 */
bool Check(int board[8][8], int row)

{
    
        if ( row>= 8) // base case
    
        {
            return true;
        }
    
        for (int col = 0; col < 8; col++) // integer being checked locally
    
        {
    
        bool safe = true; // means we can proceed to place the Queen
        
        for (int i = 0; i < row; i++)
    
        {
    
        if (board[i][col] == 1) // checks if previous rows column has a 1
    
            {
    
        safe = false;
    
        break; // do NOT place
    
            }
           
        }
        
        for (int i = row, j = col; i >= 0 && j>=0; i--, j-- ) // searches left diagonal ( i-up a row, j- left one column)
            
        {
            
        if (board[i][j] == 1) // if a queen is in left diagonal
                
            {
        safe = false;
                
        break;
                
            }
    
        }
        
        for ( int i = row, j = col; i >=0 && j<8; i--, j++) // searches right diagonal ( i-up a row, j-right one column)
                
    {
        if (board[i][j] == 1) // if queen is in right diagonal
            
        {
        safe = false;
        break;
    
        }
            
    }
        
        if (safe ) // if conditions are met
            
        {
            
        board[row][col] = 1; // place queen
            
        if (Check(board, row + 1)) // recursion call

        {
                
        return true;
                
        }
            
        board[row][col] = 0;  // Backtrack
            
        }
        
}
    
    return false; // if nothing works

}
