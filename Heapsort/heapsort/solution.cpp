#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

//static int build_array(int[]);
//static void print_array(int[], int);
void heap_sort(int[], int);

/*
int main()
{
    int array[1000];
    int n;
 
    n = build_array(array);

    cout << n << " elements unsorted\n\n";

    print_array(array, n);
    
    cout << endl << n << " elements in ascending order\n\n";
    
    heap_sort(array, n);
    print_array(array, n);

    return 0;
}
*/

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




void sift_down(int array[], int start, int end)

{
    
    int root = start;
    
    while ((2 * root + 1) <= end)
        
    {
        int child = (2 * root + 1);
        
        int largest = root;
        
        if (array[largest] < array[child])
        {
            largest = child;
        }
        
        if ((child + 1) <= end && array[largest] < array[child+1])
            
        {
            largest = child + 1;
        }
        
        if ( largest == root)
            
        {
            return;
        }
        
        else
        {
            std :: swap (array[root], array[largest]);
            root = largest;
        }
        
        
    }
    
    
}



void heapify(int array[], int n)

{
    
    
    
    int start = (n - 2) / 2;
    
    while (start >= 0)
        
    {
        
        sift_down(array, start, n - 1);
        
        start--;
    }
    
    
}

void heap_sort(int array[], int n )

{
    
    heapify(array , n);
    
    int end = n - 1;
    
    while ( end > 0 )
        
    {
        
        std::swap(array[end], array[0]);
        end = end - 1;
        sift_down(array, 0, end);
    }
    
    
    
    
}
