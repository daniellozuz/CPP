#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int INITIAL_STAKE = 50;

enum symbol_t { CHERRY, LEMON, ORANGE, PLUM, BELL, BAR };

symbol_t spin(void);
int payoff(symbol_t symbol1, symbol_t symbol2, symbol_t symbol3);

int main(void) {
    string decision;
    int stake = INITIAL_STAKE;

    while (stake > 0) {
        cout << "You have $" << stake << ". Would you like to play? ";
        getline(cin, decision);
        if (decision == "yes") {
            // stake += payoff(spin(), spin(), spin()); DOES NOT WORK o.O?
            symbol_t symbol1 = spin();
            symbol_t symbol2 = spin();
            symbol_t symbol3 = spin();
            stake += payoff(symbol1, symbol2, symbol3);
        }
        else if (decision == "no")
            break;
        else
            cout << "Invalid command. Enter: (yes/no)." << endl;
    }

    cin.get();
    return 0;
}

symbol_t spin(void) {
    symbol_t symbol = symbol_t(rand() % 6);
    switch (symbol) {
        case CHERRY: cout << setw(7) << left << "CHERRY"; break;
        case LEMON: cout << setw(7) << left << "LEMON"; break;
        case ORANGE: cout << setw(7) << left << "ORANGE"; break;
        case PLUM: cout << setw(7) << left << "PLUM"; break;
        case BELL: cout << setw(7) << left << "BELL"; break;
        case BAR: cout << setw(7) << left << "BAR"; break;
        default: cout << setw(7) << left << "ERROR!";
    }
    return symbol;
}

int payoff(symbol_t symbol1, symbol_t symbol2, symbol_t symbol3) {
    if (symbol1 == BAR && symbol2 == BAR && symbol3 == BAR) return 250;
    if (symbol1 == BELL && symbol2 == BELL && (symbol3 == BELL || symbol3 == BAR)) return 20;
    if (symbol1 == PLUM && symbol2 == PLUM && (symbol3 == PLUM || symbol3 == BAR)) return 14;
    if (symbol1 == ORANGE && symbol2 == ORANGE && (symbol3 == ORANGE || symbol3 == BAR)) return 10;
    if (symbol1 == CHERRY && symbol2 == CHERRY && symbol3 == CHERRY) return 7;
    if (symbol1 == CHERRY && symbol2 == CHERRY) return 5;
    if (symbol1 == CHERRY) return 2;
    return -1;
}
