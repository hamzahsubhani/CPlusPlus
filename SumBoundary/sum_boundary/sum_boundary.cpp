#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declarations
    int lower, upper;

    // Input lower bound
    cout << "What is the lower bound? ";
    cin >> lower;

    // Input upper bound
    cout << "What is the upper bound? ";
    cin >> upper;

    // Check and swap if necessary
    if (lower > upper) {
        cout << "\n*** boundary values have been swapped ***\n";
        swap(lower, upper);
    }

    // Calculate sum
    int sum = 0;
    for (int i = lower; i <= upper; ++i) {
        sum += i;
    }

    // Display result
    cout << "\nThe sum of the values between " << lower << " and " << upper << " is " << sum << "\n";

    return 0;
}
