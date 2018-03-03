#ifdef _map_h

template <typename T>
Map<T>::Map() {
	n_buckets = INITIAL_SIZE;
	buckets = new cell_t *[n_buckets];
	for (int i = 0; i < n_buckets; i++)
		buckets[i] = NULL;
}

template <typename T>
Map<T>::~Map() {
	clear();
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
		delete_chain(buckets[i]);
	n_entries = 0;
}

template <typename T>
void Map<T>::put(string key, T value) {
	int index = hash(key) % n_buckets;
	cell_t *cell = find_cell(buckets[index], key);
	if (cell == NULL) {
		cell = new cell_t;
		cell->key = key;
		cell->link = buckets[index];
		buckets[index] = cell;
		n_entries++;
	}
	cell->value = value;
	if (n_entries / n_buckets > REHASH_TRESHOLD)
		rehash();
}

template <typename T>
T Map<T>::get(string key) {
	cell_t *cell = find_cell(buckets[hash(key) % n_buckets], key);
	if (cell == NULL)
		cout << "ERROR: Attempt to get value for key that is not in the map.";
	return cell->value;
}

template <typename T>
bool Map<T>::contains_key(string key) {
	return find_cell(buckets[hash(key) % n_buckets], key) != NULL;
}

template <typename T>
void Map<T>::remove(string key) {
	int index = hash(key) % n_buckets;
	cell_t *prev = NULL;
	cell_t *cp = buckets[index];
	while (cp != NULL && cp->key != key) {
		prev = cp;
		cp = cp->link;
	}
	if (cp != NULL) {
		if (prev == NULL)
			buckets[index] = cp->link;
		else
			prev->link = cp->link;
		delete cp;
		n_entries--;
	}
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
typename Map<T>::cell_t *Map<T>::find_cell(cell_t *chain, string key) {
	for (cell_t *cp = chain; cp != NULL; cp = cp->link) {
		if (cp->key == key)
			return cp;
	}
	return NULL;
}

template <typename T>
void Map<T>::delete_chain(cell_t *chain) {
	if (chain != NULL) {
		delete_chain(chain->link);
		delete chain;
	}
}

template <typename T>
void Map<T>::rehash() {
	n_buckets *= 2;
	n_entries = 0;
	cell_t **old_buckets = buckets;
	buckets = new cell_t *[n_buckets];
	for (int i = 0; i < n_buckets; i++)
		buckets[i] = NULL;
	for (int i = 0; i < n_buckets / 2; i++) {
		for (cell_t *cp = old_buckets[i]; cp != NULL; cp = cp->link)
			put(cp->key, cp->value);
	}
	for (int i = 0; i < n_buckets / 2; i++)
		delete_chain(old_buckets[i]);
	delete[] old_buckets;
}

#endif
