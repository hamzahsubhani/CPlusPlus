#include <iostream>
#include <iomanip>
#include <cstring> // need for strcat, strcpy, etc
#include <cctype> // needed for this program because of isalpha and isdigit
#define LEFT_COLUMN_WIDTH 30 // symbolic constants for how the info will be arranged
#define RIGHT_COLUMN_WIDTH 10

using namespace std;

class employee 
{
private:
    // these attributes are in the private partition because they will need accessor set and get methods
    char name[30];
    char id[8];
    double salary;

public:
    employee(); // default constructor
    employee (const char em[], const char id[], double sal); // alternate constructor
    
    
    // these methods and their usses will all be listed in the documentation boxes
    void display();
    void setIDnum( const char updated_id[] );
    void increaseSalary(double raise);
    void setSalary( double updated_salary );
    const char * getName();
    const char * getIDnum();
    double getSalary();

};





int main() 
{
   // from here, i will create employee objects from 2 constructors. One takes 4 arguments. One takes none
    employee first ("Hamzah", "NIU0017" , 53948.61);
    cout <<"The first employee object:" << endl;
    first.display(); // calling display method
    first.increaseSalary(125.15); // calling increase salary method
    first.display();
    
    employee second;
    cout <<"The second employee object:" << endl;
    second.display();
    second.increaseSalary(-2200.00);
    second.display();
    
    employee third("Blanche Devereaux" , "TGG1985" , 820.12);
    cout <<"The third employee object:" << endl;
    third.display();
    third.setSalary(82.88); // calling set salary method
    third.setIDnum("TGP1992");
    third.display(); // calling set id method
    
    employee fourth("Grace Hopper", "UNI1950", 2468.00);
    cout <<"The fourth employee object:" << endl;
    fourth.display();
    fourth.setIDnum("COBOL1959");
    fourth.increaseSalary(9517.53);
    cout << setw(LEFT_COLUMN_WIDTH) << left << "Grace Hopper has a salary of" << fourth.getSalary() << endl << endl;
    fourth.display(); //  calling method that will only retrieve one element. in this case it is the salary
    
    
    employee fifth ("Charlie Hudson" , "REX2332" , 71940.76);
    cout <<"The fifth employee object:" << endl;
    fifth.display();
    fifth.setSalary(-10000.01);
    cout <<"Employee 5 has an indentification number of " << fifth.getIDnum() << endl << endl; // like the salary with grace, but now it is the id number
    fifth.display();
    
   
    
    
    
    
    
    
    
    

    
    return 0;
}



/***************************************************************
Default constructor: employee

Use:  initializes the data members so that employee name is "None," the identification number is "ACB1234", and the salary is 0.00.

Arguments:  nothing
***************************************************************/

employee::employee()
{
    
        strcpy(name, "None");
        strcpy(id, "ABC1234");
        salary = 0.0;
}

/***************************************************************
Alternate constructor: employee

Use:   initializes the data members using values that are passed to the constructor.

Arguments:  an array of constant charactera with an employee name, an array of constant characters with the employee identification number, and a double that holds the employee salary.
***************************************************************/

employee:: employee(const char employ[], const char id[], double sal)
{
    setIDnum(id);
    setSalary(sal);
    strcpy(name, employ);

}

/***************************************************************
Method: display

Use:  displays the employee information.

Arguments: none
Returns : nothing
***************************************************************/

void employee :: display()
{
    cout << setw(LEFT_COLUMN_WIDTH) << left << name << right << setw(RIGHT_COLUMN_WIDTH) << id << endl;
    cout << fixed << setprecision(2) << "$" << salary << endl;
    cout << endl;
}

/***************************************************************
Method: increaseSalary

Use:  increases an employees salary based on a non negative number condition.

Arguments:  a double that represents the amount to increase the employee's salary.
Returns : nothing
***************************************************************/

 void employee :: increaseSalary (double raise)
{
     if (raise <= 0)
     {
         cout <<"Error: salary increase is invalid - negative or 0.00. Salary was not changed." << endl;
         cout << endl;
     }
     else
     {
         salary += raise;
     }
 }

/***************************************************************
Method: setIDnum

Use:  changes an employees indentification number based on certain conditions.

Arguments:  an array of constant characters that holds the new employee identification number.
Returns : nothing
***************************************************************/

void employee::setIDnum(const char updated_id[]) 
{
    bool isValid = true;
        
        if (strlen(updated_id) != 7)
        {
            cout << "Error: new ID is invalid - not 7 characters. ID was not changed." << endl << endl;
            isValid = false;
        }
        else
        {
          
            for (int i = 0; i < 3; i++)
            {
                if (!isalpha(updated_id[i]))
                {
                    cout << "First three characters of the ID must be letters." << endl << endl;
                    isValid = false;
                    break;
                }
            }

            for (int i = 3; i < strlen(updated_id); i++)
            {
                if (!isdigit(updated_id[i]))
                {
                    cout << "Last 4 elements of ID do not all contain digits." << endl << endl;
                    isValid = false;
                    break;
                }
            }
        }
        
        if (isValid)
        {
            strcpy(id, updated_id);
        }
    }


/***************************************************************
Method: setSalary

Use: changes an employees salary based on a non negative number condition.

Arguments:  a double that represents the new employee salary.
Returns : nothing
***************************************************************/
void employee :: setSalary(double updated_salary)
{
    if (updated_salary <=0 )
    {
        cout <<"Error: new salary is invalid - negative or 0.00. Salary was not changed."<< endl << endl;
    }
    
    else
    {
        salary = updated_salary;
    }
}
/***************************************************************
Method: getName

Use: returns an employees name.

Arguments:  none
Returns : name data member
***************************************************************/

const char * employee :: getName()

{
    return name;
}
/***************************************************************
Method: getIDnum

Use:  returns an employees identification number

Arguments:  none
Returns : ID data member
***************************************************************/
const char * employee :: getIDnum()
{
    return id;
}
/***************************************************************
Method: getSalary

Use: returns an employees salary

Arguments:
Returns : salary data member
***************************************************************/

double employee :: getSalary()
{
    return salary;
}









