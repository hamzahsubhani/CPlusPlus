#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool ends_with(const char*, const char*);
/*
int main()
{
    cout << "Test 1: ";
    if (ends_with("your house", "house"))
        cout << "PASSED - \"your house\" starts with \"house\"\n";
    else
        cout << "FAILED - \"your house\" starts with \"house\"\n";

    cout << "Test 2: ";
    if (!ends_with("your mouse", "house"))
        cout << "PASSED - \"your mouse\" does not start with \"your\"\n";
    else
        cout << "FAILED - \"your mouse\" does not start with \"your\"\n";

    cout << "Test 3: ";
    if (!ends_with("use", "house"))
        cout << "PASSED - \"use\" does not start with \"house\"\n";
    else
        cout << "FAILED - \"use\" does not start with \"house\"\n";

    cout << "Test 4: ";
    if (ends_with("house", "use"))
        cout << "PASSED - \"house\" starts with \"use\"\n";
    else
        cout << "FAILED - \"house\" starts with \"use\"\n";

    return 0;
}
*/

bool ends_with(const char* s, const char* suffix)
{
    size_t suffix_length = strlen(suffix);
    size_t s_length = strlen(s);
    
    if (suffix_length > s_length)
    {
           return false;
       }
    
    size_t i = 0;
    
    while (i < suffix_length)
    {
        if (s[s_length - suffix_length + i] != suffix[i])
            return false;
        i++;
    }
        
    return true;
    
}
