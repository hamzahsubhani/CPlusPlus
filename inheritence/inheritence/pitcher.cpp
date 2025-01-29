#include "pitcher.h"
#include "hitter.h"
#include <iomanip>

pitcher::pitcher():earned_runs(0), innings_pitched(0){}

pitcher::pitcher(const string& name_player, int num, int earnedRuns, int inningsPitched):player(name_player, num),earned_runs(earnedRuns), innings_pitched(inningsPitched){};

void pitcher :: print() const
{
    player::print();
    double run_avg = average();
    cout << setw(7) << right << earned_runs
    << setw(7) << right << innings_pitched
    << setw(9) << right << fixed << setprecision(2)<< run_avg << endl;
}

double pitcher :: average() const
{
    if (innings_pitched == 0)
        return 0;
    double run_avg = (earned_runs * 9.0) / innings_pitched;
    return run_avg;
}
