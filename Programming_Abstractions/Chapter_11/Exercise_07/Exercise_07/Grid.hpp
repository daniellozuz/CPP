#ifdef _grid_h

template <typename T>
Grid<T>::Grid() {
	rows = cols = 0;
	grid = NULL;
}

template <typename T>
Grid<T>::Grid(int num_rows, int num_cols) {
	rows = num_rows;
	cols = num_cols;
	grid = new GridRow[num_rows];
	for (int i = 0; i < num_rows; i++) {
		GridRow prev_row = grid[i];
		GridRow *new_row;
		new_row = new GridRow(this);
		grid[i] = new_row;
	}
}

template <typename T>
Grid<T>::~Grid() {
	delete[] grid;
}

template <typename T>
inline int Grid<T>::num_rows() {
	return rows;
}

template <typename T>
inline int Grid<T>::num_cols() {
	return cols;
}

template <typename T>
void Grid<T>::resize(int num_rows, int num_cols) {
	if (num_rows < 1 || num_cols < 1)
		cout << "ERROR: resize: cannot create grid with such dimensions";
	rows = num_rows;
	cols = num_cols;
	grid = new GridRow[rows];
}

template <typename T>
T Grid<T>::get_at(int row, int col) {
	if (!in_bounds(row, col))
		cout << "ERROR: get_at: no element with such indeces";
	return grid[row][col];
}

template <typename T>
void Grid<T>::set_at(int row, int col, T element) {
	if (!in_bounds(row, col))
		cout << "ERROR: set_at: no element with such indeces";
	grid[row].set_at(col, element);
}

template <typename T>
void Grid<T>::GridRow::set_at(int col, T element) {
	elements[col] = element;
}

template <typename T>
bool Grid<T>::in_bounds(int row, int col) {
	return (row >= 0 && row < rows && col >= 0 && col < cols);
}

template <typename T>
Grid<T>::Iterator::Iterator() {
	vp = NULL;
}

template <typename T>
typename Grid<T>::Iterator Grid<T>::iterator() {
	return Iterator(this);
}

template <typename T>
Grid<T>::Iterator::Iterator(Grid *vp) {
	this->vp = vp;
	index = 0;
}

template <typename T>
bool Grid<T>::Iterator::has_next() {
	if (vp == NULL)
		cout << "ERROR: has_next called on uninitialized iterator";
	return index < vp->size();
}

template <typename T>
T Grid<T>::Iterator::next() {
	if (vp == NULL)
		cout << "ERROR: next called on uninitialized iterator";
	if (!has_next())
		cout << "ERROR: next: No more elements";
	return vp->get_at(index++);
}

template <typename T>
Grid<T>::GridRow::GridRow() {
}

template <typename T>
Grid<T>::GridRow::GridRow(Grid *gp) {
	if (gp->rows < 1)
		cout << "ERROR: GridRow: cannot create row smaller than one element";
	*elements = new T[gp->rows];
}

#endif
