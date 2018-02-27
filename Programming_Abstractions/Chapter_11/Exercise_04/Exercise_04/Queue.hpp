#ifdef _queue_h

template <typename T>
Queue<T>::Queue() {
	head = tail = NULL;
	count = 0;
}

template <typename T>
Queue<T>::~Queue() {
	clear();
}

template <typename T>
int Queue<T>::size() {
	return count;
}

template <typename T>
bool Queue<T>::is_empty() {
	return (count == 0);
}

template <typename T>
void Queue<T>::clear() {
	while (count > 0)
		dequeue();
}

template <typename T>
void Queue<T>::enqueue(T elem) {
	cell_t *new_cell = new cell_t;
	new_cell->element = elem;
	new_cell->next = NULL;
	if (count == 0)
		head = new_cell;
	else
		tail->next = new_cell;
	tail = new_cell;
	count++;
}

template <typename T>
T Queue<T>::dequeue() {
	if (is_empty())
		cout << "ERROR: dequeue: Attempting to dequeue an empty queue" << endl;
	T result = head->element;
	cell_t *old_cell = head;
	head = head->next;
	delete old_cell;
	count--;
	return result;
}

template <typename T>
T Queue<T>::peek() {
	if (is_empty())
		cout << "ERROR: peek: Attempting to peek at an empty queue" << endl;
	return head->element;
}

template <typename T>
void Queue<T>::reverse() {
	cell_t *cursor1 = head;
	for (int i = 0; i < count / 2; i++) {
		cell_t *cursor2 = cursor1;
		for (int j = 0; j < count - 1 - 2 * i; j++)
			cursor2 = cursor2->next;
		T tmp = cursor1->element;
		cursor1->element = cursor2->element;
		cursor2->element = tmp;
		cursor1 = cursor1->next;
	}
}

#endif
