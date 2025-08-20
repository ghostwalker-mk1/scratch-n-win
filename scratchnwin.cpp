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
        {0.599, 0, "💣", 0, 0.599},

        {0.270, 1, "🍋", 0.599, 0.869},

        {0.070, 2, "🍒", 0.869, 0.939},

        {0.040, 5, "🍇", 0.939, 0.979},

        {0.015, 10, "🔔", 0.979, 0.994},

        {0.010, 25, "💲", 0.994, 1.000}
    };

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    double roll = dist(rng);

    std::cout << roll <<"\n";
    
    Outcome deal;

    for (Outcome &res : outcomes) {
        if (roll >= res.lowR && roll < res.highR) {
            deal = res;
        }
    }

    std::vector<std::string> ticket = {
    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + deal.symbol + "|   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + deal.symbol + "| " + deal.symbol + "|   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + deal.symbol + "| " + deal.symbol + "| " + deal.symbol + "|   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    }
    };
    
    std::string input = "";
    int count = 0;

    do {
        if (count >= ticket.size()) {
            break;
        }

        std::getline(std::cin, input);

        if (input == "") {
        std::cout << ticket[count];
        count++;
        }

        std::cout << count <<"\n";

    } while (1);

    if (deal.payout == 0) {
        std::cout << "D'oh! Nothing...\n";
    } else if (deal.payout == 1 || deal.payout == 2) {
        std::cout << "You won $" + std::to_string(deal.payout) + ".\n";
    } else {
        std::cout << "Woo-hoo! You won $" + std::to_string(deal.payout) + "!\n";
    }

    return 0;

}