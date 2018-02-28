#include <iostream>
#include "Grid.h"

using namespace std;

int main(void) {
	Grid<int> grid;

	cout << (grid.num_rows() == 0) << endl;
	cout << (grid.num_cols() == 0) << endl;

	grid.resize(2, 3);

	cout << (grid.num_rows() == 2) << endl;
	cout << (grid.num_cols() == 3) << endl;

	Grid<int> grid2(2, 3);

	cout << (grid2.num_rows() == 2) << endl;
	cout << (grid2.num_cols() == 3) << endl;


	//grid.set_at(0, 0, 1);
	//grid.set_at(0, 1, 2);
	//grid.set_at(0, 2, 3);
	//grid.set_at(1, 0, 4);
	//grid.set_at(1, 1, 5);
	//grid.set_at(1, 2, 6);


	/*
	cout << (vec.is_empty() == 1);

	for (int i = 0; i < 10; i++) {
		vec.add(i);
		cout << (vec.size() == i + 1);
		cout << (vec.is_empty() == 0);
		cout << (vec.get_at(i) == i);
	}

	vec.set_at(2, 99);
	cout << (vec.get_at(2) == 99);

	cout << (vec.get_at(5) == 5);
	vec.insert_at(5, -2);
	cout << (vec.get_at(5) == -2);
	vec.remove_at(5);
	cout << (vec.get_at(5) == 5);

	vec.clear();
	cout << (vec.is_empty() == 1);
	cout << (vec.size() == 0);
	*/

	cin.get();
	return 0;
}
