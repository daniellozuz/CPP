#include <iostream>
#include <string>
#include "mazelib.h"

using namespace std;

const string FILE_NAME = "maze4.txt";

bool solve_maze(point_t pt, int &n_calls, bool fast_version);

int main(void) {
	int n_calls_slow = 0;
	int n_calls_fast = 0;

	read_maze_map(FILE_NAME);
	solve_maze(get_start_position(), n_calls_slow, false);
	cout << "Calls with unmarking: " << n_calls_slow << endl;

	read_maze_map(FILE_NAME);
	solve_maze(get_start_position(), n_calls_fast, true);
	cout << "Calls without unmarking: " << n_calls_fast << endl;

	cin.get();
	return 0;
}

bool solve_maze(point_t pt, int &n_calls, bool fast_version) {
	n_calls++;
	if (outside_maze(pt))
		return true;
	if (is_marked(pt))
		return false;
	mark_square(pt);
	for (int i = 0; i < 4; i++) {
		direction_t dir = direction_t(i);
		if (!wall_exists(pt, dir)) {
			if (solve_maze(adjacent_point(pt, dir), n_calls, fast_version))
				return true;
		}
	}
	if (!fast_version)
		unmark_square(pt);
	return false;
}
