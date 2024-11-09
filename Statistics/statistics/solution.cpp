#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int minimum(int array[], int n);
int maximum(int array[], int n);
int range(int array[], int n);
double average(int array[], int n);
double median(int array[], int n);
double stddev(int array[], int n);

int main()
{
    int a1[10] = {66, 68, 70, 72, 75, 84, 86, 86, 89, 92};
    int a2[9] = {59, 66, 68, 70, 72, 75, 86, 89, 92};
    int a3[20] = {47, 49, 51, 52, 60, 65, 67, 68, 71, 72, 77, 78, 79, 80, 83, 84, 85, 86, 89, 100};
    int n;
    
    cout << fixed << setprecision(2);
    
    n = 10;
    
    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a1, n) << '\n';
    cout << "Maximum Value:      " << maximum(a1, n) << '\n';
    cout << "Range:              " << range(a1, n) << '\n';
    cout << "Average:            " << average(a1, n) << '\n';
    cout << "Median:             " << median(a1, n) << '\n';
    cout << "Standard Deviation: " << stddev(a1, n) << '\n';
    cout << endl;
    
    n = 9;

    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a2, n) << '\n';
    cout << "Maximum Value:      " << maximum(a2, n) << '\n';
    cout << "Range:              " << range(a2, n) << '\n';
    cout << "Average:            " << average(a2, n) << '\n';
    cout << "Median:             " << median(a2, n) << '\n';
    cout << "Standard Deviation: " << stddev(a2, n) << '\n';
    cout << endl;

    n = 20;
    
    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a3, n) << '\n';
    cout << "Maximum Value:      " << maximum(a3, n) << '\n';
    cout << "Range:              " << range(a3, n) << '\n';
    cout << "Average:            " << average(a3, n) << '\n';
    cout << "Median:             " << median(a3, n) << '\n';
    cout << "Standard Deviation: " << stddev(a3, n) << '\n';
    cout << endl;

return 0; 
}
 
double average(int array[], int n)
{
    double sum = 0;
    double average = 0.00;

    for(int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    
    average = sum / n;
    
    return average;
}

double median(int array[], int n)
{
    int sum = 0;
    for (int y = 0; y < n; y++)
    {
        sum += array[y];
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap the elements
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    
    if (n % 2 != 0)
        return (double)array[n/2];
    
    return (double)(array[(n-1)/2] + array[n/2])/2.0;
    
}

double stddev(int array[], int n)
{
    if (n == 0) return 0; // Handle division by zero if n is zero

      int sum = 0;
      for (int i = 0; i < n; i++)
          sum += array[i];

      double mean = sum / n;

      double sqDiff = 0;
      for (int i = 0; i < n; i++)
          sqDiff += (array[i] - mean) * (array[i] - mean);

      double variance = sqDiff / n;
      return variance * variance;
    
}

int minimum(int array[], int n)
{
    
    int min = array[0];
    
    for (int i = 0; i < array[n]; i++)
    {
        if (array[n] < min)
        {
            array[n] = min;
            cout << min;
        }
        
            
    }
    
    return min;
}


int maximum(int array[], int n)
{
    int i;
    
       // assigning  maximum element
       int max = array[0];
    
       // go through array elements
       // from second and compare
       // every element with current max
       for (i = 1; i < n; i++)
           if (array[i] > max)
               max = array[i];
    
       return max;
}




int range(int array[], int n) // range = maximum - minimum
{
    int range;
    int min = array[0];
    
    {
        for (int u = 0; u < array[n]; u++)
        {
            if (array[n] < min)
            {
                array[n] = min;
            }
        }
        int max = array[0];
        for (int k = 1; k < n; k++)
            if (array[k] > max)
                max = array[k];
        
        range = max - min;
        
        return range;
    }
    
    
    
}
