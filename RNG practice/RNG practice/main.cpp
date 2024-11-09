#include <iostream>
#include <cstdlib>
#define MIN 30
#define MAX 50
#define MAX2 90
#define MIN2 70
using namespace std;

int main() {
    cout << "Please enter in a character: ";
    char user_input;
    cin >> user_input;

    int result;
    if (user_input == 'A') {
        result = rand() % (MAX - MIN + 1) + MIN;
    } else {
        result = rand() % (MAX2 - MIN2 + 1) + MIN2;
    }

    cout << result << endl;
    
    

    return 0;
}
