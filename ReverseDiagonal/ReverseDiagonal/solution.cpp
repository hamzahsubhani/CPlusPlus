#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

/*static void print_array(int array[][4])
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << array[row][col] << ' ';
        }

        cout << endl;
    }
}
*/
void reverse_diagonal(int[][4]);

/*int main()
{
    int array1[4][4] = {{21, 26, 31, 36},
                        {41, 46, 51, 56},
                        {61, 66, 71, 76},
                        {81, 86, 91, 96}};

    int array2[4][4] = {{35, 12, 27, 84},
                        {62, 19, 81, 32},
                        {74, 53, 29, 41},
                        {23, 60, 37, 15}};

    cout << "Before:\n\n";
    print_array(array1);

    reverse_diagonal(array1);

    cout << "\nAfter:\n\n";
    print_array(array1);

    cout << endl;

    cout << "Before:\n\n";
    print_array(array2);

    reverse_diagonal(array2);

    cout << "\nAfter:\n\n";
    print_array(array2);

    return 0;
}
*/

void reverse_diagonal(int array[][4])
{
    // Reverse the primary diagonal (top-left to bottom-right)
    for (int i = 0; i < 2; i++)
    {
        int temp = array[i][i];
        array[i][i] = array[3-i][3-i];
        array[3-i][3-i] = temp;
    }
    
    // Reverse the secondary diagonal (top-right to bottom-left)
    for (int i = 0; i < 2; i++)
    {
        int temp = array[i][3-i];
        array[i][3-i] = array[3-i][i];
        array[3-i][i] = temp;
    }
}
