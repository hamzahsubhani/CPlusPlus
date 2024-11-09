#include <iostream>
#include <string>

using namespace std;

bool ispalindrome(const string&);

int main()
{
    if (ispalindrome("noon"))
        cout << "PASSED - \"noon\" is a palindrome\n";
    else
        cout << "FAILED - \"noon\" is a palindrome\n";

    if (!ispalindrome("                 norton"))
        cout << "PASSED - \"                 norton\" is not a palindrome\n";
    else
        cout << "FAILED - \"                 norton\" is not a palindrome\n";

    if (ispalindrome("level"))
        cout << "PASSED - \"level\" is a palindrome\n";
    else
        cout << "FAILED - \"level\" is a palindrome\n";

    if (ispalindrome("     noon     "))
        cout << "PASSED - \"     noon     \" is a palindrome\n";
    else
        cout << "FAILED - \"     noon     \" is a palindrome\n";

    if (ispalindrome("taco cat"))
        cout << "PASSED - \"taco cat\" is a palindrome\n";
    else
        cout << "FAILED - \"taco cat\" is a palindrome\n";

    if (!ispalindrome("taco rat"))
        cout << "PASSED - \"taco rat\" is not a palindrome\n";
    else
        cout << "FAILED - \"taco rat\" is not a palindrome\n";

    if (ispalindrome("A man, a plan, a canal... Panama!"))
        cout << "PASSED - \"A man, a plan, a canal... Panama!\" is a palindrome\n";
    else
        cout << "FAILED - \"A man, a plan, a canal... Panama!\" is a palindrome\n";

    return 0;
}
 

bool ispalindrome(const string& str)

{
    string num = to_string(n);
      int len = num.length();
      bool check = false;
      for(int i=0; i < len/2; i++){
        if(num[i] == num[len - 1 -i])
        check = true;
      }
      return check;
    
}
