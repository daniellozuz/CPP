#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

bool check_for_win(vector<vector<char>> &board, char mark);
bool check_line(vector<vector<char>> &board, char mark, int row, int col, int d_row, int d_col);

int main(void) {
    vector<vector<char>> board = { 
        { 'x', 'o', 'x' },
        { 'x', 'o', 'x' },
        { 'o', 'x', 'o' }
    };

    cout << check_for_win(board, 'x');

    cin.get();
    return 0;
}

bool check_for_win(vector<vector<char>> &board, char mark) {
    for (int i = 0; i < SIZE; i++) {
        if (check_line(board, mark, i, 0, 0, 1) || check_line(board, mark, 0, i, 1, 0))
            return true;
    }
    return (check_line(board, mark, 0, 0, 1, 1) || check_line(board, mark, SIZE - 1, 0, -1, 1));
}

bool check_line(vector<vector<char>> &board, char mark, int row, int col, int d_row, int d_col) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][col] != mark)
            return false;
        row += d_row;
        col += d_col;
    }
    return true;
}
