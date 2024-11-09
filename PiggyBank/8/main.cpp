/***************************************************************
CSCI 240         Program 8     Spring 2024

Name:   Hamzah Subhani
Z-ID: 2010017
Section: 2
TA: Sai Padmasree
Due Date: 4/19/2024

Purpose: This program will be used to represent a collection of coins.  Functionality will be added to the class so that coins can be added to the bank and output operations can be performed.
***************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;


//*************** Place the class description after this line ***************


//****************************************************************************
class PiggyBank // this is what will be called before every method

{
    
private:
    int numPennies;
    int numNickels;
    int numDimes;
    int numQuarters;
    
public:
    PiggyBank();
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

};


int main()
{
//Test 1 -- default constructor and printPiggyBank
cout << "***** Test 1: Default Constructor and printPiggyBank *****" << endl << endl;
cout << fixed << setprecision(2);

//create two objects using the default constructor
PiggyBank bank1;
PiggyBank bank2 = PiggyBank();

//display the two objects
cout << "bank1:" << endl;

bank1.printBank();

cout << endl << endl << "bank2:" << endl;

bank2.printBank();


//Test 2 -- printBankValue
cout << endl << endl << endl << "***** Test 2: printBankValue *****" << endl << endl
     << "bank1:" << endl;

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//Test 3 -- adding coins
cout << endl << endl << endl << "***** Test 3: addCoins Method *****" << endl << endl
     << "3a: Adding 2 pennies, 47 nickels, 20 dimes, and 5 quarters to bank1 produces:"
     << endl << endl;

//update bank 1: 2 pennies, 47 nickels, 20 dimes, and 5 quarters   and display
bank1.addCoins( 2, 47, 20, 5 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//update bank 2: 143 pennies, 9 nickels, 0 dimes, and 44 quarters   and display
bank2.addCoins( 143, 9, 0, 44 );

cout << endl << endl << "3b: Adding 143 pennies, 9 nickels, 0 dimes, and 44 quarters to bank2 produces:"
     << endl << endl;

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();


//Test 4 -- adding pennies
cout << endl << endl << endl << "***** Test 4: addPennies Method *****" << endl << endl
     << "4a: Adding 95 pennies to bank1:" << endl << endl;

//update bank 1: 95 pennies   and display
bank1.addPennies( 95 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


cout << endl << endl << "4b: Adding -54 pennies to bank1:" << endl << endl;

//(try to) update bank 1: -54 pennies   and display
bank1.addPennies( -54 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//Test 5 -- adding nickels
cout << endl << endl << endl << "***** Test 5: addNickels Method *****" << endl << endl
     << "5a: Adding -12 nickels to bank2:" << endl << endl;

//(try to) update bank 2: -12 nickels   and display
bank2.addNickels( -12 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();


cout << endl << endl << "5b: Adding 17 nickels to bank2:" << endl << endl;

//update bank 2: 17 nickels   and display
bank2.addNickels(17);

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



//Test 6 -- adding dimes
cout << endl << endl << endl << "***** Test 6: addDimes Method *****" << endl << endl
     << "6a: Adding 157 dimes to bank2:" << endl << endl;

//update bank 2: 157 dimes   and display
bank2.addDimes( 157 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();

cout << endl << endl << "6b: Adding -37 dimes to bank2:" << endl << endl;

//(try to) update bank 2: -37 dimes   and display
bank2.addDimes( -37 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



//Test 7 -- adding quarters
cout << endl << endl << endl << "***** Test 7: addQuarters Method *****" << endl << endl
     << "7a: Adding 14 quarters to bank1: " << endl << endl;

//update bank 1: 14 quarters   and display
bank1.addQuarters( 14 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


cout << endl << endl << "7b: Adding -45 quarters to bank1:" << endl << endl;

//(try to) update bank 1: -45 quarters   and display
bank1.addQuarters( -45 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();



//Test 8 -- bank value
cout << endl << endl << endl << "***** Test 8: Calculating the Bank Values *****" << endl << endl;

//Get the current value of both banks and calculate the total amount of money
double bank1value = bank1.calcBankValue(),
       bank2value = bank2.calcBankValue();

double total = bank1value + bank2value;

//display the calculated total
cout << "$" << bank1value << " + $" << bank2value << " = $" << total << endl << endl;


//Test 9 -- empty the bank
cout << endl << endl << endl << "***** Test 9: Emptying the PiggyBanks *****" << endl << endl
     << "It\'s time to empty the banks!" << endl << endl;

cout << endl << "9a: bank1 initially contains: " << endl << endl;

//display the current value of bank1 and the updated value after it has been emptied
bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();

bank1.emptyTheBank();

cout << endl << endl << "bank1 now contains: " << endl << endl;

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();



cout << endl << endl << endl << "9b: bank2 initially contains: " << endl << endl;

//display the current value of bank2 and the updated value after it has been emptied
bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();

bank2.emptyTheBank();

cout << endl << endl << "bank2 now contains: " << endl << endl;

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



cout << endl << endl;

return 0;
}//end of int main()


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
    


















     
     
     
     
 
    
    
    
    
    
    
    
    
    
    
    

