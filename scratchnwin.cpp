#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <array>
#include <map>

using namespace std;

int main () {

    struct {
        double prob = 0.695;
        int payout = 0;
        string symbol = "💣";
        double lowR = 0;
        double highR = 0.695;
    } lose;

    struct {
        double prob = 0.170;
        int payout = 1;
        string symbol = "🍋";
        double lowR = 0.695;
        double highR = 0.865;
    } small1;

    struct {
        double prob = 0.070;
        int payout = 2;
        string symbol = "🍒";
        double lowR = 0.865;
        double highR = 0.935;
    } small2;

    struct {
        double prob = 0.040;
        int payout = 5;
        string symbol = "🍇";
        double lowR = 0.935;
        double highR = 0.975;
    } mid;

    struct {
        double prob = 0.015;
        int payout = 10;
        string symbol = "🔔";
        double lowR = 0.975;
        double highR = 0.990;
    } big;

    struct {
        double prob = 0.010;
        int payout = 25;
        string symbol = "⭐";
        double lowR = 0.990;
        double highR = 1.000;
    } jackpot;

    srand(time(NULL));

    double roll = ((double) rand() / RAND_MAX);
    cout << roll <<"\n";
    
    
    array<string, 4> banners = {
    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",

    " --SCRATCH 'N' WIN-- \n"
    "|    ___ ___ ___    |\n"
    "|   |   |   |   |   |\n"
    "|    --- --- ---    |\n"
    " ------------------- \n",
    };

    return 0;

}