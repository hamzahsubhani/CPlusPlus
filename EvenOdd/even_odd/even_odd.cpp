#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int result;

   
    cout << "Enter an integer value: "<< endl;
    cin >> result;

    if (result == 0)
    {
        cout << "The value cannot be 0." << endl;
    }
    else if (result % 2 == 0)
    {
        cout << "The value " << result << " is EVEN. " << endl;
    }
    else
    {
        cout << "The value " << result << " is ODD. " << endl;
    }

    return 0;
}
