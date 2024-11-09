#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class myClass {
private:
    int data;

public:
    // Default Constructor
    myClass()
    {
        data = 0;
        cout << "Default Constructor: data initialized to " << data << endl;
    }

    // Parameterized Constructor
    myClass(int value)
    {
        this -> data = value;
        cout << "Parameterized Constructor: data initialized to " << data << endl;
    }

    // Copy Constructor
    myClass(const myClass& other)
    {
        this -> data = other.data;
        cout << "Copy Constructor: data copied, value is " << data << endl;
    }

    // Copy Assignment Operator
    myClass& operator=(const myClass& other)
    {
        if (this == &other)  // Check for self-assignment
            return *this;

        data = other.data;
        cout << "Copy Assignment Operator: data assigned, value is " << data << endl;
        return *this;
    }

    // Destructor
    ~myClass() {
        cout << "Destructor: data with value " << data << " is being destroyed" << endl;
    }

    // Getter to display data
    int getData() const
    {
        return data;
    }
};

int main() {
    myClass obj1;           // Default constructor
    myClass obj2(42);       // Parameterized constructor
    myClass obj3 = obj2;    // Copy constructor
    obj1 = obj2;            // Copy assignment operator
    return 0;               // Destructor called for obj1, obj2, and obj3
}
