#ifdef _vector_h

template <typename T>
Vector<T>::Vector() {
	head = NULL;
	count = 0;
}

template <typename T>
Vector<T>::~Vector() {
	clear();
}

template <typename T>
inline int Vector<T>::size() {
	return count;
}

template <typename T>
bool Vector<T>::is_empty() {
	return (count == 0);
}

template <typename T>
void Vector<T>::clear() {
	while (count > 0)
		remove_at(0);
}

template <typename T>
T Vector<T>::get_at(int index) {
	if (index < 0 || index >= count)
		cout << "ERROR: getAt: index out of range";
	cell_t *cursor = head;
	for (int i = 0; i < index; i++)
		cursor = cursor->next;
	return cursor->element;
}

template <typename T>
void Vector<T>::set_at(int index, T element) {
	if (index < 0 || index >= count)
		cout << "ERROR: setAt: index out of range";
	cell_t *cursor = head;
	for (int i = 0; i < index; i++)
		cursor = cursor->next;
	cursor->element = element;
}

template <typename T>
void Vector<T>::insert_at(int index, T element) {
	if (index < 0 || index > count)
		cout << "ERROR: insertAt: index out of range";
	cell_t *new_cell = new cell_t;
	new_cell->element = element;
	if (index == 0) {
		new_cell->next = head;
		head = new_cell;
	}
	else {
		cell_t *cursor = head;
		for (int i = 0; i < index - 1; i++)
			cursor = cursor->next;
		new_cell->next = cursor->next;
		cursor->next = new_cell;
	}
	count++;
}

template <typename T>
void Vector<T>::remove_at(int index) {
	if (index < 0 || index >= count)
		cout << "ERROR: removeAt: index out of range";
	if (index == 0) {
		cell_t *old_cell = head;
		head = head->next;
		delete old_cell;
	}
	else {
		cell_t *cursor = head;
		for (int i = 0; i < index - 1; i++)
			cursor = cursor->next;
		cell_t *old_cell = cursor->next;
		cursor->next = old_cell->next;
		delete old_cell;
	}
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
	cell_t *cursor = head;
	for (int i = 0; i < index; i++)
		cursor = cursor->next;
	return cursor->element;
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

#endif
