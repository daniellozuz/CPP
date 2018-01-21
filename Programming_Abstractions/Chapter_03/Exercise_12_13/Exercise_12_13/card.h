#include <string>

using namespace std;

#ifndef _CARD_H
#define _CARD_H

const int Jack = 11;
const int Queen = 12;
const int King = 13;
const int Ace = 14;

extern enum rank_t { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum suit_t { CLUBS, DIAMONDS, HEARTS, SPADES };

struct card_t {
    rank_t rank;
    suit_t siut;
};

card_t new_card(int rank, int suit);
rank_t rank(card_t card);
suit_t suit(card_t card);
string card_name(card_t card);

#endif
