#include <iostream>
#include <string>
#include "mazelib.h"

using namespace std;

const string FILE_NAME = "maze3.txt";
const int NO_SOLUTION = 10000;

int shortest_path_length(point_t pt);
int solve_maze(point_t pt, int solution);

int main(void) {
	read_maze_map(FILE_NAME);
	cout << shortest_path_length(get_start_position());

	cin.get();
	return 0;
}

int shortest_path_length(point_t pt) {
	int s = 0;
	return solve_maze(pt, s);
}

int solve_maze(point_t pt, int solution) {
	if (outside_maze(pt))
		return solution;
	if (is_marked(pt))
		return NO_SOLUTION;
	mark_square(pt);
	show_maze();
	int best_solution = NO_SOLUTION;
	for (int i = 0; i < 4; i++) {
		direction_t dir = direction_t(i);
		if (!wall_exists(pt, dir)) {
			int new_solution = solve_maze(adjacent_point(pt, dir), solution + 1);
			if (new_solution < best_solution)
				best_solution = new_solution;
		}
	}
	unmark_square(pt);
	show_maze();
	return best_solution;
}
