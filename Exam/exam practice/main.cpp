#include <iostream> // cin , cout , endl
#include <iomanip> // setw fixed setprecision
#include <fstream> // used for reading and writing files (ifstream, ofstream)
#include <cstdlib> // srand , rand, same as stdlib.h
#include <stdlib.h> // like cstdlib
#include <string> // access to the C++ standard string class and related functions for string manipulation.
#include <numeric> // GCD for frations (NOT AS IMPORTANT)
#include <cctype> // includes isalpha, isdigit, tolower, toupper
#include <cstring> // strlen, strcpy, strcmp,
#define slacker "yippie" // example of defining a c style symbolicconstant string
#define number 240// c style symblic constant integer



using namespace std; // specified which tools from the above libraries we would liek to use, "give me everything"

// int getsome integer(): // get will not have an argument
// bool setSomeInteger(int): // set will have an argument


char getAns( char &letter)
{
    if ( letter >= 'A' && letter <= 'D')
    {
        cout << " success !" << endl;
        cout << " your letter was " << letter << endl;
    }
    else
    {
        do
        {
            cout <<" error :(  try again ";
            cin >> letter;
        }
        while
            (
             letter > 'D'
             );
    }
    return letter;
}
    
    
    //int fn (int);
    int domath (int x,  int y)
     
     {
     int sum;
     sum = x + y;
        cout << sum << endl;
     
     return sum;
     }
     

 
   
   
   
 
     
 
 
    
   
    
     
     // working with function prototypes, bodies, references
     
     void work (int &x )
     {
     cout << x << endl;
     x++; //increment x by 1
     cout << x << endl << endl;
     }
     
     void swap ( int & c , int & y)
     {
     int temp = c; // swapping the c and y values
     c = y;
     y = temp;
     
     }

void foo (string str)
{
   
    str = "prithvi";
    cout << str << endl;
}
    
void fooWithReference (string &str)
{
   
    str = "prithvi";
    cout << str << endl;
}

struct Point
{
    int x;
    int y;
};

void modifyPoint(Point& point, int new_x, int new_y) 
{
    point.x = new_x;
    point.y = new_y;
}

