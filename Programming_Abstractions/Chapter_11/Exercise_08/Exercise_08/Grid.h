#ifndef _grid_h
#define _grid_h

template <typename T>
class Grid {
public:
	class GridRow;
	class Iterator;

	Grid();
	Grid(int num_rows, int num_cols);
	~Grid();

	int num_rows();
	int num_cols();
	void resize(int num_rows, int num_cols);
	T get_at(int row, int col);
	void set_at(int row, int col, T value);
	bool in_bounds(int row, int col);

	class Iterator {
	public:
		Iterator();
		bool has_next();
		T next();
	private:
		int timestamp;
		Grid *gp;
		int row_index, col_index;
		Iterator(Grid *gp);
		friend class Grid;
	};
	friend class Iterator;

	Iterator iterator();

private:
	int rows;
	int cols;
	int timestamp;
	T **elements;
};

#include "Grid.hpp"

#endif
