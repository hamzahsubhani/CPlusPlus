/********************************************************************
CSCI 240 - Assignment 6 - Spring semester 2024


Progammer: Hamzah Subhani
 Z-ID- 2010017
Section:  2
TA:      Kalpana Paramanantham
Date Due:  3/8/2024

Purpose: To Prompt the user with operations to use to preform calculations. The key difference between this program and program 5 is that the program is executed using functions instead of simple switch statments.
 Whatever function gets used is bsed on what operation the user wants to preform.
*********************************************************************/
#include <iostream>
#include <string> // will be used in our getvalue functions to replace cout

bool firstTime = true; // used for displaying "next operation?" when menu loops more than once

using namespace std;

// declaring function prototypes so they can be used after int main.
int addition(int value1, int value2);
int subtraction(int value1, int value2);
int multiplication(int value1, int value2);
int quotient(int value1, int value2);
int remainder(int value1, int value2);
int power(int base, int exponent);
int factorial(int value);
int getValue(string prompt);
int getNonNegativeValue(string prompt);
int getNonZeroValue(string prompt);
char menu();

int main() {
    char userDecision;

    do {
        userDecision = menu();

        //the switch statment below will now utilize functions that are being called instead of having the code executed in it.
        switch (userDecision)
        {
            case '+': {
                int value1 = getValue("What is the first number to add? ");
                cout << endl;
                int value2 = getValue("What is the second number to add? ");
                cout << endl;
                addition(value1, value2);
                break;
            }

            case '-': {
                int value1 = getValue("What is the first number to subtract? ");
                cout << endl;
                int value2 = getValue("What is the second number to subtract? ");
                cout << endl;
                subtraction(value1, value2);
                break;
            }

            case '*': {
                int value1 = getValue("What is the first number to multiply? ");
                cout << endl;
                int value2 = getValue("What is the second number to multiply? ");
                cout << endl;
                multiplication(value1, value2);
                break;
            }

            case '/': {
                int dividend = getValue("What is the dividend? ");
                cout << endl;
                int divisor = getNonZeroValue("What is the divisor? ");
                cout << endl;
                quotient(dividend, divisor);
                remainder(dividend, divisor);
                break;
            }

            case '^': {
                int base = getValue("What is the base number? ");
                cout << endl;
                int exponent = getNonNegativeValue("What is the power? ");
                cout << endl;
                power(base, exponent);
                break;
            }

            case '!': {
                int value = getNonNegativeValue("What is the number? ");
                cout << endl;
                factorial(value);
                break;
            }

            case 'q':
            case 'Q':
                return 0;

            
        }

        firstTime = false; // Set firstTime to false after the first iteration

    } while (userDecision != 'q' && userDecision != 'Q');

    return 0;
}




/***************************************************************
Function: addition

Use:   Adds two integers together that are entered by the user.

Arguments: 1. value1- first integer used in addition. value2- second integer used in addition.
 

Returns:   The sum of the two integer values
***************************************************************/
int addition(int value1, int value2)
{
    int result = value1 + value2;
    cout << value1 << " + " << value2 << " = " << result << endl;
    cout << endl;
    return result;
}





/***************************************************************
Function: subtraction

Use:   Subtracts the second integer from the first integer to display the difference between the two.

Arguments: 1. value1- first integer used in subtraction. value2- second integer used to subtract from first integer.
 

Returns:   The difference of the two integer values
***************************************************************/

int subtraction(int value1, int value2) 
{
    int result = value1 - value2;
    cout << value1 << " - " << value2 << " = " << result << endl;
    cout << endl;
    return value1 - value2;
}



/***************************************************************
Function: multiplication

Use:   Multiplies two values together that are entered by the user to form a product.

Arguments: 1. value1- first integer used in multiplication. value2- second integer used in multiplication.
 

Returns:   The product of the two integer values
***************************************************************/

int multiplication(int value1, int value2)
{
    int result = value1 * value2;
    cout << value1 << " * " << value2 << " = " << result << endl;
    cout << endl;
    return value1 * value2;
}





/***************************************************************
Function: quotient

Use:   Divides the second integer from the first integer to form a quotient.

Arguments: 1. value1- first integer used in division. value2- second integer divided from first integer.
 

Returns:   The quotient of the two integer values
***************************************************************/

