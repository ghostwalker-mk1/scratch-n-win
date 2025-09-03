#ifndef GAME_CORE
#define GAME_CORE

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

#endif