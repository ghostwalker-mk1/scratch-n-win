#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>

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

    ticket.v1 = rand() % 10 + 1;
    ticket.v2 = rand() % 10 + 1;
    ticket.v3  = rand() % 10 + 1;

    cout << "Ticket values are: " << ticket.v1 << ticket.v2 << ticket.v3;

    return 0;

}