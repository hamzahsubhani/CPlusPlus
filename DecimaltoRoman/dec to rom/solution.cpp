#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string decimal_to_roman(int number);
/*
int main() {
    cout << "1:    " << decimal_to_roman(1) << endl;
    cout << "14:   " << decimal_to_roman(14) << endl;
    cout << "26:   " << decimal_to_roman(26) << endl;
    cout << "39:   " << decimal_to_roman(39) << endl;
    cout << "247:  " << decimal_to_roman(247) << endl;
    cout << "789:  " << decimal_to_roman(789) << endl;
    cout << "160:  " << decimal_to_roman(160) << endl;
    cout << "227:  " << decimal_to_roman(227) << endl;
    cout << "1099: " << decimal_to_roman(1099) << endl;
    cout << "1918: " << decimal_to_roman(1918) << endl;
    cout << "1954: " << decimal_to_roman(1954) << endl;
    cout << "3999: " << decimal_to_roman(3999) << endl;

    return 0;
}
*/
string decimal_to_roman(int number) {
    if (number <= 0 || number > 3999) {
        return "Invalid"; // Roman numerals are typically only valid for 1 to 3999
    }

    // Define arrays for the values and their corresponding Roman numerals
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result;
    
    // Iterate through the values and build the Roman numeral representation
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        while (number >= values[i]) {
            result += numerals[i];  // Append the corresponding numeral
            number -= values[i];     // Decrease the number
        }
    }

    return result;
}
