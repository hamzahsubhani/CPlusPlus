//DisplayValues daily

#include <iostream>
#include <iomanip>

using namespace std;

//displayValues function prototype
void displayValues(int, int);


int main()
  {
  int numValues, startValue;
  
  //Get the number of values to display and the first value to display
  cout << "How many values should be displayed? ";
  cin >> numValues;

  cout << "What is the starting display value? ";
  cin >> startValue;


  //Call the function 4 times
  for( int testNum = 1; testNum <= 4; testNum++ )
    {
        cout << endl << "Test " << testNum << ": " << numValues << " values starting from " << startValue << endl;
    displayValues(numValues, startValue);
    
    //alter the number of values to display and the starting display value
    numValues -= 3;
    startValue += 7;
    }

  return 0;
  }

//Code the displayValues function below this line

void displayValues(int numValues, int startValue)
{
    int i;
    if (numValues < 0)
    {
        cout << "*** Invalid Number of Values ***" << endl;
    }
    else
    {
        for (i = 0; i < numValues; i++)
        {
            cout << startValue + i << " "; // Display each value with a space in between
        }
        cout << endl; // Add a newline after displaying all values
    }
}
