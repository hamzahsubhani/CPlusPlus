#include <iostream>

using namespace std;

class MyClass {
private:
    int num1 = 4, num2 = 3;
public:
    MyClass() {
        std::cout << "Default constructor called!" << std::endl;
    }
    friend int add(const MyClass& obj);
};

int add(const MyClass& obj)
{
    return obj.num1+ obj.num2;
}
int main()
{
    MyClass obj;
    cout << add(obj) << endl;
    // dynamically allocate an integer variable
    // n was statically allocated - at compile time
    // unnamed variable -- dynamically allocated at run time
    int* n = new int; // creates TWO variables
    
    *n = 8;
    
    int* o;
    
    o = new int;
    
    *o = 2;
    
    int sum = *n + *o;
    
    cout <<"The sum of " << *n << " and " << *o << " is " << sum << endl;
    
    delete n;
    delete o;
    
    int size; // statically allocated
    int* aptr; // statically allocated
    cout << "Enter the size of the array: ";
    cin >> size; // will determine how many elements are in each array
    
    //create a dynamically allocated array
    aptr = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number for element " << i << ": ";
        cin >> aptr[i];
    }
    
    int i = 0;
    while (i < size)
    {
        cout << aptr[i] << " ";
        i++;
    }
    cout << endl;
    
    delete[] aptr;
    
    
    MyClass* array = new MyClass[3]; // default constructor will be called three times

      // Free the array
      delete[] array;

      return 0;
}
