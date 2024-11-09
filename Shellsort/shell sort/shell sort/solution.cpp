#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

//static int build_array(int[]);
//static void print_array(int[], int);
void shell_sort(int[], int);

/*
int main()
{
    int array[1000];
    int n;
 
    n = build_array(array);

    cout << n << " elements unsorted\n\n";

    print_array(array, n);
    
    cout << endl << n << " elements in ascending order\n\n";
    
    shell_sort(array, n);
    print_array(array, n);

    return 0;
}


int build_array(int array[])
{
    int n = 0;

    while (cin >> array[n])
        n++;

    return n;
}

void print_array(int array[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        cout << setw(8) << array[i];
        if ((i+1) % 8 == 0)
            cout << endl;
    }

    if (i % 8 != 0)
        cout << endl;
}

*/

void shell_sort(int array[], int n)
{
    
    int i;
    int g;
    int j;
    int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
    
    g = 0;
    
    while
        ( g < 8)
    {
        
        int gap = gaps[g];
        i = gap;
        
        
        
        while ( i < n)
        {
            int temp = array[i];
            j = i;
            
            
            while ( j >= gap && array[j-gap] > temp)
            {
                array[j] = array[j-gap];
                j = j - gap;
                
                
            }
            
            array[j] = temp;
            
            i = i + 1;
        }
        
        g = g + 1;
        
    }
}
