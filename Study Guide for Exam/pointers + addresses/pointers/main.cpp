
#include <iostream>
using namespace std;


int main()
{
    
    
    // pointers = variable that stores a memory address of another variable
    //                    sometimes it's easier to work with an address

    // & address-of operator
    // * dereference operator
/*
    std::string name = "Bro";
    int age = 21;
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    
    std::string *pName = &name; // Bro
    int *pAge = &age;
    std::string *pFreePizzas = freePizzas;

    std::cout << *pName << '\n';
    std::cout << *pAge << '\n';
    std::cout << *pFreePizzas << '\n';

    
    string name = "Hamzah";
    string *pName = &name;
    cout << "Variable: " <<  name << endl;
    cout << "pointer address: " << pName << endl;
    cout << "Variable: " << *pName  << endl;
    cout << "Variable Address: " << &name << endl;
    */
    
    
    
    /*                      Types of pointers                          */
    
    
    
    //Pointer
    int x = 10;
    int* p = &x;  // Pointer to an integer
    *p = 20;      // Modify the value of x through the pointer

    
    //Pointer to constant data
    const int y = 30;
    const int* q = &y;  // Pointer to a constant integer
    // *q = 40;          // Error: cannot modify the value pointed to by a const pointer
    
    
    //Constant pointer
    int z = 50;
    int* const r = &z;  // Constant pointer to an integer
    *r = 60;// Modify the value of z through the constant pointer
    // r = &x;          // Error: cannot change the address of a constant pointer

    //Constant pointer to constant data
    const int a = 70;
    const int* const s = &a;  // Constant pointer to a constant integer
    // *s = 80;                // Error: cannot modify the value pointed to by a const pointer
    // s = &y;                 // Error: cannot change the address of a constant pointer

  
    
    double piValue = 3.14159;
    double* piPtr = &piValue;
    cout << *piPtr << endl;
    cout <<piPtr << endl;
    return 0;
}
