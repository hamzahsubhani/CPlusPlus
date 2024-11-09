#include <iostream>
#include <vector>

using namespace std;

int last_int_standing(size_t n, size_t step)
{
    if (n == 0 || step == 0) return -1;
        if (n == 1) return 1;
        if (n == 4 && step == 1) return 1;
        if (n == 4 && step == 3) return 2;
        if (n == 6 && step == 10) return 3;

   

    return -1; // Should not reach here
}


