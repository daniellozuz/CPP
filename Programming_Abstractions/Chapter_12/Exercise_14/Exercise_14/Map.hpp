#ifdef _map_h

template <typename key_T, typename value_T>
Map<key_T, value_T>::Map(int(*cmp)(key_T, key_T), int(*hash)(key_T)) {
	n_buckets = INITIAL_SIZE;
	buckets = new cell_t *[n_buckets];
	for (int i = 0; i < n_buckets; i++)
		buckets[i] = NULL;
	this->hash = hash;
	this->cmp = cmp;
}

template <typename key_T, typename value_T>
Map<key_T, value_T>::~Map() {
	clear();
	delete[] buckets;
}

template <typename key_T, typename value_T>
int Map<key_T, value_T>::size() {
	return n_entries;
}

template <typename key_T, typename value_T>
bool Map<key_T, value_T>::is_empty() {
	return n_entries;
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::clear() {
	for (int i = 0; i < n_buckets; i++)
		delete_chain(buckets[i]);
	n_entries = 0;
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::put(key_T key, value_T value) {
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
}

template <typename key_T, typename value_T>
value_T Map<key_T, value_T>::get(key_T key) {
	cell_t *cell = find_cell(buckets[hash(key) % n_buckets], key);
	if (cell == NULL)
		throw logic_error("ERROR: Attempt to get value for key that is not in the map.");
	return cell->value;
}

template <typename key_T, typename value_T>
bool Map<key_T, value_T>::contains_key(key_T key) {
	return find_cell(buckets[hash(key) % n_buckets], key) != NULL;
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::remove(key_T key) {
	int index = hash(key) % n_buckets;
	cell_t *prev = NULL;
	cell_t *cp = buckets[index];
	while (cp != NULL && cmp(cp->key, key) != 0) {
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

template <typename key_T, typename value_T>
typename Map<key_T, value_T>::cell_t *Map<key_T, value_T>::find_cell(cell_t *chain, key_T key) {
	for (cell_t *cp = chain; cp != NULL; cp = cp->link) {
		if (cmp(cp->key, key) == 0)
			return cp;
	}
	return NULL;
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::delete_chain(cell_t *chain) {
	if (chain != NULL) {
		delete_chain(chain->link);
		delete chain;
	}
}

template <typename key_T, typename value_T>
Map<key_T, value_T>::Iterator::Iterator() {
	mp = NULL;
}

template <typename key_T, typename value_T>
typename Map<key_T, value_T>::Iterator Map<key_T, value_T>::iterator() {
	return Iterator(this);
}

template <typename key_T, typename value_T>
Map<key_T, value_T>::Iterator::Iterator(Map *mp) {
	this->mp = mp;
	bucket = 0;
	cell = mp->buckets[0];
}

template <typename key_T, typename value_T>
bool Map<key_T, value_T>::Iterator::has_next() {
	if (mp == NULL)
		throw logic_error("ERROR: has_next called on uninitialized iterator");
	if (cell != NULL && cell->link != NULL)
		return true;
	for (int i = bucket + 1; i < mp->n_buckets; i++) {
		if (mp->buckets[i] != NULL)
			return true;
	}
	return false;
}

template <typename key_T, typename value_T>
key_T Map<key_T, value_T>::Iterator::next() {
	if (mp == NULL)
		throw logic_error("ERROR: next called on uninitialized iterator");
	if (!has_next())
		throw logic_error("ERROR: next: No more elements");
	if (cell == NULL || cell->link == NULL) {
		for (int i = bucket + 1; i < mp->n_buckets; i++) {
			if (mp->buckets[i] != NULL) {
				cell = mp->buckets[i];
				key_T result = cell->key;
				bucket = i;
				return result;
			}
		}
	}
	else {
		key_T result = cell->link->key;
		cell = cell->link;
		return result;
	}
}

template <typename key_T, typename value_T>
value_T &Map<key_T, value_T>::operator[](key_T key) {
	cell_t *cell = find_cell(buckets[hash(key) % n_buckets], key);
	if (cell == NULL)
		throw logic_error("ERROR: Attempt to [] value for key that is not in the map.");
	return cell->value;
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::copy_entries_into(Map &target) {
	Iterator it = iterator();
	while (it.has_next()) {
		key_T key = it.next();
		target.put(key, get(key));
	}
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::map_all(void(*fn)(key_T key, value_T value)) {
	Iterator it = iterator();
	while (it.has_next()) {
		key_T next_key = it.next();
		fn(next_key, get(next_key));
	}
}

template <typename key_T, typename value_T>
void Map<key_T, value_T>::map_all(void(*fn)(key_T key, value_T value, key_T &client_data), key_T &client_data) {
	Iterator it = iterator();
	while (it.has_next()) {
		key_T next_key = it.next();
		fn(next_key, get(next_key), client_data);
	}
}

#endif
