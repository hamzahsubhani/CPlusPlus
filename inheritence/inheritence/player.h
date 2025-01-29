#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
class player
{
private:
    string name;
    int number;
public:
    player();
    player(const string&, int);
    virtual ~player();
    int get_number() const;
    virtual void print() const;
    virtual double average() const = 0;
};

#endif
