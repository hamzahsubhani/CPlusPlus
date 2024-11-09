#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int num1, num2;
    
    
    int counter = 0, slacker;
    while (counter < N)
    {
        // Here, slacker will be assigned a new random number
        
        if (slacker % 2! == 0) 
        {// Check if slacker is odd
            cout << slacker << " ";
        }
        
    
     counter++; // update the value of counter
    }

    // Ask the user to enter two integer values
    cout << "What is the first number? ";
    cin >> num1;

    cout << "What is the second number? ";
    cin >> num2;
    cout<<endl;
    // Check if both values are positive
    if (num1 > 0 && num2 > 0) {
        // Check if num1 is a multiple of num2
        if (num1 % num2 == 0) {
            cout << num1 << " is a multiple of " << num2 << endl;
        } else {
            cout << num1 << " is NOT a multiple of " << num2 << endl;
        }
    } else {
        // Display error message if either value is not positive
        cout << "*** Invalid input: one or both values is not positive" <<endl;
    }

    return 0;
}
