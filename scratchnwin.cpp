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

    // std::cout << roll <<"\n";
    
    Outcome deal;

    for (Outcome &res : outcomes) {
        if (roll >= res.lowR && roll < res.highR) {
            deal = res;
        };
    };

    std::string symbol1;
    std::string symbol2;
    std::string symbol3;

    std::vector<std::string> symbols = {
        symbol1, symbol2, symbol3
    };

    if (deal.payout == 0) {
    } else {
        for (int i = 0; i < symbols.size(); i++) {
            symbols[i] = deal.symbol;
        };
    };

    std::vector<std::string> ticket = {
    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___  $1|\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___  $1|\n"
    "|   | " + symbols[0] + "|   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___  $1|\n"
    "|   | " + symbols[0] + "| " + symbols[1] + "|   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n"
    },

    {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___  $1|\n"
    "|   | " + symbols[0] + "| " + symbols[1] + "| " + symbols[2] + "|   |\n"
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
    } else {
        std::cout << "Woo-hoo! You won $" + std::to_string(deal.payout) + "!\n";
    };

    return 0;

}