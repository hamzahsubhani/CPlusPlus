/***************************************************************
CSCI 240         Program 9     Spring 2024

Name:   Hamzah Subhani
Z-ID: 2010017
Section: 2
TA: Sathwik
Due Date: 4/26/2024

Purpose: This program will be used to represent a collection of coins.  Functionality will be added to the class so that coins can be added to the bank and output operations can be performed. This time, extra constructors will be added to increase overall usabaility with the program, as well as new methods and a new function.
***************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;


//*************** Place the class description after this line ***************


//****************************************************************************

void printSectionTitle(string title); // new function

class PiggyBank // this is what will be called before every method

{
    
private:
    int numPennies;
    int numNickels;
    int numDimes;
    int numQuarters;
    
public:
    PiggyBank();
    
    // new constructors
    PiggyBank (int, int, int, int);
    PiggyBank(const PiggyBank &otherBank);
    //
    
    void printBank();
    void printBankValue();
    void emptyTheBank();
    void addCoins(int, int, int , int);
    int morePennies, moreQuarters, moreDimes, moreNickels;
    void addPennies (int morePennies);
    void addNickels(int moreNickels );
    void addDimes(int moreDimes);
    void addQuarters (int moreQuarters);
    double calcBankValue(); 
    
    // new method prototypes
    void print (string);
    PiggyBank addBanks (int, int, int, int);
    PiggyBank addBanks(PiggyBank otherBank);
    bool isEqual(int, int, int, int);
    bool isEqual(PiggyBank otherBank);
    bool isLessThan(int, int, int, int);
    bool isLessThan(PiggyBank otherBank);
    int getCoin(int coinIndex);
    //
}; // end of class description


int main() 
{
    // declaring objects with PiggyBank class
    PiggyBank bank1(12, 34, 56, 78);
    PiggyBank bank2(23, -5, -10, 31);
    PiggyBank bank3 = bank1; // copy constructor usage
    
    printSectionTitle("Initial values in the bank objects"); // every single time i make a title a line will come before it to separate and organize the output of the program
    // all the print statements will just print the contents (monetary value) of each bank that ive declared as an object
    bank1.print("bank1 object contains");
    cout << endl;
    bank2.print("\nbank2 object contains");
    cout << endl;
    bank3.print("\nbank3 object contains");
    cout << endl;
    
    printSectionTitle("Using the addBanks method with 4 arguments");
    PiggyBank bank4(0, 0, 0, 0);
    bank4.print("initial bank4 value");
    cout << endl;
    bank4 = bank2.addBanks(4, 27, 45, 7);
    bank2.print("\nbank2 values after using addBanks method");
    cout << endl;
    bank4.print("\nbank4 values after using addBanks method");
    cout << endl;
    
    printSectionTitle("Using the addBanks method with PiggyBank object");
    PiggyBank bank5;
    bank1.print("bank1 object contains");
    cout << endl;
    bank2.print("\nbank2 object contains");
    cout << endl;
    bank5.print("\nbank5 object contains");
    cout << endl;
    bank5 = bank1.addBanks(bank2);
    bank1.print("\nbank1 object contains");
    cout << endl;
    bank2.print("\nbank2 object contains");
    cout << endl;
    bank5.print("\nbank5 object contains");
    cout << endl;
    
    cout << endl;
    
    printSectionTitle("Using the isEqual method with 4 arguments");
    PiggyBank compare1(27, 27, 45, 38);
    bool equalResult = bank4.isEqual(compare1);
    if (equalResult) // if it is true that the banks are equal, a message will be displayed saying so. If not, it will say they are not equal. this will be used often starting here
    {
        cout << "banks are equal" << endl;
    }
    else
    {
        cout << "banks are not equal" << endl;
    }
    PiggyBank compare2(35, 34, 15, 7);
    bool equalResult2 = bank5.isEqual(compare2);
    if (equalResult2)
    {
        cout << "banks are equal" << endl;
    }
    else
    {
        cout << "banks are not equal" << endl;
    }
    cout << endl;
    
    printSectionTitle("Using the isEqual method with PiggyBank object");
   bool equalResult3 = bank5.isEqual(bank2);
    if (equalResult3)
    {
        cout << "banks are equal" << endl;
    }
    else
    {
        cout <<"banks are not equal" << endl;
    }
    
    bool equalResult4 = bank1.isEqual(bank3);
    if (equalResult4)
    {
        cout << "banks are equal" << endl;
    }
    else
    {
        cout <<"banks are not equal" << endl;
    }
    
    cout << endl;
    
   
    printSectionTitle("Current values in the bank objects");
    bank1.print("bank 1 object");
    cout << endl;
    bank2.print("\nbank 2 object");
    cout << endl;
    bank3.print("\nbank 3 object");
    cout << endl;
    bank4.print("\nbank 4 object");
    cout << endl;
    bank5.print("\nbank 5 object");
    cout << endl;
    
    printSectionTitle("Using the isLessThan method with 4 arguments");
    PiggyBank compare3(12, 33, 42, 108);
    bool Lessthanresult1 = bank1.isLessThan(compare3);
    if (Lessthanresult1)
    {
        cout << "bank 1 is less than other bank." << endl;
    }
    else
    {
        cout <<"bank 1 is not less than ther bank." << endl;
    }
    
    PiggyBank compare4(3, 4, 70, 3);
    bool Lessthanresult2 = bank2.isLessThan(compare4);
    if (Lessthanresult2)
    {
        cout << "bank 2 is less than other bank" << endl;
    }
    else
    {
        cout << "bank 2 is not less than other bank" << endl;
    }
    cout << endl;
    
    printSectionTitle("Using the isLessthan method with PiggyBank objects");
    bool Lessthanresult3 = bank3.isLessThan(bank5);
    if (Lessthanresult3)
    {
        cout <<"bank3 is less than bank5" << endl;
    }
    else
    {
        cout <<"bank3 is not less than bank5" << endl;
    }
    bool Lessthanresult4 = bank4.isLessThan(bank2);
    if (Lessthanresult4)
    {
        cout <<"bank4 is less than bank2" << endl;
    }
    else
    {
        cout <<"bank4 is not less than bank2" << endl;
    }
    cout << endl;
    
    printSectionTitle("Using the getCoin method");
    cout <<"bank 1 contains " << bank1.getCoin(0) << " pennies" << endl; // using getcoin method to display specific coin values for each bank
    cout <<"bank 2 contains " << bank2.getCoin(1) << " nickels" << endl;
    cout <<"bank 3 contains " << bank3.getCoin(2) << " dimes" << endl;
    cout <<"bank 4 contains " << bank4.getCoin(3) << " quarters" << endl;
    cout << "getCoin returned " << bank5.getCoin(4) << " with invalid index" << endl;
    
    
    
    return 0;
}



//*************** Implement the class methods after this line ***************
//***************   DON'T FORGET TO ADD DOCUMENTATION BOXES   ***************


/***************************************************************
Default constructor: PiggyBank

Use:    Utilizes the emptyTheBank method,  which initlaizes all coin data members to 0.

Arguments: Nothing
***************************************************************/


