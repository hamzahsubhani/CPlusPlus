#ifndef PITCHER_H
#define PITCHER_H
#include "player.h"

class pitcher:public player
{
private:
    int earned_runs;
    int innings_pitched;
public:
    pitcher();
    pitcher(const string&, int , int , int);
    void print() const override;
    double average() const override;
};











#endif
