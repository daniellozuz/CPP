#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 8;

enum direction_t { DDR, DRR, URR, UUL, UUR, DLL, DDL, ULL };

struct point_t {
	int x, y;
	int state;
};

vector<vector<point_t>> chessboard;

void initialize_chessboard(void);
void show_chessboard(void);
bool find_tour(point_t pt);
bool outside_board(point_t pt);
bool occupied(point_t pt);
void occupy(point_t pt);
void unoccupy(point_t pt);
point_t next_position(point_t pt, direction_t dir);
bool secluded(point_t pt);
bool close(point_t now_pt, point_t pt);
bool all_around_occupied(point_t pt);

int main(void) {
	point_t pt = { 0, 0, 1 };

	initialize_chessboard();

	find_tour(pt);

	show_chessboard();

	cin.get();
	return 0;
}

bool find_tour(point_t pt) {
	occupy(pt);
	if (pt.state == SIZE * SIZE)
		return true;
	if (!secluded(pt)) {
		for (int i = 0; i < 8; i++) {
			point_t next_pt = next_position(pt, direction_t(i));
			if (!outside_board(next_pt) && !occupied(next_pt)) {
				if (find_tour(next_pt))
					return true;
			}
		}
	}
	unoccupy(pt);
	return false;
}

bool secluded(point_t now_pt) {
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row) {
			if (!occupied(pt)) {
				if (!close(now_pt, pt) && all_around_occupied(pt))
					return true;
			}
		}
	}
	return false;
}

bool all_around_occupied(point_t pt) {
	for (int i = 0; i < 8; i++) {
		point_t next_pt = next_position(pt, direction_t(i));
		if (!outside_board(next_pt)) {
			if (!occupied(next_pt))
				return false;
		}
	}
	return true;
}

bool close(point_t now_pt, point_t pt) {
	for (int i = 0; i < 8; i++) {
		point_t next_pt = next_position(now_pt, direction_t(i));
		if (next_pt.x == pt.x && next_pt.y == pt.y)
			return true;
	}
	return false;
}

point_t next_position(point_t pt, direction_t dir) {
	point_t new_pt = pt;
	switch (dir) {
		case ULL: new_pt.x -= 2; new_pt.y--; break;
		case UUL: new_pt.x--; new_pt.y -= 2; break;
		case UUR: new_pt.x++; new_pt.y -= 2; break;
		case URR: new_pt.x += 2; new_pt.y--; break;
		case DLL: new_pt.x -= 2; new_pt.y++; break;
		case DDL: new_pt.x--; new_pt.y += 2; break;
		case DDR: new_pt.x++; new_pt.y += 2; break;
		case DRR: new_pt.x += 2; new_pt.y++; break;
	}
	new_pt.state++;
	return new_pt;
}

void unoccupy(point_t pt) {
	chessboard[pt.x][pt.y].state = 0;
}

void occupy(point_t pt) {
	chessboard[pt.x][pt.y].state = pt.state;
}

bool occupied(point_t pt) {
	return (chessboard[pt.x][pt.y].state != 0);
}

bool outside_board(point_t pt) {
	return (pt.x < 0 || pt.x >= SIZE || pt.y < 0 || pt.y >= SIZE);
}

void initialize_chessboard(void) {
	for (int r = 0; r < SIZE; r++) {
		vector<point_t> row;
		for (int c = 0; c < SIZE; c++) {
			point_t pt;
			pt.x = r;
			pt.y = c;
			pt.state = 0;
			row.push_back(pt);
		}
		chessboard.push_back(row);
	}
}

void show_chessboard(void) {
	for (vector<point_t> row : chessboard) {
		for (point_t pt : row)
			cout << setw(3) << pt.state;
		cout << endl;
	}
}
