#ifdef _queue_h

template <typename T>
Queue<T>::Queue() {
	capacity = INITIAL_CAPACITY;
	elements = new T[capacity];
	head = 0;
	tail = 0;
}

template <typename T>
Queue<T>::~Queue() {
	delete[] elements;
}

template <typename T>
int Queue<T>::size() {
	return (tail + capacity - head) % capacity;
}

template <typename T>
bool Queue<T>::is_empty() {
	return (head == tail);
}

template <typename T>
void Queue<T>::clear() {
	head = tail = 0;
}

template <typename T>
void Queue<T>::enqueue(T elem) {
	if (size() == capacity - 1)
		expand_capacity();
	elements[tail] = elem;
	tail = (tail + 1) % capacity;
}

template <typename T>
T Queue<T>::dequeue() {
	if (is_empty())
		cout << "ERROR: dequeue: Attempting to dequeue an empty queue" << endl;
	T result = elements[head];
	head = (head + 1) % capacity;
	return result;
}

template <typename T>
T Queue<T>::peek() {
	if (is_empty())
		cout << "ERROR: peek: Attempting to peek at an empty queue" << endl;
	return elements[head];
}

template <typename T>
void Queue<T>::expand_capacity() {
	int count = size();
	capacity *= 2;
	T *old_elements = elements;
	elements = new T[capacity];
	for (int i = 0; i < count; i++)
		elements[i] = old_elements[(head + i) % capacity];
	head = 0;
	tail = count;
	delete[] old_elements;
}

#endif
