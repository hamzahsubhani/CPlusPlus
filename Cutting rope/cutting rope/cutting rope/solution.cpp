#include <iostream>

using std::cout;
using std::endl;

int cutting_rope(int a[], int n, int sum);

void print_array(int a[], int n)
{
    int i;

    for (i = 0; i < n; i ++)
        cout << a[i] << ' ';
}

/*
int main()
{
    int a[100], n, sum;

    a[0] = 1; a[1] = 2; a[2] = 1; a[3] = 2; n = 4; sum = 2; // 1
    print_array(a, n);
    cout << " sum = " << sum << endl;
    cout << cutting_rope(a, n, sum) << endl << endl;

    a[0] = 1; a[1] = 2; a[2] = 1; a[3] = 2; n = 4; sum = 1; // -1
    print_array(a, n);
    cout << " sum = " << sum << endl;
    cout << cutting_rope(a, n, sum) << endl << endl;

    // sum = 1  --> 3
    // sum = 3  --> 2
    // sum = 6  --> 1
    // sum = 10 --> 0
    a[0] = 2; a[1] = 4; a[2] = 1; a[3] = 0; a[4] = 3; n = 5;
    for (sum = 1; sum <= 12; sum++)
    {
        print_array(a, n);
        cout << " sum = " << sum << endl;
        cout << cutting_rope(a, n, sum) << endl << endl;
    }

    return 0;
}
*/ 
int cutting_rope(int a[], int n, int sum)

{
    int lowest = 0;
    int highest = 0;

       
       for (int i = 0; i < n; i++) {
           if (a[i] > highest) {
               highest = a[i];
           }
       }

      
       while (lowest <= highest) {
           int mid = (lowest + highest) / 2;
           int total_cut = 0;

          
           for (int i = 0; i < n; i++) {
               if (a[i] > mid) {
                   total_cut += (a[i] - mid);
               }
           }

           
           if (total_cut == sum) {
               return mid;
           }
           
           else if (total_cut > sum) {
               lowest = mid + 1;
           }
          
           else {
               highest = mid - 1;
           }
       }

      
       return -1;
}
