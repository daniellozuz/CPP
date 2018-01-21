#include <iostream>
#include <iomanip>
#include "card.h"

using namespace std;

const int CARDS_COUNT = 52;

void initialize(card_t *deck);
void shuffle(card_t *deck);
void display(card_t *deck);

int main(void) {
    card_t deck[CARDS_COUNT];

    initialize(deck);
    shuffle(deck);
    display(deck);

    cin.get();
    return 0;
}

void initialize(card_t *deck) {
    for (int suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = TWO; rank <= ACE; rank++)
            deck[13 * suit + rank - 2] = new_card(rank, suit);
    }
}

void shuffle(card_t *deck) {
    for (int i = 0; i < CARDS_COUNT; i++) {
        int j = rand() % CARDS_COUNT;
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void display(card_t *deck) {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 12; j++)
            cout << setw(4) << card_name(deck[13 * i + j]);
        cout << endl;
    }
}
