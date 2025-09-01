#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

// Struct for possible outcomes
struct Outcome {
    double prob;
    int payout;
    std::string symbol;
    double lowR;
    double highR;
};

// Struct for loss outcome types
struct LossOutcome {
    std::string symbol;
    double prob;
    double lowR;
    double highR;
};

int main () {

    // Possible outcomes
    std::vector<Outcome> outcomes = {
        {0.599, 0, "💣", 0, 0.599},

        {0.270, 1, "🍋", 0.599, 0.869},

        {0.070, 2, "🍒", 0.869, 0.939},

        {0.040, 5, "🍇", 0.939, 0.979},

        {0.015, 10, "🔔", 0.979, 0.994},

        {0.010, 25, "💲", 0.994, 1.000}
    };

    // Loss outcomes
    std::vector<LossOutcome> lossOutcomes = {
        {"alldiff", 0.60, 0, 0.60},
        {"2ofkind", 0.30, 0.60, 0.90},
        {"3ofkind", 0.10, 0.90, 1.0}
    };

    // Generate "randomness"
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Main roll
    double roll = dist(rng);
    
    Outcome deal;

    for (Outcome &res : outcomes) {
        if (roll >= res.lowR && roll < res.highR) {
            deal = res;
        };
    };

    // Loss roll
    double lossRoll = dist(rng);

    LossOutcome lossDeal;

    for (LossOutcome &res : lossOutcomes) {
        if (lossRoll >= res.lowR && lossRoll < res.highR) {
            lossDeal = res;
        };
    };

    // 2 OF A KIND

    // Dupe roll
    double dupeRoll = dist(rng);
    
    Outcome dupeDeal;

    for (Outcome &res : outcomes) {
        if (dupeRoll >= res.lowR && dupeRoll < res.highR) {
            dupeDeal = res;
        };
    };

    // Odd roll
    double oddRoll = dist(rng);
    
    Outcome oddDeal;

    for (Outcome &res : outcomes) {
        if (oddRoll >= res.lowR && oddRoll < res.highR && res.symbol != dupeDeal.symbol) {
            oddDeal = res;
        };
    };

    // 3 OF A KIND

    // 1
    double roll1 = dist(rng);
    
    Outcome deal1;

    for (Outcome &res : outcomes) {
        if (roll1 >= res.lowR && roll1 < res.highR) {
            deal1 = res;
        };
    };

    // 2
    double roll2 = dist(rng);
    
    Outcome deal2;

    for (Outcome &res : outcomes) {
        if (roll2 >= res.lowR && roll2 < res.highR && res.symbol != deal1.symbol) {
            deal2 = res;
        };
    };

    // 3
    double roll3 = dist(rng);
    
    Outcome deal3;

    for (Outcome &res : outcomes) {
        if (roll3 >= res.lowR && roll3 < res.highR && res.symbol != deal1.symbol && res.symbol != deal2.symbol) {
            deal3 = res;
        };
    };

    // Create symbols
    std::string symbol1;
    std::string symbol2;
    std::string symbol3;

    std::vector<std::string> symbols = {
        symbol1, symbol2, symbol3
    };

    std::cout << lossDeal.symbol << "\n";

    // Pick symbols
    if (deal.payout == 0) {
        if (lossDeal.symbol == "3ofkind") {
            symbols[0] = deal.symbol;
            symbols[1] = deal.symbol;
            symbols[2] = deal.symbol;
        } else if (lossDeal.symbol == "2ofkind") {
            symbols[0] = dupeDeal.symbol;
            symbols[1] = dupeDeal.symbol;
            symbols[2] = oddDeal.symbol;
        } else {
            symbols[0] = deal1.symbol;
            symbols[1] = deal2.symbol;
            symbols[2] = deal3.symbol;
        }
    } else {
        symbols[0] = deal.symbol;
        symbols[1] = deal.symbol;
        symbols[2] = deal.symbol;
    };

    // Shuffle symbols
    std::shuffle(symbols.begin(), symbols.end(), rng);

    // Ticket stages
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
    
    // Scratch game
    std::string input = "";
    int count = 0;

    std::cout << "Scratch to win!\n";

    do {
        if (count >= ticket.size()) {
            break;
        }

        std::getline(std::cin, input);

        if (input == "") {
        std::cout << ticket[count];
        count++;
        }

    } while (1);

    // Show result
    if (deal.payout == 0) {
        std::cout << "\nD'oh! Nothing...\n";
    } else {
        std::cout << "\nWoo-hoo! You won $" + std::to_string(deal.payout) + "!\n";
    };

    return 0;

}