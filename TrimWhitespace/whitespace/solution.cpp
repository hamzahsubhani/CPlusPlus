#include <iostream>
#include <cstring>

using namespace std;

char* trim(char*, const char*);
/*
int main()
{
    char result[80];

    if (strcmp(trim(result, " \t  \nboth ends   \n\t"), "both ends") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"both ends\"\n";
    
    if (strcmp(trim(result, "trailing  \t\n"), "trailing") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"trailing\"\n";

    if (strcmp(trim(result, "\t\n\t  leading"), "leading") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"leading\"\n";

    if (strcmp(trim(result, " \t  \n\n\t"), "") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"\"\n";

    if (strcmp(trim(result, ""), "") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"\"\n";

    return 0;
}
*/
char* trim(char* destination, const char* source) {
    // Handle empty source string case
    if (source == nullptr || *source == '\0') {
        destination[0] = '\0';
        return destination;
    }

    // Find the start index of the first non-whitespace character
    int start = 0;
    while (source[start] != '\0') {
        if (source[start] != ' ' && source[start] != '\t' && source[start] != '\n') {
            break;
        }
        ++start;
    }

    // If the entire string is whitespace, return an empty string
    if (source[start] == '\0') {
        destination[0] = '\0';
        return destination;
    }
 

    // Find the end index of the last non-whitespace character
    int end = std::strlen(source) - 1;
    while (end >= 0) {
        if (source[end] != ' ' && source[end] != '\t' && source[end] != '\n') {
            break;
        }
        --end;
    }

    // Copy the trimmed characters to the destination
    int destIndex = 0;
    for (int i = start; i <= end; ++i) {
        destination[destIndex] = source[i];
        ++destIndex;
    }

    // Null terminate the destination string
    destination[destIndex] = '\0';

    return destination;
}
