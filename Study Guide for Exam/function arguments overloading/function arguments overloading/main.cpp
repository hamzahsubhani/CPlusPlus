
#include <iostream>
using namespace std;

    float add (float , float);
    int add (int, int);
    double add (double, double);
    int add (int);

int main()
{
    float number1 = 0;
    float number2 = 2;
    
    cout << add(number1, number2) << endl; // the float function takes priority
    
    int add1 = 2;
    int add2 = 3;
    cout << add(add1, add2) << endl; // calls function with 2 params
    cout << add(add1); // calls function with one param
    
}
 
float add (float float1 , float float2)
{
    return float1 + float2;
}
int add (int int1, int int2)
{
    return int1 + int2;
}
double add (double d1, double d2)
{
    return d1 + d2;
}
int add (int d1)
{
    return d1;
}
