#include "player.h"
#include <iomanip>
using namespace std;
player::player()
{
    name = "";
    number = 0;
}

player::player(const string& player_name, int player_number)
{
    this -> name = player_name;
    this -> number = player_number;
}

player:: ~player() {}

int player::get_number() const
{
    return number;
}

void player:: print() const

{
    if (number < 10)
    {
        // If the player number is a single digit, add an extra space
        cout << left << ' ' << setw(5) << number << setw(20) << left << name;
    }
    else
    {
        cout << setw(6)  << left << number << setw(20) << left << name;
    }
    
    
}
