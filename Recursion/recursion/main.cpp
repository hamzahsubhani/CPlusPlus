#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int);

int main()
{
    int n = 10;
    int result = factorial(n); // Store the result of the factorial

    cout << "The factorial of " << n << " is " << result << endl; // Print the result

    return 0; // Add return statement for main
}

int factorial(int n)
{
    if (n == 0 || n == 1) // Handle the case for 0 as well
        return 1;
    else
        return n * factorial(n - 1); // Recursive function call
}