int quotient(int value1, int value2) 
{
    int result = value1/ value2;
    cout << value1 << " / " << value2 << " = " << result << endl;
    return value1 / value2;
}





/***************************************************************
Function: remainder

Use:   Takes the modulus of the first integer from the second integer to get a remainder, if present.

Arguments: 1. value1- first integer used in remainder function. value2- second integer to divide from value1 to determine a remainder
 

Returns:   The sum of the two integer values
***************************************************************/



int remainder(int value1, int value2) 
{
    int result = value1 % value2;
    cout << value1 << " % " << value2 << " = " << result << endl;
    cout << endl;
    return value1 % value2;
}

/***************************************************************
Function: power

Use:   Raises the entered base number to an entered exponent to calculate a result.

Arguments: 1. base - integer representing the base value. exponent- integer representing the power that the base number will be raised to.
 

Returns:   The result of a base raised to the power of an exponent
***************************************************************/
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) 
    {
        result *= base;
    }
    cout << base << "^" << exponent << " = " << result << endl;
    cout << endl;
    return result;
}








/***************************************************************
Function: factorial

Use:   Calculates the factorial of an integer entered by the user by using a for loop to multiply all the numbers that ascend up to the entered integer.

Arguments:
  1. value - an integer for which the factorial is calculated.

Returns:
  The factorial of the given integer .
***************************************************************/
int factorial(int value) {
    int result = 1;
    for (int i = 1; i <= value; i++)
    {
        result *= i;
    }
    cout << value << "! = " << result << endl;
    cout << endl;
    
    return result;
}


/***************************************************************
Function: getValue

Use:   obtains an integer from the user with a displayed prompt.

Arguments:
  prompt - a string containing the prompt to display to the user, similar to the cout statement.

Returns:
  An integer value entered by the user.
***************************************************************/

int getValue(string prompt) {
    int userValue;

    cout << prompt;
    cin >> userValue;

    return userValue;
}



/***************************************************************
Function: getNonNegativeValue

Use:   obtains a non-negative integer from the user with a displayed prompt.

Arguments:
  prompt - a string containing the prompt to display to the user.

Returns:
  A non-negative integer value entered by the user.
***************************************************************/
int getNonNegativeValue(string prompt)
{
    int userValue;

    cout << prompt;
    cin >> userValue;

    while (userValue < 0) {
        cout << "Error: the value cannot be negative. Try again: ";
        cin >> userValue;
    }

    return userValue;
}

/***************************************************************
Function: getNonZeroValue

Use:   obtains a non-zero integer from the user with a displayed prompt.

Arguments:
  prompt - a string containing the prompt to display to the user.

Returns:
  A non-zero integer value entered by the user.
***************************************************************/

int getNonZeroValue(string prompt)
{
    int userValue;

    cout << prompt;
    cin >> userValue;

    while (userValue == 0) {
        cout << "Error: the value cannot be zero. Try again: ";
        cin >> userValue;
    }

    return userValue;
}


/***************************************************************
Function: menu

Use:   Displays a menu of operations to the user and asks for their desired operation.

Returns:
  A character representing the user's chosen operation.
***************************************************************/
char menu() {
    char decision;

    cout << "What operation would you like to perform:" << endl;
    cout << "+ addition" << endl;
    cout << "- subtraction" << endl;
    cout << "* multiplication" << endl;
    cout << "/ division" << endl;
    cout << "^ number to power" << endl;
    cout << "! factorial" << endl;
    cout << "q quit" << endl;
    cout << endl;

    if (firstTime) 
    {
        cout << "Operation? ";
    } 
    else
    {
        cout << "Next Operation? ";
    }

    //do while statement evaluates input from user to see if it matches what is valid to be entered
    do {
        cin >> decision;
        cout << endl;
        if (!(decision == '+' || decision == '-' || decision == '*' || decision == '/' ||
              decision == '^' || decision == '!' || decision == 'q' || decision == 'Q')) {
            cout << "Error: that is an invalid operation. Try again: ";
        }
    } while (!(decision == '+' || decision == '-' || decision == '*' || decision == '/' ||
               decision == '^' || decision == '!' || decision == 'q' || decision == 'Q'));

    return decision;
}
