#ifdef _grid_h

template <typename T>
Grid<T>::Grid() {
	rows = cols = 0;
	elements = NULL;
}

template <typename T>
Grid<T>::Grid(int num_rows, int num_cols) {
	resize(num_rows, num_cols);
}

template <typename T>
Grid<T>::~Grid() {
	for (int i = 0; i < rows; i++)
		delete[] elements[i];
	delete[] elements;
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
	elements = new int*[rows];
	for (int i = 0; i < rows; i++)
		elements[i] = new int[cols];
}

template <typename T>
T Grid<T>::get_at(int row, int col) {
	if (!in_bounds(row, col))
		cout << "ERROR: get_at: no element with such indeces";
	return elements[row][col];
}

template <typename T>
void Grid<T>::set_at(int row, int col, T element) {
	if (!in_bounds(row, col))
		cout << "ERROR: set_at: no element with such indeces";
	elements[row][col] = element;
}

template <typename T>
bool Grid<T>::in_bounds(int row, int col) {
	return (row >= 0 && row < rows && col >= 0 && col < cols);
}

template <typename T>
Grid<T>::Iterator::Iterator() {
	gp = NULL;
}

template <typename T>
typename Grid<T>::Iterator Grid<T>::iterator() {
	return Iterator(this);
}

template <typename T>
Grid<T>::Iterator::Iterator(Grid *gp) {
	this->gp = gp;
	row_index = col_index = 0;
}

template <typename T>
bool Grid<T>::Iterator::has_next() {
	if (gp == NULL)
		cout << "ERROR: has_next called on uninitialized iterator";
	return row_index < gp->rows;
}

template <typename T>
T Grid<T>::Iterator::next() {
	if (gp == NULL)
		cout << "ERROR: next called on uninitialized iterator";
	if (!has_next())
		cout << "ERROR: next: No more elements";
	T result = gp->get_at(row_index, col_index);
	if (++col_index == cols) {
		col_index = 0;
		row_index++;
	}
	return result;
}

#endif
