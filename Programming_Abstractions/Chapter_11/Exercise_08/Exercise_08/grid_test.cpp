#include <iostream>
#include "Grid.h"

using namespace std;

int main(void) {
	Grid<int> grid;

	cout << (grid.num_rows() == 0);
	cout << (grid.num_cols() == 0);

	grid.resize(2, 3);

	cout << (grid.num_rows() == 2);
	cout << (grid.num_cols() == 3);

	Grid<int> grid2(2, 3);

	cout << (grid2.num_rows() == 2);
	cout << (grid2.num_cols() == 3);

	grid2.set_at(0, 0, 1);
	grid2.set_at(0, 1, 2);
	grid2.set_at(0, 2, 3);
	grid2.set_at(1, 0, 4);
	grid2.set_at(1, 1, 5);
	grid2.set_at(1, 2, 6);

	cout << (grid2.get_at(0, 0) == 1);
	cout << (grid2.get_at(0, 1) == 2);
	cout << (grid2.get_at(0, 2) == 3);
	cout << (grid2.get_at(1, 0) == 4);
	cout << (grid2.get_at(1, 1) == 5);
	cout << (grid2.get_at(1, 2) == 6);

	Grid<int>::Iterator iterator = grid2.iterator();
	while (iterator.has_next())
		cout << iterator.next() << endl;

	cin.get();
	return 0;
}
