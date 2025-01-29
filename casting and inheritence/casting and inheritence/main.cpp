#include <iostream>
using namespace std;
class Base {
public:
    virtual void display() {
        std::cout << "Base class display method" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display method" << std::endl;

        // Call the base class version of display within derived class
      //  Base::display();
    }
};

int main() {

    // upcasting
    Derived derivedObj;
       Base* basePtr = &derivedObj; // Upcasting: Derived object to Base pointer
       basePtr->display(); // Calls the derived class's display method due to polymorphism
    
    //downcasting
    Base* basePtr2 = new Derived(); // Upcasting to base
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr2); // Safe Downcasting
    if (basePtr2!= NULL)
    derivedPtr->display();
    return 0;
    
    
}
