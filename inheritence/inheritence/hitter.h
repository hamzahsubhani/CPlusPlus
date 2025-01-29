#ifndef HITTER_H
#define HITTER_H
#include "player.h"

using namespace std;

class hitter: public player
{
private:
    int hits;
    int at_bats;
public:
    hitter();
    hitter(const string&, int, int, int);
    virtual void print() const override;
    virtual double average() const override;
};

#endif
