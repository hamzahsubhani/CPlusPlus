#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int N;

    // Get the value for N
    cout << "N value (must be greater than or equal to 0)? ";
    cin >> N;

    // Check for validity of N
    if (N < 0 || N > 12) {
        // Display error message for invalid N
        cout << "\nInvalid Input: " << N << "\n";
        return 0;
    }

    // Calculate factorial and count digits
    int factorial = 1, digits = 0;
    for (int i = 1; i <= N; ++i) {
        factorial *= i;
    }

    int temp = factorial;
    while (temp > 0) {
        temp /= 10;
        ++digits;
    }

    // Display the result
    cout << "\n" << N << "! is equal to " << factorial << ". There are " << digits << " digits.\n";

    return 0;
}
