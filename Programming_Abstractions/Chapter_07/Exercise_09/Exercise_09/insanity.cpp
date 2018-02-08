#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

enum color_t { G, W, B, R };
typedef vector<color_t> cube_t;

// First element - top, Last element - bottom, Other elements - sides.
vector<cube_t> CUBES = {
	{ G, W, B, B, R, G },
	{ R, W, W, G, B, G },
	{ W, R, R, W, B, G },
	{ B, G, R, R, R, W },
};
vector<cube_t> column;

bool build(int height_remaining);
bool repeating_colors(vector<cube_t> column);
vector<cube_t> all_possible_orientations(cube_t cube);
vector<cube_t> possible_orientations(cube_t cube, vector<int> indeces);
void show(vector<cube_t> column);

int main(void) {

	if (build(CUBES.size())) {
		cout << "Found solution!" << endl;
		show(column);
	}
	else
		cout << "No solution!" << endl;

	cin.get();
	return 0;
}

bool build(int height_remaining) {
	if (repeating_colors(column))
		return false;
	if (height_remaining == 0)
		return true;
	for (cube_t orientation : all_possible_orientations(CUBES[CUBES.size() - height_remaining])) {
		column.push_back(orientation);
		if (build(height_remaining - 1))
			return true;
		column.pop_back();
	}
	return false;
}

vector<cube_t> all_possible_orientations(cube_t cube) {
	vector<cube_t> orientations;
	vector<vector<int>> indeces = {
		{ 0, 1, 2, 3, 4, 5 },
		{ 1, 2, 0, 4, 5, 3 },
		{ 2, 3, 0, 1, 5, 4 },
		{ 3, 2, 5, 4, 0, 1 },
		{ 4, 3, 5, 1, 0, 2 },
		{ 5, 1, 4, 3, 2, 0 },
	};
	for (int i = 0; i < 6; i++) {
		for (cube_t c : possible_orientations(cube, indeces[i])) {
			orientations.push_back(c);
		}
	}
	return orientations;
}

vector<cube_t> possible_orientations(cube_t cube, vector<int> indeces) {
	vector<cube_t> orientations;
	for (int i = 0; i < 4; i++) {
		cube_t c;
		c.push_back(cube[indeces[0]]);
		c.push_back(cube[indeces[i % 4 + 1]]);
		c.push_back(cube[indeces[(i + 1) % 4 + 1]]);
		c.push_back(cube[indeces[(i + 2) % 4 + 1]]);
		c.push_back(cube[indeces[(i + 3) % 4 + 1]]);
		c.push_back(cube[indeces[5]]);
		orientations.push_back(c);
	}
	return orientations;
}

bool repeating_colors(vector<cube_t> column) {
	for (int s = 0; s < 4; s++) {
		set<color_t> side;
		for (int i = 0; i < column.size(); i++)
			side.insert(column[i][s + 1]);
		if (side.size() < column.size())
			return true;
	}
	return false;
}

void show(vector<cube_t> column) {
	for (cube_t cube : column) {
		for (int i = 0; i < 6; i++) {
			switch (cube[i]) {
				case G: cout << "G "; break;
				case W: cout << "W "; break;
				case B: cout << "B "; break;
				case R: cout << "R "; break;
			}
		}
		cout << endl;
	}
}
