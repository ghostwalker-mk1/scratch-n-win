#include "game_core.cpp"

int main() {

    int n = 100000;
    int totalSpent = n * 1;
    int wins = 0;
    int totalPayout = 0;
    int totalSymbols = n * 3;

    for (int i = 0; i < n; i++) {

        payout = 0;

        std::vector<std::string> symbols = generateTicket();

        bool isWin;

        isWin = checkWin(&symbols);

        if (isWin) {
            wins++;
        };

        totalPayout += payout;

    };

    double winRate = (double(wins) / double(n)) * 100;
    double rtp = (double(totalPayout) / double(totalSpent)) * 100;

    std::cout << "---------- TEST SHEET ----------\n";

    std::cout << "Simulation of " << n << " scratch tickets:" "\n\n";

    std::cout << "Amount spent: " << "$" << totalSpent << "\n\n";

    std::cout << "Total Wins: " << wins << "\n\n";

    std::cout << "Win rate: " << winRate << "%" << "\n\n";

    std::cout << "Total payout: " << "$" << totalPayout << "\n\n";

    std::cout << "RTP (Return to Player): " << rtp << "%" << "\n";

    std::cout << "--------------------------------\n";

    return 0;
}