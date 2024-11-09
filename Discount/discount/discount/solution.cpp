#include <iostream>
#include <iomanip>

using namespace std;
/*
double discount(double amount);

int main()
{
    cout << fixed << setprecision(2);
    
    double amount = 27.99;
    
    cout << "Purchase amount: " << amount << ", discounted amount: "
         << discount(amount) << endl;

    amount = 50.00;
    
    cout << "Purchase amount: " << amount << ", discounted amount: "
         << discount(amount) << endl;

    amount = 67.99;
    
    cout << "Purchase amount: " << amount << ", discounted amount: "
         << discount(amount) << endl;

    amount = 100.00;
    
    cout << "Purchase amount: " << amount << ", discounted amount: "
         << discount(amount) << endl;

    amount = 184.27;
    
    cout << "Purchase amount: " << amount << ", discounted amount: "
         << discount(amount) << endl;

    return 0;
}*/

double discount (double amount)
{
    double newprice = 0.00;
    if (amount < 50.00)
    {
        newprice = (amount - .05 * amount);
    }
    else if (amount >= 50.00 && amount<100.00)
    {
        newprice = (amount - .10 * amount);
    }
    else if (amount >= 100.00)
    {
        newprice = (amount -.15 * amount);
    }
    
    return newprice;
}