PiggyBank::PiggyBank()
{
    emptyTheBank(); // calls method that already exists because this method and default constructor do the same thing.
}

/***************************************************************
Method: printBank

Use:     Prints the contents of the bank:  of Pennies, Nickels, Dimes, and Quarters each on one line.

Arguments: Nothing

Returns:   nothing
***************************************************************/
void PiggyBank:: printBank()

{
    cout <<"Pennies   " << numPennies << "  " <<"Nickels   " << numNickels << "  " <<"Dimes   " << numDimes << "  " <<"Quarters   " << numQuarters << " " << endl;
    
}

/***************************************************************
Method: printBankValue

Use:     Prints the monetary value  of Pennies, Nickels, Dimes, and Quarters each on one line with a leading dollar sign.

Arguments: Nothing

Returns:   nothing
***************************************************************/

void PiggyBank :: printBankValue()
{
   
    cout << fixed << setprecision (2) << "$" <<calcBankValue(); // used to accurate display monetary value in U.S. dollars (##.##)
    
    
}

/***************************************************************
Method: addCoins

Use:    calls methods for the other add coin methods, which adds value to the coin data member so long as the passed in value is not negative. If it is, then an error message is displayed.

Arguments: Nothing

Returns:   nothing
***************************************************************/


void PiggyBank::addCoins(int morePennies, int moreNickels, int moreDimes, int moreQuarters)
{
    //calling all the functions i made that add coins respectively based on a condition
    addPennies(morePennies);
    addNickels(moreNickels);
    addDimes(moreDimes);
    addQuarters(moreQuarters);
}


/***************************************************************
Method: calcBankValue

Use:     Calculates and returns the value (in dollars and cents) of a PiggyBank object.
Arguments: Nothing

Returns:   double - the total amount in dollars.
 *******************************************************************************************************************************************************************************************/



