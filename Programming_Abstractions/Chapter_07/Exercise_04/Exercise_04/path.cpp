#include <iostream>
#include <string>
#include <vector>
#include "mazelib.h"

using namespace std;

const string FILE_NAME = "maze2.txt";

bool find_path(point_t pt, vector<point_t> &path);

int main(void) {
	vector<point_t> path;

	read_maze_map(FILE_NAME);
	if (find_path(get_start_position(), path)) {
		cout << "The following path is a solution:" << endl;
		for (int i = 0; i < path.size(); i++)
			cout << "(" << path[i].x << ", " << path[i].y << ")" << endl;
	}
	else
		cout << "No solution exists." << endl;

	cin.get();
	return 0;
}

bool find_path(point_t pt, vector<point_t> &path) {
	if (outside_maze(pt))
		return true;
	if (is_marked(pt))
		return false;
	mark_square(pt);
	path.push_back(pt);
	show_maze();
	for (int i = 0; i < 4; i++) {
		direction_t dir = direction_t(i);
		if (!wall_exists(pt, dir)) {
			if (find_path(adjacent_point(pt, dir), path))
				return true;
		}
	}
	unmark_square(pt);
	path.pop_back();
	show_maze();
	return false;
}
