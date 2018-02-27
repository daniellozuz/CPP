#ifdef _stack_h

template <typename element_t>
Stack<element_t>::Stack() {
	list = NULL;
	count = 0;
	length = 0;
}

template <typename element_t>
Stack<element_t>::~Stack() {
	clear();
}

template <typename element_t>
int Stack<element_t>::size() {
	return count;
}

template <typename element_t>
bool Stack<element_t>::is_empty() {
	return count == 0;
}

template <typename element_t>
void Stack<element_t>::clear() {
	while (count > 0)
		pop();
}

template <typename element_t>
void Stack<element_t>::push(element_t element) {
	if (length > 0 && length < BLOCK_SIZE) {
		list->data[length] = element;
		length++;
		count++;
	}
	else {
		cell_t *cell = new cell_t;
		cell->data[0] = element;
		cell->link = list;
		list = cell;
		length = 1;
		count++;
	}
}

template <typename element_t>
element_t Stack<element_t>::pop() {
	if (is_empty())
		cout << "ERROR! pop: Attempting to pop an empty stack" << endl;
	if (length == 1) {
		cell_t *cell = list;
		element_t result = cell->data[0];
		list = list->link;
		length = BLOCK_SIZE;
		count--;
		delete cell;
		return result;
	}
	else {
		cell_t *cell = list;
		element_t result = cell->data[length - 1];
		length--;
		count--;
		return result;
	}
}

template <typename element_t>
element_t Stack<element_t>::peek() {
	if (is_empty())
		cout << "ERROR! peek: Attempting to peek at an empty stack" << endl;
	return list->data[length - 1];
}

#endif
