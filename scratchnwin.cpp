#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <array>

using namespace std;

class Player {
    public:
        int money;
};

class Ticket {
    public:
        int v1, v2, v3;
};

int main () {
    srand (time(NULL));

    Player player;
    Ticket ticket;

    ticket.v1 = rand() % 9 + 1;
    ticket.v2 = rand() % 9 + 1;
    ticket.v3  = rand() % 9 + 1;

    array<string, 4> banners = {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + to_string(ticket.v1) + " |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + to_string(ticket.v1) + " | " + to_string(ticket.v2) + " |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   | " + to_string(ticket.v1) + " | " + to_string(ticket.v2) + " | " + to_string(ticket.v3) + " |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",
    };

    for (const auto& banner : banners) {
        cout << banner << "\n\n";
    }

    return 0;

}