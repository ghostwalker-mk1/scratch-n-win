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

#include "game_core.cpp"

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