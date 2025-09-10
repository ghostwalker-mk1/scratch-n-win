#include "game_core.cpp"
#include <iostream>
#include <fstream>

int main() {

    int n = 100000;
    int totalSpent = n * 1;
    int wins = 0;
    int totalPayout = 0;
    int totalSymbols = n * 3;

    std::cout << "Simulating " << n << " games...\n";

    std::ofstream MyFile("output.txt");

    MyFile << "TicketID,Symbol1,Symbol2,Symbol3,Win,Payout\n";

    // Gameplay simulation
    for (int i = 0; i < n; i++) {

        payout = 0;

        std::vector<std::string> symbols = generateTicket();

        bool isWin;

        isWin = checkWin(&symbols);

        MyFile << i + 1 << "," << symbols[0] << "," 
        << symbols[1] << "," << symbols[2] << "," 
        << isWin << "," << payout << "\n";

    };

    MyFile.close();

    std::cout << "Done!\n";

    /*
    double winRate = (double(wins) / double(n)) * 100;
    double rtp = (double(totalPayout) / double(totalSpent)) * 100;

    std::cout << "---------- TEST RESULTS ----------\n";

    std::cout << "Simulation of " << n << " scratch tickets:" "\n\n";

    std::cout << "Amount spent: " << "$" << totalSpent << "\n\n";

    std::cout << "Total Wins: " << wins << "\n\n";

    std::cout << "Win rate: " << winRate << "%" << "\n\n";

    std::cout << "Total payout: " << "$" << totalPayout << "\n\n";

    std::cout << "RTP (Return to Player): " << rtp << "%" << "\n";

    std::cout << "--------------------------------\n";
    */

    return 0;
}