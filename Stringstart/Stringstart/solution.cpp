#include <iostream>
#include <cstring>

using namespace std;

bool starts_with(const char*, const char*);

/*
int main()
{
    cout << "Test 1: ";
    if (starts_with("your house", "your"))
        cout << "PASSED - \"your house\" starts with \"your\"\n";
    else
        cout << "FAILED - \"your house\" starts with \"your\"\n";

    cout << "Test 2: ";
    if (!starts_with("my house", "your"))
        cout << "PASSED - \"my house\" does not start with \"your\"\n";
    else
        cout << "FAILED - \"my house\" does not start with \"your\"\n";

    cout << "Test 3: ";
    if (!starts_with("you", "your"))
        cout << "PASSED - \"you\" does not start with \"your\"\n";
    else
        cout << "FAILED - \"you\" does not start with \"your\"\n";

    cout << "Test 4: ";
    if (starts_with("your", "you"))
        cout << "PASSED - \"your\" starts with \"you\"\n";
    else
        cout << "FAILED - \"your\" starts with \"you\"\n";

    return 0;
}
*/
bool starts_with(const char* s, const char* prefix)
{
    
    size_t prefix_length = strlen(prefix);
      size_t s_length = strlen(s);
    
    if (prefix_length > s_length)
    {
        return false;
    }
    
    for (size_t i = 0; i < prefix_length; i++)
    {
           if (s[i] != prefix[i]) {
               return false;  // Return false on the first mismatch
           }
       }
       
    return true;
}
