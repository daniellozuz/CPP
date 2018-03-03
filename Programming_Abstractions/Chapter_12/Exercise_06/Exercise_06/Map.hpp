#ifdef _map_h

template <typename T>
Map<T>::Map() {
	n_buckets = SIZE;
	n_entries = 0;
	buckets = new cell_t[n_buckets];
	for (int i = 0; i < n_buckets; i++) {
		cell_t cell;
		cell.is_occupied = false;
		buckets[i] = cell;
	}
}

template <typename T>
Map<T>::~Map() {
	delete[] buckets;
}

template <typename T>
int Map<T>::size() {
	return n_entries;
}

template <typename T>
bool Map<T>::is_empty() {
	return n_entries;
}

template <typename T>
void Map<T>::clear() {
	for (int i = 0; i < n_buckets; i++)
		buckets[i].is_occupied = false;
	n_entries = 0;
}

template <typename T>
void Map<T>::put(string key, T value) {
	if (n_entries >= SIZE)
		throw logic_error("ERROR: Attempt to set value when the map is full.");
	int i = find_bucket(key);
	if (!buckets[i].is_occupied) {
		buckets[i].key = key;
		buckets[i].is_occupied = true;
		n_entries++;
	}
	buckets[i].value = value;
}

template <typename T>
T Map<T>::get(string key) {
	int index = find_bucket(key);
	if (buckets[index].is_occupied)
		return buckets[index].value;
	throw logic_error("ERROR: Attempt to get value for key that is not in the map.");
}

template <typename T>
bool Map<T>::contains_key(string key) {
	return buckets[find_bucket(key)].is_occupied;
}

template <typename T>
void Map<T>::remove(string key) {
	int i = hash(key) % n_buckets;
	if (!buckets[i].is_occupied)
		throw logic_error("ERROR: Attempt to remove value for key that is not in the map.");
	int j = i;
	while (true) {
		buckets[j].is_occupied = false;
		int hashcode;
		do {
			j = (j + 1) % n_buckets;
			if (!buckets[j].is_occupied) {
				n_entries--;
				return;
			}
			hashcode = hash(buckets[j].key) % n_buckets;
		} while ((i <= j) ? ((i < hashcode) && (hashcode <= j)) : ((i < hashcode) || (hashcode <= j)));
		buckets[i] = buckets[j];
		i = j;
	}
	n_entries--;
}

template <typename T>
int Map<T>::hash(string s) {
	const long MULTIPLIER = -1664117991L;
	unsigned long hashcode = 0;
	for (int i = 0; i < s.length(); i++)
		hashcode = hashcode * MULTIPLIER + s[i];
	return hashcode & ((unsigned)-1 >> 1);
}

template <typename T>
int Map<T>::find_bucket(string key) {
	int index = hash(key) % n_buckets;
	while (buckets[index].is_occupied && buckets[index].key != key)
		index = (index + 1) % n_buckets;
	return index;
}

#endif
