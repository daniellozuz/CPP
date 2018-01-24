#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 9;

bool check_sudoku_solution(vector<vector<int>> &puzzle);
bool is_valid(vector<vector<int>> &puzzle);
bool check_line(vector<vector<int>> &puzzle, int row, int col, int d_row, int d_col);
bool check_square(vector<vector<int>> &puzzle, int row, int col);
bool check(vector<int> &nine);
vector<int> sorted(vector<int> &nine);

int main(void) {
    vector<vector<int>> solved = {
        { 3, 9, 2, 4, 6, 5, 8, 1, 7 },
        { 7, 4, 1, 8, 9, 3, 6, 2, 5 },
        { 6, 8, 5, 2, 7, 1, 4, 3, 9 },
        { 2, 5, 4, 1, 3, 8, 7, 9, 6 },
        { 8, 3, 9, 6, 2, 7, 1, 5, 4 },
        { 1, 7, 6, 9, 5, 4, 2, 8, 3 },
        { 9, 6, 7, 5, 8, 2, 3, 4, 1 },
        { 4, 2, 3, 7, 1, 9, 5, 6, 8 },
        { 5, 1, 8, 3, 4, 6, 9, 7, 2 },
    };
    vector<vector<int>> not_solved = {
        { 3, 9, 2, 4, 6, 5, 8, 1, 7 },
        { 7, 4, 1, 8, 9, 3, 6, 2, 5 },
        { 6, 8, 5, 2, 7, 1, 4, 3, 9 },
        { 2, 5, 4, 1, 3, 8, 7, 9, 6 },
        { 8, 3, 9, 6, 2, 5, 1, 7, 4 },
        { 1, 7, 6, 9, 5, 4, 2, 8, 3 },
        { 9, 6, 7, 5, 8, 2, 3, 4, 1 },
        { 4, 2, 3, 7, 1, 9, 5, 6, 8 },
        { 5, 1, 8, 3, 4, 6, 9, 7, 2 },
    };
    vector<vector<int>> invalid = {
        { 3, 9, 2 },
        { 7, 4, 1 },
        { 6, 8, 5 },
    };

    cout << check_sudoku_solution(solved) << endl;
    cout << check_sudoku_solution(not_solved) << endl;
    cout << check_sudoku_solution(invalid) << endl;

    cin.get();
    return 0;
}

bool check_sudoku_solution(vector<vector<int>> &puzzle) {
    if (!is_valid(puzzle))
        return false;
    for (int i = 0; i < SIZE; i++) {
        if (!check_line(puzzle, 0, i, 1, 0) || !check_line(puzzle, i, 0, 0, 1))
            return false;
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (!check_square(puzzle, row, col))
                return false;
        }
    }
    return true;
}

bool is_valid(vector<vector<int>> &puzzle) {
    if (puzzle.size() != SIZE)
        return false;
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i].size() != SIZE)
            return false;
    }
    return true;
}

bool check_line(vector<vector<int>> &puzzle, int row, int col, int d_row, int d_col) {
    vector<int> nine;
    for (int i = 0; i < SIZE; i++)
        nine.push_back(puzzle[row + i*d_row][col + i*d_col]);
    return check(nine);
}

bool check_square(vector<vector<int>> &puzzle, int row, int col) {
    vector<int> nine;
    for (int i = 3 * row; i < 3 * (row + 1); i++) {
        for (int j = 3 * col; j < 3 * (col + 1); j++)
            nine.push_back(puzzle[i][j]);
    }
    return check(nine);
}

bool check(vector<int> &nine) {
    vector<int> solved = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    return (sorted(nine) == solved);
}

vector<int> sorted(vector<int> &nine) {
    sort(nine.begin(), nine.begin() + SIZE);
    return nine;
}
