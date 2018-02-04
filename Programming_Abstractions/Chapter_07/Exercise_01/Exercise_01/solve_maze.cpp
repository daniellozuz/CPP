#include <iostream>
#include <string>
#include "mazelib.h"

using namespace std;

const string FILE_NAME = "maze2.txt";

bool solve_maze(point_t pt);

int main(void) {
	read_maze_map(FILE_NAME);
	solve_maze(get_start_position());

	cin.get();
	return 0;
}

bool solve_maze(point_t pt) {
	if (outside_maze(pt))
		return true;
	if (is_marked(pt))
		return false;
	mark_square(pt);
	show_maze();
	for (int i = 0; i < 4; i++) {
		direction_t dir = direction_t(i);
		if (!wall_exists(pt, dir)) {
			if (solve_maze(adjacent_point(pt, dir)))
				return true;
		}
	}
	unmark_square(pt);
	show_maze();
	return false;
}
