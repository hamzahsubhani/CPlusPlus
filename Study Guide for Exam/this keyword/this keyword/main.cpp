#include<iostream>
using namespace std;
/*
 local variable is same as a member's name
class Test
{
private:
   int x;
public:
   void setX (int x)
   {
       // The 'this' pointer is used to retrieve the object's x
       // hidden by the local variable 'x'
       this->x = x;
   }
   void print() { cout << "x = " << x << endl; }
};

int main()
{
   Test obj;
   int x = 20;
   obj.setX(x);
   obj.print();
   return 0;
}



class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0)
    {
      this->x = x; this->y = y;
    }
  Test &setX(int a)
    {
      x = a;
      return *this;
    }
  Test &setY(int b)
    {
      y = b;
      return *this;
    }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int main()
{
  Test obj1(5, 5);

  // Chained function calls.  All calls modify the same object
  // as the same object is returned by reference
  obj1.setX(10).setY(20);

  obj1.print();
  return 0;
}




class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
    void change(Test *t) { x = t -> x; }
  void print() { cout << "x = " << x << endl; }
};

int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}
*/


