#include<iostream>
#include <iomanip>

using namespace std;
int ptX;
int ptY;
int main() {
    if (ptX < left || ptX > right || ptY > top || ptY < bottom) {
      cout << "The point is outside the rectangle." << endl;
    } else {
      cout << "The point is inside or on the rectangle." << endl;
    }

    
}






