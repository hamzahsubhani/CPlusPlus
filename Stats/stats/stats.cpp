//Compound Relational daily
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//function prototype
void stats(int num1 , int num2 , int num3);

const int START_TEST = 5;
const int NUM_TESTS = 3;

int main()
{
  int num1, num2, num3;
  int rand_num1, rand_num2, rand_num3;
    int seed_value;

  //Get three numbers to test
  cout << "What is the first number? ";
  cin >> num1;

  cout << "What is the second number? ";
  cin >> num2;

  cout << "What is the third number? ";
  cin >> num3;

  cout << endl << "What is the seed value for the random number generator? ";
  cin >> seed_value;

  //Test the function with user input
  cout << endl << "Test 1: check the \'stats\' on the numbers: " << num1 << ", " << num2 << ", and " << num3 << endl;

  stats(num1, num2, num3);


  //Test the function with known values
  cout << endl << "Test 2: check the \'stats\' on the numbers: 1, 5, and 9" << endl;

  stats(1, 5, 9);

  cout << endl << "Test 3: check the \'stats\' on the numbers: 6, 4, and 6" << endl;

  stats(6, 4, 6);

  cout << endl << "Test 4: check the \'stats\' on the numbers: 9, 5, and 1" << endl;

  stats(9, 5, 1);

  //test the function with random values
  
  //seed the random number generator with a value of 15
  srand(seed_value);

  //conduct the extra tests with the random numbers
  for(int testNum = START_TEST; testNum < START_TEST + NUM_TESTS; testNum++)
    {
    //generate the three random numbers that will be used by the test
    rand_num1 = rand();
    rand_num2 = rand();
    rand_num3 = rand();
    
    //display the heading for the test, including the random numbers
    cout << endl << "Test " << testNum << ": check the \'stats\' on the numbers: "
         << rand_num1 << ", " << rand_num2 << ", and " << rand_num3 << endl;

    //determine the stats for the 3 random numbers
    stats(rand_num1, rand_num2, rand_num3);
    }

  return 0;
}

    
    
    
    
    
    


//Code the stats function below this line
void stats(int num1, int num2, int num3)
{
    // Initialize a variable to keep track of conditions met
    int conditionsMet = 0;

    // Condition 1: The first and second numbers are both even.
    if (num1 % 2 == 0 && num2 % 2 == 0)
    {
        cout << "1 ";
        conditionsMet++;
    }

    // Condition 2: The first number is less than both the second and the third.
    if (num1 < num2 && num1 < num3)
    {
        cout << "2 ";
        conditionsMet++;
    }

    // Condition 3: The second or the third number is odd.
    if (num2 % 2 != 0 || num3 % 2 != 0)
    {
        cout << "3 ";
        conditionsMet++;
    }

    // Condition 4: Either the first or the second numbers are less than the third.
    if (num1 < num3 || num2 < num3)
    {
        cout << "4 ";
        conditionsMet++;
    }

    // Print a newline if at least one condition is met
    if (conditionsMet > 0)
    {
        cout << endl;
    }
}

