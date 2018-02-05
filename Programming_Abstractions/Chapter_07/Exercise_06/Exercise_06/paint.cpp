#include <iostream>
#include <string>
#include "houselib.h"

using namespace std;

const string FILE_NAME = "house.txt";

void paint(point_t pt);

int main(void) {
	point_t pt;

	read_house(FILE_NAME);

	pt.x = 2;
	pt.y = 2;
	pt.state = get_pixel_state(pt);
	
	show_house();
	paint(pt);
	show_house();

	cin.get();
	return 0;
}

void paint(point_t pt) {
	if (get_pixel_state(pt) == WHITE) {
		set_pixel_state(pt, BLACK);
		for (int i = 0; i < 4; i++)
			paint(adjacent_point(pt, direction_t(i)));
	}
}
