#include <iostream>

using namespace std;

template <class T>
class calculator {
public:
    T add(T , T );
};

template <class T>
T calculator<T>::add(T x, T y) {
    return x + y;
}

int main() {
    calculator<int> intCalculator;
    calculator<double> doubleCalculator;
    calculator<string> stringCalculator;

    cout << intCalculator.add(3, 4) << endl; // Output: 7
    cout << stringCalculator.add("peee", " peee") << endl; // Output: peee peee
    cout << doubleCalculator.add(1.2323, 323.22) << endl; // Output: 324.4523

    return 0;
}