struct Person 
{
    string name;
    int age;
};


    int main ()
{
        const int ARRAY_SIZE = 3;

           // Declare an array of Person
           Person people[ARRAY_SIZE];

           // Initialize elements of the array
           people[0].name = "Alice";
           people[0].age = 30;

           people[1].name = "Bob";
           people[1].age = 25;

           people[2].name = "Charlie";
           people[2].age = 35;

           // Access and print individual structs and their data members
           for (int i = 0; i < ARRAY_SIZE; ++i) {
               cout << "Person " << i+1 << ": Name = " << people[i].name
                    << ", Age = " << people[i].age << endl;
           }

           // Access and print data members of a specific struct
           cout << "Data members of the first person:" << endl;
           cout << "Name = " << people[0].name << endl;
           cout << "Age = " << people[0].age << endl;
        
        
       
        Point p = {3, 4};

            // Display the original values
            std::cout << "Original values: x = " << p.x << ", y = " << p.y << std::endl;

            // Modify the fields of the Point structure using the function
            modifyPoint(p, 5, 6);

            // Display the modified values
            std::cout << "Modified values: x = " << p.x << ", y = " << p.y << std::endl;
        
       /* int y = 6;
        int x = 10;
        domath(6, 10);
        
        string statement = "yippie!";
        for (int i = 5; i <= 13; i++)
        {
            cout << statement << endl;
        }

        
       int randomnum[100];
        srand(time(0));
        for (int i = 0; i < 100; i++)
        {
            randomnum[i]= (rand() % 61 - 10) + 15;
            cout << randomnum[i] << endl;
        }
      
        for (int i = 0; i < 30; i++)
        {
            cout << (rand() % 201) * 2 << endl;
        }
*/
        
        char str[] = "Hello";
        cout << strlen(str) << endl;


        int arr4[] {1, 2, 3};
        for (int i = 0; i < 3; i++)
        {
            
            cout << arr4[i] << endl;
        }

        
        
        
        /*
         int - negative or positive number between -21 and 2.1 billion
         unsinged int - exclusively non neg numbers between 00 and 4.2 billion
        
         float and double represent real numbers with decimal points. double has more precision
         char - single ASCII chracters represented by a valur
         string - an array of cgaracter values
         bool - true or false data ONLY.
         cout << standard output stream , different from when we would extract data from the user (cin)
         cin >> input stream operator
         endl and \n do the same thing - print a newline.
        
         
         CONDITIONAL STATEMENTS
         if statements - more used
         switch - less commonly used
         
         both allow code to only be executed if an associated relational expression evalues to true
         if (slacker <0)
         {
         
         cout << "slacker is positive.";
         }
         else
         {
         cout <<"slacker is negative.";
         }
         compound relational expression
         if (slacker > 0 && (slacker % 30 ==0) ) // the and or && operator requires both relational expressions to be true for the code to execute
         if (slacker > 0 || (slacker % 30 ==0) ) // this is different because it has the or operator, which only executes the code if ONE of the relational expressions is true, not both.
         == equality operator
         = assignment operator (always true)
         switch statements are great for whenever we are tested for direct equality to a great umber of potentioanl outcomes.
         
         switch (slacker)
         {
         case (0):
         cout <<"yes.";
         break; // escape mechanism ; breaks you out of whatever coding structure the program is currently in.
         default :
         cout << "this is the default statement";
         break;
         }
         
         FOR LOOPS
         for ( initialization; condition; updation )
         for (int i = 0; i < N; i++) // this code will run an N number of times
         
         while loop is a "top driven" loop, because the condtion is checked at the top of the loop
         while (!inFile.eof())
         {
        //do stuff
         inFile >> slacker;
         }
         
         do
         {
         
         //stuff
         
         } while (i < N);
         
       RANDOM NUMBER GENERATION PRACTICE
    when generating a random number , we can use the data type "rand". This will generate a random number.
    however, when you try to output this number ( cout << rand() )  you will keep getting the  the same number.
    in order to get a random number everytime, we need to use srand(time(0); This will ensure a number is random every single time the program runs.
    
        
        
            srand (time (0)); // seeding the srand so it generates a random number everytime
            srand (33); // produces a fixed value
            cout << rand() << endl;
            ccout << rand () % & 101 << endl; // generates random numbers in the range {0, 100}
            cout << rand () % 61 + 15 << endl; // this will generate nubers between 15 amd 75
         
         ARRAYS
         these are ways in which we can allocate LOTS of variables all at oncee
         the first element of the array is always found at subscript 0 or [0]
         the last legal subscript value you can use for the elemnts of an array is the maximum array size - 1.
         
         to write a for loop based on an array youve created in ascending order
         for (int i = 0; i < maximum_array_size; i++
         {
         cout << array[i] << endl;
         }
         
         the for loop below prints the array in reverse order from [size -1] to [0]
         for (int i = maximum array size -1; i>=0; i--)
         {
         cout << array[i] << endl;
         }
         
         to find the middle value of the array
         cout << array [maximum array size / 2] << endl;
         
         
         
         to find sum of all elements in an array, view this example:
         double real_numbers [10];
         double sum = 0;
         for (int i = 0; i < 10; i++)
         {
         sum += real_numbers[i];
         cout << "the average is ==" << sum / 10 << endl;
         }
         how to type cast :
         re interpret the data type as another
         if a int named slacker  is 4 and you wanna make it a double
         cout << double (slacker)
         
         // MULTI DIMENSIONAL ARRAYS are a little different. They store multiple lists of data instead of one.
         
         the syntax for a multidimensional array is shown below :
         
         
         int A[2][2] = {{1, 2}, {3, 4}};
         for (int k = 0; k < 2; k++)
         {
         for (int g = 0; g < 2; g++)
         {
         cout << A[k][g] << " ";
         }
         cout << endl;
         }
         
         int r[6][6] = {{1, 9, 3} , {4, 9, 6}};
         for (int y = 0; y < 3; y++)
         {
         for (int u = 0; u < 3; u++)
         {
         cout << r[y][u];
         }
         cout << endl;
         
         
        
         
         int y[3][5] = {{1, 2, 3, 4, 5}
             ,{1, 2, 3, 4 , 5}
             ,{1, 2, 3, 4 , 5}};
         
         for (int h = 0; h < 3; h++)
         {
             for (int f = 0; f < 5; f++)
             {
                 cout <<y[h][f];
             }
             cout << endl;
         }
         
         FUNCTIONS
         
          Functions are things that can be used for anything that can be done in int main. its better than hardcoding in main because you can just call the function to do whatever you need it to do.
          
          Function prototypes and function headers are different.  A function prototype does NOT need to have
          the argument NAMES in its declaration, and can be declared before or after int main.
          // We call the pieces of information that are passed to a function, which it then uses to do its task an ARGUMENT.
          
          
          
          Function prototypes look like this : void dostuff (int, int);
          shown above, the argument name does not need to be provided in the PROTOTYPE. So, the order is 1- the functions data type, 2- the name of the function (can be whatever you want) 3- the argument TYPE without the name.
          
          
          a function HEADER is different. a Function header includes all the code necessary to be executed before I call it in main. it HAS to include the data type of the function, the name of the function, the argument type AND its name.
          The syntax of a header is like this : int dostuff (int x, int y)
          {
          
          }
          each function HEADER has to return some data type. So at the end of every function it should one of these:
          return double/float/int/string/char.
          the void data type of the function is the only exception. it does not need to return anything
          
          
          int x = 10; // this x value will be recognized by the function
          int y = 4; // this y value will be recognized by the function
         
          cout  << domath (x, y) << endl; // i dont list the actual NUMBERS or DATA TYPE that i have initialized the variables to, just the NAME ive given to the numbers.
          
          
          
          int num = 3;
          fn(num);
          cout << num;
          
         
         
         
         
         
         
         
         
        char matrix[7][7];
        int coin;
        for (int i = 0; i < 7; i++) // for every row
        {
            for (int j = 0; j < 7; j++) // for every column
            {
                coin = rand() % 2;
                matrix[i][j] = char ((int ('A') + (rand () % 26 )) * coin) +
                char ((int ('0') + (rand () % 10 )) * !coin);
                cout << setw(7) << matrix[i][j];
            }
            cout << endl;
        }
        
        char array[5] ={'a', 'b', 'c', 'd', 'e'};
        for (int i = 0; i < 5; i++)
        {
            cout << int(array[i]) << endl; // this an example of converting to an ASCII character
        }
        
        
         
         
         
         
         
         
         
         
         
         
         
        
        //  C style strings
        
        string greeting = "hello"; // this is called a string literal. greeting is an object
        cout << greeting[0] << endl; // since greeting is an array, we display the subscript just like we would a normal array
        cout << greeting + " " + "there" << endl; // combining hello with there.
        
        string complete_greeting = greeting + " there";
        cout << complete_greeting << endl;
        complete_greeting += "!";
        cout << complete_greeting << endl;
        cout << complete_greeting.length() << endl;
        
        char name[] = "caleb"; // a c style string is just an array of characters. caleb will be limited to 6 characters "caleb\0"
        // name = "t"; // wont compile
      
        ///////
        
        
        
        
        
         
         
        
        string ham = "hamzah";
        cout << ham << endl;
        foo(ham);
        cout << ham << endl;
        fooWithReference (ham);
        cout << ham << endl;
        
        ///
         
         
        // END OF PRACTICE WITH accessor methods */////////////////////////////////////////////////////////////////////////////////
        ///
        
        
        
    
    
        
        
   
        
         
         
      /*  char ar[2][7] = {{ 'A' ,'B' ,'C', 'F', 'E' ,'F' ,'G'},
            {'H', 'I', 'J', 'F', 'L', 'M', 'N'}};
        cout <<ar[0][3];
        cout <<ar[1][3];
        
        for (int o = 0; 0 <2; o++)
        {
            for (int u = 0; u<7; u++)
            {
               
            }
        }
         */
         
         //  PRACTICING INPUT FILE STREAMING
         
         // ifstream - used for reading data FROM a file. Reads data from an EXISTING file
         
         // ofstream - used for writing output for files. Whatever I write will be placed IN this file, whether it exists or doesnt (if it doesnt exist, itll just create a file that is named whatever i enter)
         
      /*   ofstream outFile; // declaring my name for the output variable.
         
         outFile.open("ballsack.txt"); // creates a filename based on whatever the user (me) entered. so if i entered "ballsack" itll make a file called ballsack and store data in it.
         if (outFile. fail ())
         {
             cout << "Error" << endl; // if the file fails to get created, then you will get this error message
             exit(-1); // just like return 0;
         }
            
         outFile <<"Woo" << endl; // this is what the file i created is gonna say inside it. you could say whatever tf you want for this.
         
         outFile.close(); // closes the output file
         
       //  now that i created this dumbahh file, lets read the data from it and then print it.
         
         ifstream inFile; // just like i did above, i gotta declare the name for it first
         
         
        inFile.open("ballsack.txt"); // this will open the file
        
        if (inFile.fail()) // if this mf fails
        {
            cout <<"Error" << endl; //  you will get this error message
            exit(-2);
        }
        
        string temp; // intializing a string variable to attach to the woo i wrote in that file
        while (inFile >> temp) // or while (!inFile.eof())
        {
        cout << temp << " "; // Print the current value
        inFile << temp; // check if there is more stuff to read
        }
        inFile.close(); // close the file to prevent reading more data
        
         */
 
        // Start of practicing using references  */////////////////////////////////////////////////////////
        
        
        /* A REFERENCE allows us to refer to some area of memory. Think of it as an "ALIAS"
         
         
         int a = 5;
         int &b = a;
         cout << a + 2 << endl;
         cout << b + 2 << endl;
         
         
         int a = 5;
         work (a);
         
         
         
         int c = 0;
         int y = 10;
         cout << "before swap: " << c <<" , " << y << endl;
         swap(c , y);
         cout << "after swap: " << c <<" , "<< y << endl;
         
         // you CANNOT use a reference twice unless you declare another variable and its value and then have the reference equal that.
         
         
         
         END OF PRACTICE WITH References */////////////////////////////////////////////////////////////////////////////////
      
       
        
         
         
        
        
        /*
         
         Exam questions that I missed
         EXAM 2
         // QUESTION 1- Print an Array in reverse order, printing last element first and first element last
         
         
         for ( int i = MAXIMUM_ARRAY_SIZE - 1 ; i >= 0 ; i-- )
         {
         cout << slacker[i]<< " ";
         }
         
         // QUESTION 2- I have a 2x2 dimensional array called matrix. complete the following for loop that wil print each of the values along the diagonal starting from the top right to the bottom left most elements
         
         char matrix[3][3] =
          {
              {'D', 'C', 'X'},
              {'F', 'X', 'V'},
              {'X', 'O', 'P'}
          };
          for (int i = 0; i < 3; ++i)
          {
              cout << matrix[i][2 - i] << endl;
          }
         Explanation: the "2- i' business represents what column we would like to print out. the i for the row stays the same beause we want to iterate over rows in sequence. since it starts fro right to left, we start with row[0]. then 2 - 0 = 2, so it will print the letter for matrix[0][2], which is the first "X".
         
         
         
         
        //  QUESTION 3- Consider the following :
         i have a void function called print that takes two arguments, an array of student objects called roster and an integer called count. complete the following function header
         void print (_______ __________________, ___________________ count)
         {
         } ( you do not need to fill in the function body)
         
         void print(Student roster[], int count) 
         {
             // Function body will be implemented here
         }
         Explanation: what i got wrong was the data type of the roster, i put string. Since it is an array of student OBJECTS i have to assume student is an an object and roster is an array.
         
       //  QUESTION 4 - consider the following function
         void swap ( ___________ x, _____________y)
         {

         string temp;
         temp = x:
         x = y:
          y = temp;
         }
         what data type fills out both blanks?
         
         void swap(string& x, string& y)
         {
             string temp = x;
             x = y;
             y = temp;
         }
         EXPLANATION: I need to use references because this is a function that will swap values that are being passed in by reference.
         legitimately swapping x and y would create separate copies and would not work with other variables
         if in int main i put
         string a = "Hello";
         string b = "World";
         and then did swap(a, b); // it wouldnt work because the function only knows x and y
         
         
        // QUESTION 5-  Consider the following scenario:
         I have a double function called gpaSearch which takes three arguments in this order : an array of student objects, a constant reference to an integer, and a string. complete the following function call
         int main()
         {
         Student roster[20];
         int size;
         string target;
         double result;
         result = gpaSearch(___________,________________,__________); (only fill in the 3 blanks)
         result = gpaSearch(roster, size, target);
         EXPLANATION: the reason i got this wrong is because i put &size. when calling a function in int main you do not need to put ay data type, just the NAME of the data type. since its int size, you only put size.
         
         
         
     // QUESTION 6- i have a class called slacker that contains a double attribute called zeta. complete the following method prototype for the two accessor methods, that control read/write access to this double attribute.
         _______getZeta________;
         ________setZeta_______;
         
         double getZeta();
         void setZeta(double value);
         EXPLANATION: i got these messed up, plain and simple. the getZeta accessor method has to be a double because it is returning a value, so it cannot be void. the setZeta has to be void because it is not returning anything, but needs an argument because it is potentially changing the argumen
         
         GOING TO EXAM 1 NOW
         
       //  QUESTION 7-
         Consider this scenario. I have an integer variable called slacker which has been given a value.
         Complete the following if-statement to resolve to be true if the value of slacker is not in the range of 100-200 exclusive, i.e. 100 and 200 are both unacceptable values.
         
         
         QUESTION 8- Consider the following scenario. I want to build a for-loop that will iterate exactly 9 times. Complete the for-header below.
         for (int i = 5; i <= ____; i++)
         for (int i = 5; i <= 13; i++)
         
         i accidentally incremented it by 2. dumb mistake. I have to remember that when i start counting i start with the integer that i have initialized to my variable. so if i = 5, i start counting from 5 until i get to 13. 5,6,7,8,9,10,11,12,13
         
         
         
    
         QUESTION 9- Consider the following scenario. I want to build a for-loop that will iterate exactly 9 times. Complete the for-header below.
         for (int i = ____; i < 25; i += 2)
         for (int i = 7; i < 25; i += 2)
         just like question 8, i need to start counting with the integer i have initialized to my variable. when i = 7, it iterates 9 times. 7, 9, 11, 13, 15, 17, 19, 21, 23
         
         
         QUESTION 10 - Consider the following scenario. I want to build a while loop that will print out every odd number from a random number generated during an N number of iterations, where N is a symbolic constant that has been declared and set equal to some arbitrary, nonnegative integer. Complete the instructions below to achieve this:
         int counter = 0, slacker;
         while (counter < _____)
         {
          // Here, slacker will be assigned a new random number

          if (slacker _____  ______ == __________) // Check if slacker is odd
           cout << slacker << " ";

          
          __________; // update the value of counter
         }
         int counter = 0, slacker;
         while (counter < N)
         {
            
             if (slacker % 2 == 1) // Check if slacker is odd . i checked if it is odd but if it has two equal signs then ! is not used in the statement.
                 cout << slacker << " ";

             counter++; // update the value of counter
         }

         QUESTION 11- Consider the following scenario. I would like to generate a "random", even number between 0 and 400, and then simply print it to standard output. You cannot write a loop or use an if-statement to accomplish this task.
         Write the one line of code that would achieve this. You may assume all necessary libraries have already been included and "used" by this program -- all you need to focus on is the instruction necessary to achieve this outlined objective.
         cout << rand () % (400 - 0 + 1) + 0
         cout << (rand() % 201) * 2 << endl;
         I did generate a number between 0 and 400 but i didnt make it even. //multiple 200 by 2 to get 400 which is the maxmium of the range, and also multiplying it by 2 to make the outcom even

         

         
         
         

         
         
         
         

         
         
         
         
    
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         */
        
        
        
    
        
        
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
        
         
        
        
        //// ARRAY PRACTICE
        
        
        
        /*    int AR[45] = {1 , 2 , 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 , 24, 25, 26 ,27,28, 29, 30, 31, 32, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};
         
         for ( int i = 0; i < 45; i++)
         {
         if ( AR[i] % 2 !=0)
         {
         cout << AR[i] << " ";
         }
         else
         {
         
         }
         }
         
         int pp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
         int temp;
         temp = pp[0];
         pp[0] = pp[9];
         pp[9] = temp;
         for (int i = 0; i < 10; i++)
         {
         cout << pp[i];
         }
         
         int yes[500] = {2, 4};
         for ( int i = 0; i < 500; i++)
         {
         cout << yes[i];
         }
         
         
         
        
        
     
        int numbers [3][4] =
            {{0, 1, 2, 3},
            {4, 5, 6, 7},
            { 8 , 9 , 10 , 11}}; // first square bracket is rows in the 2d array, second square bracket is columns in the 2d array/
        
        
     //   cout << numbers [2] [3] << endl;
        
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 4; column++)
            {
                cout <<numbers[row][column] << " ";
                
            }
            cout << endl;
        }
        
        
        
        
        char keyboard [4] [10] = {{'1' , '2' , '3', '4' , '5' , '6', '7', '8', '9', '0'}
            ,{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' }
            ,{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';'}
            ,{'Z','X', 'C', 'V', 'B', 'N', 'M', ',' , '.' ,'/' }};
        
        for (int k = 0; k < 4; k++)
        {
            for (int y = 0; y < 10; y++)
            {
                cout << keyboard[k][y] << " ";
            }
            cout << endl;
        }
      */
        
            
        
            
        
        
      /*  int myarray[5][5]; // will have 5 rows and 5 columns. this is the initialization
        int my[2][2] = {1, 2, 3, 4}; // declaration with initilization
        int my2[3][3] = {{1, 1, 1,}, {2, 2, 2,} , {3, 3, 3} }; //  declaration with initilization
     
        for ( int i = 0 ; i <3; i++)
        {
            
            
            for (int j = 0; j< 3; j++)
            {
                cout << my2 [i][j] << " " ;
            }
            cout << endl;
       
        }
       
       int values[5][9];
          
          ofstream Fileout;
          Fileout.open("mynumbers.txt");
          if (Fileout.fail()) {
              cout << "File could not be opened." << endl;
              exit(-1);
          }
       srand(time(0));
          // Write 45 random numbers to the file
          for (int i = 0; i < 5; i++) {
              for (int j = 0; j < 9; j++) {
                  Fileout << rand() % 75 + 1 << " ";
              }
              Fileout << endl;
          }
          Fileout.close();
          
          ifstream Filein;
          Filein.open("mynumbers.txt");
          if (Filein.fail()) {
              cout << "File could not be opened." << endl;
              exit(-1);
          }
       int temp = 0;
       Filein >> temp;
          // Read values from the file into the array
          for (int i = 0; i < 5; i++) {
              for (int j = 0; j < 9; j++) {
                  Filein >> values[i][j];
              }
          }
          Filein.close();
          
          // Print the values from the array
          for (int i = 0; i < 5; i++) {
              for (int j = 0; j < 9; j++) {
                  cout << values[i][j] << " ";
              }
              cout << endl;
          }

       
       be familiar with the general process of the seleiton sort algorithm.
       the selection sort algorithm sorts an aray by comparing two numbers in an array and depending on how the numbers need to be assorted, switches the two numbers positions and goes onto then next.
          */
       
       
      
        
        // random number generation practice
    //when generating a random number , we can use the data type "rand". This will generate a random number.
    //however, when you try to output this number ( cout << rand() )  you will keep getting the  the same number.
    //in order to get a random number everytime, we need to use srand(time(0); This will ensure a number is random every single time the program runs.
    //
       
       
       /*   srand (time (0)); // seeding the srand so it generates a random number everytime
        
        for (int i = 0; i < 100; i++)
        {
        //  cout << rand() % 75 + 1 << endl;
        // if i were to just have 75 without adding one, it would generate random numbers up to 74. So, whenever you put a value after rand, your program will execute random numbers up to whatever your value is -1.
        
        // So, if i wanted to make it 100, it would look like this.
        cout << rand () % 100 + 1 << endl;
        
        }
        */
       
       
       
       
       
       /*  char letter;
        cout << "please enter in a letter: ";
        cin >> letter;
        getAns(letter);
     
     
     */

     
      
                
                     return 0; // commonly our "exit point"
        
                     }
       
    
char getAns();
    
    
    void work (); // function for reference practice
    void swap (); // function for reference practice
    int domath (int, int); // function prototype practice
void cube();
    
   
    
                     
