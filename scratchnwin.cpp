#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <random>

int main () {

    struct Outcome {
        double prob;
        int payout;
        std::string symbol;
        double lowR;
        double highR;
    } outcome;

    std::vector<Outcome> outcomes = {
        {0.695, 0, "💣", 0, 0.695},

        {0.170, 1, "🍋", 0.695, 0.865},

        {0.070, 2, "🍒", 0.865, 0.935},

        {0.040, 5, "🍇", 0.935, 0.975},

        {0.015, 10, "🔔", 0.975, 0.990},

        {0.010, 25, "⭐", 0.990, 1.000}
    };

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    double roll = dist(rng);

    std::cout << roll <<"\n";
    
    for (Outcome &res : outcomes) {
        std::cout << res.prob <<"\n";
    }
    
    
    std::string ticket = {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    };
    return 0;

}