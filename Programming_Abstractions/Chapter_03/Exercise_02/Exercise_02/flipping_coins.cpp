#include <iostream>
#include <cstdlib>

using namespace std;

const int IN_A_ROW = 3;

enum coin_t { HEADS, TAILS };

coin_t coin_flip(void);

int main(void) {
    int consecutive_heads_count = 0;
    int amount_of_flips = 0;

    while (consecutive_heads_count < 3) {
        amount_of_flips++;
        switch (coin_flip()) {
            case HEADS:
                cout << "heads" << endl;
                consecutive_heads_count++;
                break;
            case TAILS:
                cout << "tails" << endl;
                consecutive_heads_count = 0;
                break;
            default:
                cout << "ERROR!" << endl;
        }
    }

    cout << "It took " << amount_of_flips << " flips to get " << IN_A_ROW << " consecutive heads.";

    cin.get();
    return 0;
}

coin_t coin_flip(void) {
    return coin_t(rand() % 2);
}
