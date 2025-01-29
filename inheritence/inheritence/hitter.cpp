#include <iostream>
#include "hitter.h"
#include <iomanip>

hitter::hitter()
{
    hits = 0;
    at_bats = 0;
}

hitter::hitter(const string& Name, int Number, int Hits, int atBats): player(Name, Number), hits(Hits),at_bats(atBats){}


void hitter::print() const
{
    player::print();
    double bat_avg = average();
    cout << setw(7) << right << hits
    << setw(7) << right << at_bats
    << setw(9) << right << fixed << setprecision(3) << bat_avg << endl;
}

double hitter::average() const
{
    if (at_bats == 0)
        return 0.0;
    double bat_avg = static_cast<double> (hits) / at_bats;
    return bat_avg;
}