double PiggyBank :: calcBankValue()
{
    double value = (numPennies * .01) + (numNickels * .05) + (numDimes * .10)  + (numQuarters * .25); // each formula is different because the value for each type of coin is different
    
    return value;
}

/***************************************************************
Method(s) : addPennies, addDimes, addQuarters, addNickels

Use:     Adds value to the coin data member so long as the passed in value is not negative. If it is, then an error message is displayed.

Arguments: integer holding the number of pennies, quarters, nickels, or  dimes  to add to the PiggyBank object.

Returns:   nothing
 *******************************************************************************************************************************************************************************************/

void PiggyBank :: addPennies( int morePennies )
{
    
    if ( morePennies < 0 )
    {
        cout <<"Error: Cannot add a negative amount of pennies" << endl << endl; // you cant add negatives to a piggybank. I will add this to each method that adds a type of coin based on a passed in value
    }
    else
    {
       
        numPennies += morePennies;
       
    }
    
}

void PiggyBank :: addNickels( int moreNickels )
{
    
    if ( moreNickels < 0 )
    {
        cout <<"Error: Cannot add a negative amount of Nickels" << endl << endl;
    }
    else
    {
        
        numNickels += moreNickels;
    }
}

void PiggyBank :: addDimes( int moreDimes )
{
    if ( moreDimes < 0 )
    {
        cout <<"Error: Cannot add a negative amount of Dimes" << endl << endl;
    }
    else
    {
        
        numDimes += moreDimes;
    }
}

void PiggyBank :: addQuarters( int moreQuarters )
{
    if ( moreQuarters < 0 )
    {
        cout <<"Error: Cannot add a negative amount of Quarters" << endl << endl;
    }
    else
    {
        numQuarters += moreQuarters;
    }
}

/************************************************************************************************************************************************************************************************************/



/***************************************************************
Method: emptyTheBank

Use:     intializes all coin data members to 0, "emptying" a piggybank.

Arguments: none

Returns:   none
 *******************************************************************************************************************************************************************************************/


void PiggyBank :: emptyTheBank()
{
    numPennies  = numDimes = numNickels = numQuarters = 0; //now, the piggybank contents will show 0 for everything.
    
}
//*******************************************************************************************************


/***************************************************************
Alternate constructor: PiggyBank

Use:   creates an object with a specific number of coins and calls the emptythebank and addcoins method that have already been coded.

Arguments: an integer that holds the initial number of pennies, an integer that holds the initial number of nickels, an integer that holds the initial number of dimes, and an integer that holds the initial number of quarters.
***************************************************************/
 
PiggyBank ::PiggyBank(int pennies, int nickels, int dimes, int quarters)
{
    emptyTheBank();
    addCoins(pennies, nickels, dimes, quarters);
}


/***************************************************************
copy constructor: PiggyBank

Use:   a copy of the constructor for the PiggyBank class. Copies the data members from the passed in piggybank object into the data members of the object being created.

Arguments: a reference to a constant PiggyBank object that holds the values to copy into the object being created
***************************************************************/

PiggyBank::PiggyBank(const PiggyBank &otherBank) 
{
    numPennies = otherBank.numPennies;
    numNickels = otherBank.numNickels;
    numDimes = otherBank.numDimes;
    numQuarters = otherBank.numQuarters;
}


/***************************************************************
Method: print
 
Use:  Prints the contents and values of a piggybank object. also calls the printBank and printBankValue methods that were originally coded.

Arguments: a string that holds the title or label.
Returns: nothing
***************************************************************/
void PiggyBank :: print( string label  )
{
    cout << label << endl;
    printBank();
    printBankValue();
    
}

/***************************************************************
Method: addBanks
 
Use:    combines the contents of two piggybanks.
 
Arguments: an integer that holds the number of pennies in the piggybank to combine with the current instance, an integer that holds the number of nickels in the piggybank to combine with the current instance, an integer that holds the number of dimes in the piggybank to combine with the current instance, and an integer that holds the number of quarters in the piggybank to combine with the current instance.
 
Returns : a PiggyBank object :  an object that holds the combined contents of the two piggybanks.
***************************************************************/

PiggyBank PiggyBank ::  addBanks(int pennies, int nickels, int dimes, int quarters)
{
        PiggyBank combinedBank;
        combinedBank.addCoins(numPennies + pennies, numNickels + nickels, numDimes + dimes, numQuarters + quarters);
        return combinedBank;
    }

/***************************************************************
Method: addBanks
 
Use:   Same thing as other addBanks but the second piggy bank is passed in as a PiggyBank object rather than four separate integer values.
 
Arguments: an object of the PiggyBank class (otherBank).
 
returns:an object that holds the combined contents of the two piggybanks
***************************************************************/

