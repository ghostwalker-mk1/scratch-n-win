#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <random>
#include <algorithm> 

// Symbol struct
struct Outcome {
    double prob;
    int payout;
    std::string symbol;
    double lowR;
    double highR;
};

std::vector<Outcome> outcomes = {
    {0.45, 1, "🍋", 0.0, 0.45},   // Lemon
    {0.30, 2, "🍒", 0.45, 0.70},  // Cherry
    {0.15, 5, "🍇", 0.70, 0.85},  // Grape
    {0.08, 10, "🔔", 0.85, 0.95}, // Liberty Bell
    {0.02, 50, "💲", 0.95, 1.00}  // Dollar
};

int payout = 0;

std::vector<std::string> generateTicket() {
    // RNG
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Generate three symbols for the scratch card
    std::vector<std::string> symbols(3);
    
    for (int i = 0; i < 3; i++) {
        double roll = dist(rng);
        
        // Find which outcome this roll falls under
        for (const Outcome& outcome : outcomes) {
            if (roll >= outcome.lowR && roll < outcome.highR) {
                symbols[i] = outcome.symbol;
                break;
            }
        }
    }

    return symbols;
};

bool checkWin(std::vector<std::string>* symbols) {
    std::vector<std::string> result;
    result = *symbols;

    // Check if player wins (all three symbols match)
    bool isWin = (result[0] == result[1] && result[1] == result[2]);

    if (isWin) {
        // Find the payout for the winning symbol
        for (const Outcome& outcome : outcomes) {
            if (outcome.symbol == result[0]) {
                payout = outcome.payout;
                break;
            }
        }
    }
    return isWin;
};

int main() {

    std::vector<std::string> symbols = generateTicket();

    bool isWin;

    isWin = checkWin(&symbols);

    // Ticket display layouts
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
        "|   | "+ symbols[0] +"|   |   |   |\n"
        "|    --- --- ---    |\n"
        " ------------------- \n"
        },
        {
        " --SCRATCH 'N' WIN-- \n"
        "|    ___ ___ ___  $1|\n"
        "|   | "+ symbols[0] +"| "+ symbols[1] +"|   |   |\n"
        "|    --- --- ---    |\n"
        " ------------------- \n"
        },
        {
        " --SCRATCH 'N' WIN-- \n"
        "|    ___ ___ ___  $1|\n"
        "|   | "+ symbols[0] +"| "+ symbols[1] +"| "+ symbols[2] +"|   |\n"
        "|    --- --- ---    |\n"
        " ------------------- \n"
        }
    };
    
    // Gameplay loop
    std::string input;
    int count = 0;

    std::cout << "Scratch to win!\n";

    // Display each stage of the ticket (scratch effect)
    while (count < ticket.size()) {
        std::getline(std::cin, input);
        std::cout << ticket[count] << std::endl;
        count++;
    }

    // Show result
    if (isWin) {
        std::cout << "Woo-hoo! You won $" << payout << "!\n";
    } else {
        std::cout << "D'oh! Nothing...\n";
    }

    return 0;
}