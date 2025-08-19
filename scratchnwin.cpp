#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <array>
#include <map>

using namespace std;

int main () {

    struct Outcome {
        double prob;
        int payout;
        string symbol;
        double lowR;
        double highR;
    } outcomes;

    Outcome outcomes[6] = {
        {0.695, 0, "💣", 0, 0.695},

        {0.170, 1, "🍋", 0.695, 0.865},

        {0.070, 2, "🍒", 0.865, 0.935},

        {0.040, 5, "🍇", 0.935, 0.975},

        {0.015, 10, "🔔", 0.975, 0.990},

        {0.010, 25, "⭐", 0.990, 1.000}
    };

    srand(time(NULL));

    double roll = ((double) rand() / RAND_MAX);
    cout << roll <<"\n";
    
    
    array<string, 4> banners = {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",
    };

    return 0;

}