PiggyBank PiggyBank::addBanks(PiggyBank otherBank)
{
    return addBanks(otherBank.numPennies, otherBank.numNickels, otherBank.numDimes, otherBank.numQuarters);
}




/***************************************************************
Methods (2) : isEqual
 
Use(1):  compares the contents of two piggybanks to determine if they are equal.
Arguments(1)   an integer that holds the number of pennies in the piggybank to compare with the current instance, an integer that holds the number of nickels in the piggybank to compare with the current instance, an integer that holds the number of dimes in the piggybank to compare with the current instance, and an integer that holds the number of quarters in the piggybank to compare with the current instance.
 Returns (1) a bool:   true if the current instance piggybank is less than the piggybank represented by the passed in arguments, false if the current instance piggybank is not less than the piggybank represented by the passed in arguments.
 

 
 
 
 Use(2): Same thing as other isEqual but this time the second piggybank is passed in as a piggybank object  rather than 4 integer values;
 Arguments(2): object of the PiggyBank class(otherBank)
  Returns (2) a bool:   true if the current instance piggybank is less than the piggybank represented by the passed in arguments, false if the current instance piggybank is not less than the piggybank represented by the passed in arguments.
 


***************************************************************/

bool PiggyBank::isEqual(int pennies, int nickels, int dimes, int quarters)
    {
        // Calculate the monetary value of the current piggybank
        double thisValue = calcBankValue();

        // Calculate the monetary value of the piggybank specified by the arguments
        double otherValue = (pennies * 0.01) + (nickels * 0.05) + (dimes * 0.1) + (quarters * 0.25);

        // Compare the values and return true if they are equal, otherwise false
        if  (thisValue == otherValue)
        {
            return thisValue == otherValue;
            return true;
        }
    
    else
        return false;
    }

    



bool PiggyBank::isEqual(PiggyBank otherBank)
{
    return calcBankValue() == otherBank.calcBankValue();
}


/***************************************************************
Methods(2): isLessThan
 
Use(1): compares the contents of two piggybanks to determine if one is less than the other.
Arguments(1): an integer that holds the number of pennies in the piggybank to compare with the current instance, an integer that holds the number of nickels in the piggybank to compare with the current instance, an integer that holds the number of dimes in the piggybank to compare with the current instance, and an integer that holds the number of quarters in the piggybank to compare with the current instance.
 Returns(2) a bool: true if the current instance piggybank is less than the piggybank represented by the passed in arguments, false if the current instance piggybank is not less than the piggybank represented by the passed in arguments.
 
 
 
Use(1):  Same thing as other isLessThan. The difference is that the second piggy bank is passed in as a PiggyBank object rather than four separate integer values.
 Arguments(2): object of the PiggyBank class(otherBank)
 Returns(2):  a bool: true if the current instance piggybank is less than the piggybank represented by the passed in arguments, false if the current instance piggybank is not less than the piggybank represented by the passed in arguments.

 
***************************************************************/
bool PiggyBank:: isLessThan(int pennies, int nickels, int dimes, int quarters)
{
    double thisValue = calcBankValue();
    double otherValue = ( pennies * 0.01) + (nickels * 0.05) + (dimes * 0.1) + (quarters * 0.25);
    if (thisValue < otherValue)
    {
        return thisValue < otherValue;
        return true;
    }
    else
        return false;
}

bool PiggyBank :: isLessThan(PiggyBank otherBank)
{
    
    return calcBankValue() < otherBank.calcBankValue();
    
    
}



/***************************************************************
Accessor Method: getCoin
 
Use:    returns the value of a single data member in a PiggyBank object.

Arguments: an integer that represents the data member thats value should be returned
Returns:an integer: the value of the data member specified by the passed in index or -1 if the passed in value is invalid.
***************************************************************/

int PiggyBank :: getCoin(int coinIndex)
{
       switch (coinIndex) {
           case 0: return numPennies;
           case 1: return numNickels;
           case 2: return numDimes;
           case 3: return numQuarters;
           default: return -1;
       }
   }


/***************************************************************
Function: printSectionTitle
 
Use: displays a title: used to help separate the output of the program.

Arguments:  a string that holds the title that should be displayed.
Returns : nothing
***************************************************************/

void printSectionTitle(string title) {
    cout << "---------------------------------------------------------------" << endl;
    cout << title << endl;
    cout << endl;
}






















     
     
     
     
 
    
    
    
    
    
    
    
    
    
    
    

