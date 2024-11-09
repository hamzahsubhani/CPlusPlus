#include <iostream>
#include <string>

using namespace std;

int roman_to_decimal(const string&);
/*
int main()
{
    cout << "I:         " << roman_to_decimal("I") << endl;
    cout << "IV:        " << roman_to_decimal("IV") << endl;
    cout << "VIII:      " << roman_to_decimal("VIII") << endl;
    cout << "X:         " << roman_to_decimal("X") << endl;
    cout << "XXXIX:     " << roman_to_decimal("XXXIX") << endl;
    cout << "CDXC:      " << roman_to_decimal("CDXC") << endl;
    cout << "CCXLVI:    " << roman_to_decimal("CCXLVI") << endl;
    cout << "DCCLXXXIV: " << roman_to_decimal("DCCLXXXIV") << endl;
    cout << "MCMXVIII:  " << roman_to_decimal("MCMXVIII") << endl;
    cout << "MMMCMXCIX: " << roman_to_decimal("MMMCMXCIX") << endl;

    return 0;
}
*/
int value_of_roman_char(char roman_char) {
    switch (roman_char) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0; // In case of an invalid character
    }
}

int roman_to_decimal(const string& roman_value)
{
    int decimal_value = 0;
    int previous_value = 0;

   
    for (int i = roman_value.size() - 1; i >= 0; --i) {
        int current_value = value_of_roman_char(roman_value[i]);

        
        if (current_value < previous_value)
        {
            decimal_value -= current_value;
        } else
        {
            decimal_value += current_value;
        }

        
        previous_value = current_value;
    }

    return decimal_value;
}

