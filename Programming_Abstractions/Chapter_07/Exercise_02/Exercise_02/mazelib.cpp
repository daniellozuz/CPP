#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "mazelib.h"

using namespace std;

vector<vector<char>> maze;

void show_maze(void) {
	for (vector<char> row : maze) {
		for (char ch : row)
			cout << ch;
		cout << endl;
	}
}

void read_maze_map(string filename) {
	ifstream in_file;
	string line;
	in_file.open(filename.c_str());
	if (in_file.fail())
		cout << "Error, file does not exist!" << endl;
	while (getline(in_file, line)) {
		vector<char> row;
		for (char ch : line)
			row.push_back(ch);
		maze.push_back(row);
	}
}

point_t get_start_position(void) {
	for (int r = 0; r < maze.size(); r++) {
		for (int c = 0; c < maze[0].size(); c++) {
			if (maze[r][c] == 'S') {
				point_t pt;
				pt.x = (c - 1) / 2;
				pt.y = (maze.size() - r - 1) / 2;
				return pt;
			}
		}
	}
}

bool outside_maze(point_t pt) {
	return (pt.x < 0) || (pt.x >= (maze[0].size() - 1) / 2) || (pt.y < 0) || (pt.y >= (maze.size() - 1) / 2);
}

int get_column(point_t pt) {
	return 2 * pt.x + 1;
}

int get_row(point_t pt) {
	return maze.size() - 2 * (pt.y + 1);
}

bool wall_exists(point_t pt, direction_t dir) {
	int r = get_row(pt);
	int c = get_column(pt);
	switch (dir) {
	case North: r -= 1; break;
	case South: r += 1; break;
	case East: c += 1; break;
	case West: c -= 1; break;
	}
	return (maze[r][c] == '-' || maze[r][c] == '|');
}

void mark_square(point_t pt) {
	maze[get_row(pt)][get_column(pt)] = 'X';
}

void unmark_square(point_t pt) {
	maze[get_row(pt)][get_column(pt)] = ' ';
}

bool is_marked(point_t pt) {
	return maze[get_row(pt)][get_column(pt)] == 'X';
}

point_t adjacent_point(point_t pt, direction_t dir) {
	point_t new_pt = pt;
	switch (dir) {
	case North: new_pt.y++; break;
	case East: new_pt.x++; break;
	case South: new_pt.y--; break;
	case West: new_pt.x--; break;
	}
	return new_pt;
}
