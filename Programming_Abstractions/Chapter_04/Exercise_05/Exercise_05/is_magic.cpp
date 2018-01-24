#include <iostream>
#include <vector>

using namespace std;

bool is_magic_square(vector<vector<int>> &square);
int sum_line(vector<vector<int>> &square, int row, int col, int d_row, int d_col);

int main(void) {
    vector<vector<int>> magic_square1 = {
        { 8, 1, 6 },
        { 3, 5, 7 },
        { 4, 9, 2 },
    };
    vector<vector<int>> magic_square2 = {
        { 16, 3, 2, 13 },
        { 5, 10, 11, 8 },
        { 9, 6, 7, 12 },
        { 4, 15, 14, 1 },
    };
    vector<vector<int>> not_a_magic_square1 = {
        { 1, 2 },
        { 3, 4 },
    };
    vector<vector<int>> not_a_magic_square2 = {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 },
    };

    cout << is_magic_square(magic_square1) << endl;
    cout << is_magic_square(magic_square2) << endl;
    cout << is_magic_square(not_a_magic_square1) << endl;
    cout << is_magic_square(not_a_magic_square2) << endl;

    cin.get();
    return 0;
}

bool is_magic_square(vector<vector<int>> &square) {
    int value;
    if (square.size() != square[0].size())
        return false;
    value = sum_line(square, 0, 0, 1, 1);
    for (int i = 0; i < square.size(); i++) {
        if (sum_line(square, 0, i, 1, 0) != value || sum_line(square, i, 0, 0, 1) != value)
            return false;
    }
    return sum_line(square, 0, square.size() - 1, 1, -1) == value;
}

int sum_line(vector<vector<int>> &square, int row, int col, int d_row, int d_col) {
    int value = 0;
    for (int i = 0; i < square.size(); i++)
        value += square[row + i * d_row][col + i * d_col];
    return value;
}
