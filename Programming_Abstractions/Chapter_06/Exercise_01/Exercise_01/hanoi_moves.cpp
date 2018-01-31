#include <iostream>

using namespace std;

int n_hanoi_moves(int n);
int move_tower(int n, int &moves);

int main(void) {
    cout << n_hanoi_moves(1) << endl;
    cout << n_hanoi_moves(2) << endl;
    cout << n_hanoi_moves(3) << endl;
    cout << n_hanoi_moves(4) << endl;

    cin.get();
    return 0;
}

int n_hanoi_moves(int n) {
    int moves = 0;
    return move_tower(n, moves);
}

int move_tower(int n, int &moves) {
    if (n != 1) {
        move_tower(n - 1, moves);
        move_tower(n - 1, moves);
    }
    return ++moves;
}
