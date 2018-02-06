#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 8;

enum state_t { QUEEN, CHECKED, FREE };

struct point_t {
	int x, y;
	state_t state;
};

vector<vector<point_t>> chessboard;

void initialize_chessboard(void);
void show_chessboard(void);
bool find_placement(point_t queen);
void place(point_t queen);
void remove(point_t queen);
bool placable(point_t queen);
bool solved(void);
bool in_range(point_t queen, point_t pt);

int main(void) {
	point_t queen = { 0, 0, QUEEN };

	initialize_chessboard();

	if (find_placement(queen)) {
		cout << "Possible solution:" << endl;
		show_chessboard();
	}
	else
		cout << "No solution exists" << endl;

	cin.get();
	return 0;
}

bool find_placement(point_t queen) {
	place(queen);
	if (solved())
		return true;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			point_t next_queen;
			next_queen.x = c;
			next_queen.y = r;
			next_queen.state = QUEEN;
			if (placable(next_queen)) {
				if (find_placement(next_queen))
					return true;
			}
		}
	}
	remove(queen);
	return false;
}

void remove(point_t queen) {
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row) {
			if (in_range(queen, pt))
				chessboard[pt.x][pt.y].state = FREE;
		}
	}
	for (vector<point_t> row : chessboard) {
		for (point_t qn : row) {
			if (qn.state == QUEEN) {
				place(qn);
			}
		}
	}
}

void place(point_t queen) {
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row) {
			if (in_range(queen, pt))
				chessboard[pt.x][pt.y].state = CHECKED;
		}
	}
	chessboard[queen.x][queen.y].state = QUEEN;
}

bool in_range(point_t queen, point_t pt) {
	return (queen.x == pt.x) || (queen.y == pt.y) || ((queen.x - pt.x) == (queen.y - pt.y)) || ((queen.x - pt.x) == (pt.y - queen.y));
}

bool placable(point_t queen) {
	return (chessboard[queen.x][queen.y].state == FREE);
}

bool solved(void) {
	int n_queens = 0;
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row) {
			if (pt.state == QUEEN)
				n_queens++;
		}
	}
	return (n_queens == SIZE);
}

void initialize_chessboard(void) {
	for (int r = 0; r < SIZE; r++) {
		vector<point_t> row;
		for (int c = 0; c < SIZE; c++) {
			point_t pt;
			pt.x = r;
			pt.y = c;
			pt.state = FREE;
			row.push_back(pt);
		}
		chessboard.push_back(row);
	}
}

void show_chessboard(void) {
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row)
			cout << setw(2) << pt.state;
		cout << endl;
	}
	cout << endl;
}
