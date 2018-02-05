#ifndef _houselib_h
#define _houselib_h

#include <string>

using namespace std;

enum direction_t { UP, RIGHT, DOWN, LEFT };
enum pixel_state_t { WHITE, BLACK };

struct point_t {
	int x, y;
	pixel_state_t state;
};

void read_house(string filename);
void show_house(void);
point_t adjacent_point(point_t pt, direction_t dir);
bool outside_pixel_bounds(point_t pt);
pixel_state_t get_pixel_state(point_t pt);
void set_pixel_state(point_t pt, pixel_state_t state);

#endif
