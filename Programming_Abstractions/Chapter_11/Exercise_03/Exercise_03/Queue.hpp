#ifdef _queue_h

template <typename T>
Queue<T>::Queue() {
	capacity = INITIAL_CAPACITY;
	elements = new T[capacity];
	head = 0;
	count = 0;
}

template <typename T>
Queue<T>::~Queue() {
	delete[] elements;
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
	head = count = 0;
}

template <typename T>
void Queue<T>::enqueue(T elem) {
	if (count == capacity)
		expand_capacity();
	elements[(head + count) % capacity] = elem;
	count++;
}

template <typename T>
T Queue<T>::dequeue() {
	if (is_empty())
		cout << "ERROR: dequeue: Attempting to dequeue an empty queue" << endl;
	T result = elements[head];
	head = (head + 1) % capacity;
	count--;
	return result;
}

template <typename T>
T Queue<T>::peek() {
	if (is_empty())
		cout << "ERROR: peek: Attempting to peek at an empty queue" << endl;
	return elements[head];
}

template <typename T>
void Queue<T>::reverse() {
	for (int i = 0; i < count / 2; i++) {
		T tmp = elements[(head + i) % capacity];
		elements[(head + i) % capacity] = elements[(head + count - 1 - i) % capacity];
		elements[(head + count - 1 - i) % capacity] = tmp;
	}
}

template <typename T>
void Queue<T>::expand_capacity() {
	capacity *= 2;
	T *old_elements = elements;
	elements = new T[capacity];
	for (int i = 0; i < count; i++)
		elements[i] = old_elements[(head + i) % capacity];
	head = 0;
	delete[] old_elements;
}

#endif
