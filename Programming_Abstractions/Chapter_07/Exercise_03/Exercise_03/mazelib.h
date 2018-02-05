#ifndef _mazelib_h
#define _mazelib_h

#include <string>

using namespace std;

enum direction_t { North, East, South, West };

struct point_t {
	int x, y;
};

void read_maze_map(string filename);
point_t get_start_position(void);
bool outside_maze(point_t pt);
bool wall_exists(point_t pt, direction_t dir);
void mark_square(point_t pt);
void unmark_square(point_t pt);
bool is_marked(point_t pt);
point_t adjacent_point(point_t pt, direction_t dir);
void show_maze(void);

#endif
