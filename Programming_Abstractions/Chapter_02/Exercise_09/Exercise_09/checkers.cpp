#include <iostream>

using namespace std;

const int SIZE = 8;

void init_checkerboard(char board[][SIZE]);
void display_checkerboard(char board[][SIZE]);

int main(void) {
    char board[SIZE][SIZE];

    init_checkerboard(board);
    display_checkerboard(board);

    cin.get();
    return 0;
}

void init_checkerboard(char board[][SIZE]) {
    char board_initializer[SIZE][SIZE] = {
        { 32, 'b', 32, 'b', 32, 'b', 32, 'b' },
        { 'b', 32, 'b', 32, 'b', 32, 'b', 32 },
        { 32, 'b', 32, 'b', 32, 'b', 32, 'b' },
        { '-', 32, '-', 32, '-', 32, '-', 32 },
        { 32, '-', 32, '-', 32, '-', 32, '-' },
        { 'r', 32, 'r', 32, 'r', 32, 'r', 32 },
        { 32, 'r', 32, 'r', 32, 'r', 32, 'r' },
        { 'r', 32, 'r', 32, 'r', 32, 'r', 32 },
    };
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++)
            board[r][c] = board_initializer[r][c];
    }
}

void display_checkerboard(char board[][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++)
            cout << board[r][c] << " ";
        cout << endl;
    }
}
