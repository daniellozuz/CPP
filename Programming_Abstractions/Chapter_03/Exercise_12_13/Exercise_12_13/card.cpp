#include <iostream>
#include <string>

using namespace std;

const int Jack = 11;
const int Queen = 12;
const int King = 13;
const int Ace = 14;

enum rank_t { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum suit_t { CLUBS, DIAMONDS, HEARTS, SPADES };
struct card_t {
    rank_t rank;
    suit_t suit;
};

card_t new_card(int rank, int suit) {
    card_t card;
    card.rank = rank_t(rank);
    card.suit = suit_t(suit);
    return card;
}

rank_t rank(card_t card) {
    return rank_t(card.rank);
}

suit_t suit(card_t card) {
    return suit_t(card.suit);
}

string card_name(card_t card) {
    string name = "";
    switch (card.rank) {
        case TWO: name += "2"; break;
        case THREE: name += "3"; break;
        case FOUR: name += "4"; break;
        case FIVE: name += "5"; break;
        case SIX: name += "6"; break;
        case SEVEN: name += "7"; break;
        case EIGHT: name += "8"; break;
        case NINE: name += "9"; break;
        case TEN: name += "T"; break;
        case JACK: name += "J"; break;
        case QUEEN: name += "Q"; break;
        case KING: name += "K"; break;
        case ACE: name += "A"; break;
        default: name += "ERROR!";
    }
    switch (card.suit) {
        case CLUBS: name += "C"; break;
        case DIAMONDS: name += "D"; break;
        case HEARTS: name += "H"; break;
        case SPADES: name += "S"; break;
        default: name += "ERROR!";
    }
    return name;
}
