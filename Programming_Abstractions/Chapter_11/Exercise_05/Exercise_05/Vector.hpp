#ifdef _vector_h

template <typename T>
Vector<T>::Vector() {
	capacity = INITIAL_CAPACITY;
	count = 0;
	elements = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
	delete[] elements;
}

template <typename T>
inline int Vector<T>::size() {
	return count;
}

template <typename T>
bool Vector<T>::is_empty() {
	return count == 0;
}

template <typename T>
void Vector<T>::clear() {
	delete[] elements;
	capacity = INITIAL_CAPACITY;
	count = 0;
	elements = new T[capacity];
}

template <typename T>
T Vector<T>::get_at(int index) {
	if (index < 0 || index >= count)
		cout << "ERROR: getAt: index out of range";
	return elements[index];
}

template <typename T>
void Vector<T>::set_at(int index, T element) {
	if (index < 0 || index >= count)
		cout << "ERROR: setAt: index out of range";
	elements[index] = element;
}

template <typename T>
void Vector<T>::insert_at(int index, T element) {
	if (count == capacity)
		expand_capacity();
	if (index < 0 || index > count)
		cout << "ERROR: insertAt: index out of range";
	for (int i = count; i > index; i--)
		elements[i] = elements[i - 1];
	elements[index] = element;
	count++;
}

template <typename T>
void Vector<T>::remove_at(int index) {
	if (index < 0 || index >= count)
		cout << "ERROR: removeAt: index out of range";
	for (int i = index; i < count - 1; i++)
		elements[i] = elements[i + 1];
	count--;
}

template <typename T>
void Vector<T>::add(T element) {
	insert_at(count, element);
}

template <typename T>
T &Vector<T>::operator[](int index) {
	if (index < 0 || index >= count)
		cout << "ERROR: Vector selection index out of range";
	return elements[index];
}

template <typename T>
Vector<T>::Iterator::Iterator() {
	vp = NULL;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::iterator() {
	return Iterator(this);
}

template <typename T>
Vector<T>::Iterator::Iterator(Vector *vp) {
	this->vp = vp;
	index = 0;
}

template <typename T>
bool Vector<T>::Iterator::has_next() {
	if (vp == NULL)
		Ecout << "ERROR: has_next called on uninitialized iterator";
	return index < vp->count;
}

template <typename T>
T Vector<T>::Iterator::next() {
	if (vp == NULL)
		cout << "ERROR: next called on uninitialized iterator";
	if (!has_next())
		cout << "ERROR: next: No more elements";
	return vp->get_at(index++);
}

template <typename T>
void Vector<T>::expand_capacity() {
	capacity *= 2;
	T *old_elements = elements;
	elements = new T[capacity];
	for (int i = 0; i < count; i++) {
		elements[i] = old_elements[i];
	}
	delete[] old_elements;
}

#endif
