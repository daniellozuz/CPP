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

	/*
	void map_all(void(*fn)(T elem));
	template <typename ClientDataType>
	void map_all(void(*fn)(T elem, ClientDataType & data), ClientDataType & data);
	*/

	class Iterator {
	public:
		Iterator();
		bool has_next();
		T next();
	private:
		Grid *gp;
		int index;
		Iterator(Grid *gp);
		friend class Grid;
	};
	friend class Iterator;

	Iterator iterator();

	class GridRow {
	public:
		GridRow();
	private:
		Grid *gp;
		T *elements;
		GridRow(Grid *gp);
		void set_at(int col, T value);
		friend class Grid;
	};
	friend class GridRow;

private:
	int rows;
	int cols;
	GridRow *grid;
};

#include "Grid.hpp"

#endif
