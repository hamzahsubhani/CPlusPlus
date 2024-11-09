#include <iostream>

using namespace std;

bool windback(int a[], int b[], int len, int num_steps);
/*
static void print_arrays(int a[], int b[], int len, int num_steps)
{
    int i;

    cout << num_steps << " steps: a[] = {";
    for (i = 0; i < len-1; i++)
        cout << a[i] << ", ";
    cout << a[len-1] << "}; b[] = {";
    for (i = 0; i < len-1; i++)
        cout << b[i] << ", ";
    cout << b[len-1] << "}" << endl;
}

int main()
{
    int a1[] = {1, 2, 3}, b1[3];
    windback(a1, b1, 3, 1);
    print_arrays(a1, b1, 3, 1);

    int a2[] = {1, 2, 3, 4}, b2[4];
    windback(a2, b2, 4, 3);
    print_arrays(a2, b2, 4, 3);

    int a3[] = {1, 2}, b3[2];
    windback(a3, b3, 2, 0);
    print_arrays(a3, b3, 2, 0);

    int a4[] = {1, 2, 3, 4}, b4[4];
    windback(a4, b4, 4, 5);
    print_arrays(a4, b4, 4, 5);

    return 0;
}
*/
bool windback(int a[], int b[], int len, int num_steps)
{
    // Check for invalid inputs
    if (len < 1 || num_steps < 0) {
        return false;
    }

    // Normalize num_steps to handle cases where it exceeds len
    num_steps = num_steps % len;

    // If num_steps is zero, copy a to b directly
    if (num_steps == 0) {
        for (int i = 0; i < len; i++) {
            b[i] = a[i];
        }
        return true;
    }

    // Perform the winding back
    for (int i = 0; i < len; i++) {
        b[i] = a[(i - num_steps + len) % len]; // Adjust the index for winding back
    }

    return true;
}

