#include <iostream>
using namespace std;

int main() {
    int N;

    // Ask the user to enter a positive integer value
    cout << "N value (must be positive)? ";
    cin >> N;

    // Check the validity of N
    while (N <= 0) {
        cout << "\rError: the N-value must be positive. Try again: ";
        cin >> N;
    }

    // Display the original N value
    cout << "\nOriginal: " << N << endl;

    // Display the reversed digits of N
    cout << "Reversed: ";

    while (N > 0) {
        // Extract the last digit of N using remainder
        int digit = N % 10;

        // Display the digit with leading zeros as needed
        cout << digit;

        // Update N to remove the last digit
        N /= 10;
    }

    // Print a new line at the end
    cout << endl;

    return 0;
}
