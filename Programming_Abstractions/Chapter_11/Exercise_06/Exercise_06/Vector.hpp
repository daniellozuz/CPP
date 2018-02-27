#ifdef _vector_h

template <typename T>
Vector<T>::Vector() {
	capacity = INITIAL_CAPACITY;
	elements = new T[capacity];
	before = 0;
	after = capacity;
}

template <typename T>
Vector<T>::~Vector() {
	delete[] elements;
}

template <typename T>
inline int Vector<T>::size() {
	return before + capacity - after;
}

template <typename T>
bool Vector<T>::is_empty() {
	return (size() == 0);
}

template <typename T>
void Vector<T>::clear() {
	before = 0;
	after = capacity;
}

template <typename T>
T Vector<T>::get_at(int index) {
	if (index < 0 || index >= size())
		cout << "ERROR: getAt: index out of range";
	move_to(index);
	return elements[after];
}

template <typename T>
void Vector<T>::set_at(int index, T element) {
	if (index < 0 || index >= size())
		cout << "ERROR: setAt: index out of range";
	move_to(index);
	elements[after] = element;
}

template <typename T>
void Vector<T>::insert_at(int index, T element) {
	if (index < 0 || index > size())
		cout << "ERROR: insertAt: index out of range";
	if (size() == capacity)
		expand_capacity();
	move_to(index);
	elements[before++] = element;
}

template <typename T>
void Vector<T>::remove_at(int index) {
	if (index < 0 || index >= size())
		cout << "ERROR: removeAt: index out of range";
	move_to(index);
	after++;
}

template <typename T>
void Vector<T>::add(T element) {
	insert_at(size(), element);
}

template <typename T>
T &Vector<T>::operator[](int index) {
	if (index < 0 || index >= size())
		cout << "ERROR: Vector selection index out of range";
	move_to(index);
	return elements[after];
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
		cout << "ERROR: has_next called on uninitialized iterator";
	return index < vp->size();
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
	T *prev_elements = elements;
	T *elements = new T[2 * capacity];
	for (int i = 0; i < before; i++)
		elements[i] = prev_elements[i];
	for (int i = after; i < capacity; i++)
		elements[capacity + i] = prev_elements[i];
	after += capacity;
	capacity *= 2;
	delete[] prev_elements;
}

template <typename T>
void Vector<T>::move_to(int index) {
	while (index != before) {
		if (index > before)
			move_left();
		else
			move_right();
	}
}

template <typename T>
void Vector<T>::move_right() {
	elements[--after] = elements[--before];
}

template <typename T>
void Vector<T>::move_left() {
	elements[before++] = elements[after++];
}

#endif
