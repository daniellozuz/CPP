#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "houselib.h"

using namespace std;

vector<vector<point_t>> house;

void read_house(string filename) {
	ifstream in_file;
	string line;
	int r = 0;
	in_file.open(filename.c_str());
	if (in_file.fail())
		cout << "Error, file does not exist!" << endl;
	while (getline(in_file, line)) {
		vector<point_t> row;
		for (int c = 0; c < line.length(); c++) {
			point_t pt;
			pt.x = c;
			pt.y = r;
			pt.state = (line[c] == 'X') ? BLACK : WHITE;
			row.push_back(pt);
		}
		house.push_back(row);
		r++;
	}
}

void show_house(void) {
	for (vector<point_t> row : house) {
		for (point_t pt : row)
			cout << pt.state;
		cout << endl;
	}
	cout << endl;
}

point_t adjacent_point(point_t pt, direction_t dir) {
	point_t new_pt = pt;
	switch (dir) {
		case UP: new_pt.y--; break;
		case RIGHT: new_pt.x++; break;
		case DOWN: new_pt.y++; break;
		case LEFT: new_pt.x--; break;
	}
	new_pt.state = (outside_pixel_bounds(new_pt)) ? BLACK : house[new_pt.y][new_pt.x].state;
	return new_pt;
}

bool outside_pixel_bounds(point_t pt) {
	return (pt.x < 0 || pt.x >= house[0].size() || pt.y < 0 || pt.y >= house.size());
}

pixel_state_t get_pixel_state(point_t pt) {
	return (outside_pixel_bounds(pt)) ? BLACK : house[pt.y][pt.x].state;
}

void set_pixel_state(point_t pt, pixel_state_t state) {
	house[pt.y][pt.x].state = state;
}
