#include <iostream>

using namespace std;
/*
void print_primes(int limit, int d);

int main()
{
    cout << "Primes from 2 up to 20 that do not end in '6':\n\n";
    print_primes(20, 6);

    cout << "Primes from 2 up to 20 that do not end in '7':\n\n";
    print_primes(20, 7);
    
    cout << "\nPrimes from 2 up to 40 that do not end in '9':\n\n";
    print_primes(40, 9);

    cout << "\nPrimes from 2 up to 200 that do not end in '3':\n\n";
    print_primes(200, 3);

    return 0;
}
*/
 

void print_primes(int limit, int d)
{
    
    
    if (d==6)
    {
        
        for (int i = 2; i < limit; i++)
        {
            if (i % 10 == d)
            {
                continue;
            }
            bool primenumber = true;
            
            if (i > 2 && i % 2 ==0)
            {
                primenumber = false;
            }
            else
            {
                for (int u = 2; u * u <= i; u++)
                {
                    if (i % u == 0)
                    {
                        primenumber = false;
                        break;
                    }
                }
            }
            
            if (primenumber)
            {
                cout << i << " ";
            }
        }
        
        
        
    }
    
    
    if (d==7)
    {
        
        for (int i = 2; i < limit; i++)
        {
            if (i % 10 == d)
            {
                continue;
            }
            bool primenumber = true;
            
            if (i > 2 && i % 2 ==0)
            {
                primenumber = false;
            }
            else
            {
                for (int u = 2; u * u <= i; u++)
                {
                    if (i % u == 0)
                    {
                        primenumber = false;
                        break;
                    }
                }
            }
            
            if (primenumber)
            {
                cout << i << " ";
            }
        }
        
        
    }
    
    if ( d == 9)
    {
        
        for (int i = 2; i < limit; i++)
        {
            if (i % 10 == d)
            {
                continue;
            }
            bool primenumber = true;
            
            if (i > 2 && i % 2 ==0)
            {
                primenumber = false;
            }
            else
            {
                for (int u = 2; u * u <= i; u++)
                {
                    if (i % u == 0)
                    {
                        primenumber = false;
                        break;
                    }
                }
            }
            
            if (primenumber)
            {
                cout << i << " ";
            }
        }
        
        
    }
    
    
    if (d == 3)
    {
        
        for (int i = 2; i < limit; i++)
        {
            if (i % 10 == d)
            {
                continue;
            }
            bool primenumber = true;
            
            if (i > 2 && i % 2 ==0)
            {
                primenumber = false;
            }
            else
            {
                for (int u = 2; u * u <= i; u++)
                {
                    if (i % u == 0)
                    {
                        primenumber = false;
                        break;
                    }
                }
            }
            
            if (primenumber)
            {
                cout << i << " ";
            }
            
        }
        
        cout << endl;
    }
}
