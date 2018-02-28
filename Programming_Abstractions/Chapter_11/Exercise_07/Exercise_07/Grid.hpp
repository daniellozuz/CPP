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

#endif
