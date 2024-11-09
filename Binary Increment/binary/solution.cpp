#include <iostream>

using namespace std;

void binary_increment(int a[], int len);
/*
static void print_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i ++)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    int a[100], len;

    a[0] = 1; a[1] = 0; len = 2;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;
    
    a[0] = 0; a[1] = 0; a[2] = 0; len = 3;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    a[0] = 1; a[1] = 0; a[2] = 1; a[3] = 0; a[4] = 1; len = 5;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    a[0] = 1; a[1] = 0; a[2] = 1; a[3] = 1; len = 4;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    return 0;
}
 */
void binary_increment(int a[], int len)
{
    
    int rightMost = len - 1;
    bool incdone = false;
    
    for (int i = rightMost; i >=0;  i--)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            incdone = true;
            break;
        }
        
        if (a[i] == 1)
        {
            a[i] = 0;
            continue;
        }
       
    }
    
    if (incdone == false)
    {
        for ( int j = len - 1; j>=1; j--)
        {
            a[j] = a[j-1];
        }
        
        a[0] = 1;
    }
    
}
