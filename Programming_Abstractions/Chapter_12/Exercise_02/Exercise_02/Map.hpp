#ifdef _map_h

template <typename T>
Map<T>::Map() {
	capacity = INITIAL_CAPACITY;
	pairs = new key_value_pair_t[capacity];
	count = 0;
}

template <typename T>
Map<T>::~Map() {
	delete[] pairs;
}

template <typename T>
int Map<T>::size() {
	return count;
}

template <typename T>
bool Map<T>::is_empty() {
	return (count == 0);
}

template <typename T>
void Map<T>::clear() {
	count = 0;
}

template <typename T>
void Map<T>::put(string key, T value) {
	int index = find_key(key);
	if (index == -1) {
		if (count == capacity)
			expand_capacity();
		index = find_position_to_insert(key, 0, count);
		make_space_at(index);
		count++;
		pairs[index].key = key;
	}
	pairs[index].value = value;
}

template <typename T>
T Map<T>::get(string key) {
	int index = find_key(key);
	if (index == -1)
		cout << "ERROR: Attempt to get value for key that is not in the map.";
	return pairs[index].value;
}

template <typename T>
bool Map<T>::contains_key(string key) {
	return (find_key(key) != -1);
}

template <typename T>
void Map<T>::remove(string key) {
	int index = find_key(key);
	if (index != -1)
		pairs[index] = pairs[--count];
}

template <typename T>
int Map<T>::find_key(string key) {
	return binary_search(key, 0, count - 1); // OR not -1?
}

template <typename T>
int Map<T>::binary_search(string key, int low, int high) {
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (key == pairs[mid].key)
		return mid;
	if (key < pairs[mid].key)
		return binary_search(key, low, mid - 1);
	else
		return binary_search(key, mid + 1, high);
}

template <typename T>
int Map<T>::find_position_to_insert(string key, int low, int high) {
	if (low == high)
		return low;
	int mid = (low + high) / 2;
	if (key < pairs[mid].key)
		return find_position_to_insert(key, low, mid);
	else
		return find_position_to_insert(key, mid + 1, high);
}

template <typename T>
void Map<T>::make_space_at(int index) {
	for (int i = count; i > index; i--)
		pairs[i] = pairs[i - 1];
}

template <typename T>
void Map<T>::expand_capacity() {
	int count = size();
	capacity *= 2;
	key_value_pair_t *old_pairs = pairs;
	pairs = new key_value_pair_t[capacity];
	for (int i = 0; i < count; i++)
		pairs[i] = old_pairs[i];
	delete[] old_pairs;
}

#endif
