//
//  main.cpp
//
//  Created by Kurt McMahon on 2/5/24.
//


#include <iostream>

int compute_score(int[][4]);
//void fill_grid(int[][4]);
//void print_grid(int[][4]);

using std::cout;
using std::endl;
/*
int main()
{
    int grid[4][4];
    int game1[4][4] = {{6, 6, 6, 6}, {6, 6, 6, 6},
                       {6, 6, 6, 6}, {6, 6, 6, 6}};
    int game2[4][4] = {{5, 5, 5, 5}, {3, 3, 3, 3},
                       {1, 1, 1, 1}, {5, 5, 5, 5}};

    print_grid(game1);
    cout << "Score = " << compute_score(game1)
         << endl << endl;

    print_grid(game2);
    cout << "Score = " << compute_score(game2)
         << endl << endl;

    srand(4);
    
    for (int i = 0; i < 8; i++)
    {
        fill_grid(grid);
        print_grid(grid);
        cout << "Score = " << compute_score(grid)
             << endl << endl;
    }
    
    return 0;
}

void fill_grid(int grid[][4])
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
            grid[r][c] = rand() % 6 + 1;
    }
}

void print_grid(int grid[][4])
{
    for (int r = 0; r < 4; r++)
    {
        cout << "-----------------\n|";
        
        for (int c = 0; c < 4; c++)
            cout << ' ' << grid[r][c] << " |";
        
        cout << endl;
    }

    cout << "-----------------\n\n";
}
 */

int compute_score(int grid[][4]) {
    int score = 0;

    // Check corners
    bool cornersEven = (grid[0][0] % 2 == 0 && grid[0][3] % 2 == 0 &&
                        grid[3][0] % 2 == 0 && grid[3][3] % 2 == 0);
    bool cornersOdd = (grid[0][0] % 2 != 0 && grid[0][3] % 2 != 0 &&
                       grid[3][0] % 2 != 0 && grid[3][3] % 2 != 0);
    if (cornersEven) score += 20;
    if (cornersOdd) score += 20;

    // Check diagonals
    bool mainDiagonalEven = (grid[0][0] % 2 == 0 && grid[1][1] % 2 == 0 &&
                             grid[2][2] % 2 == 0 && grid[3][3] % 2 == 0);
    bool mainDiagonalOdd = (grid[0][0] % 2 != 0 && grid[1][1] % 2 != 0 &&
                            grid[2][2] % 2 != 0 && grid[3][3] % 2 != 0);
    if (mainDiagonalEven) score += 20;
    if (mainDiagonalOdd) score += 20;

    bool otherDiagonalEven = (grid[3][0] % 2 == 0 && grid[2][1] % 2 == 0 &&
                              grid[1][2] % 2 == 0 && grid[0][3] % 2 == 0);
    bool otherDiagonalOdd = (grid[3][0] % 2 != 0 && grid[2][1] % 2 != 0 &&
                             grid[1][2] % 2 != 0 && grid[0][3] % 2 != 0);
    if (otherDiagonalEven) score += 20;
    if (otherDiagonalOdd) score += 20;

    // Check rows and columns
    bool hasEvenRow = false;
    bool hasOddRow = false;
    bool hasEvenCol = false;
    bool hasOddCol = false;

    for (int i = 0; i < 4; i++) {
        bool allEvenRow = true;
        bool allOddRow = true;
        bool allEvenCol = true;
        bool allOddCol = true;

        for (int j = 0; j < 4; j++) {
            // For rows
            if (grid[i][j] % 2 != 0) allEvenRow = false;
            if (grid[i][j] % 2 == 0) allOddRow = false;

            // For columns
            if (grid[j][i] % 2 != 0) allEvenCol = false;
            if (grid[j][i] % 2 == 0) allOddCol = false;
        }

        if (allEvenRow) hasEvenRow = true;
        if (allEvenCol) hasEvenCol = true;
        if (allOddCol) hasOddCol = true;
    }

    if (hasEvenRow) score += 20;
    if (hasOddRow) score += 20;
    if (hasEvenCol) score += 20;
    if (hasOddCol) score += 20;

    
    int totalSum = 0;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            totalSum += grid[r][c];
        }
    }
    score += totalSum;

    return score;
}
