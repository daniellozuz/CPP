#ifdef _map_h

template <typename T>
Map<T>::Map() {
}

template <typename T>
Map<T>::~Map() {
}

template <typename T>
int Map<T>::size() {
	return my_map.size();
}

template <typename T>
bool Map<T>::is_empty() {
	return my_map.empty();
}

template <typename T>
void Map<T>::clear() {
	my_map.clear();
}

template <typename T>
void Map<T>::put(string key, T value) {
	my_map[key] = value;
}

template <typename T>
T Map<T>::get(string key) {
	return my_map[key];
}

template <typename T>
bool Map<T>::contains_key(string key) {
	return my_map.find(key) != my_map.end();
}

template <typename T>
void Map<T>::remove(string key) {
	my_map.erase(key);
}

template <typename T>
T &Map<T>::operator[](string key) {
	return my_map[key];
}

template <typename T>
void Map<T>::map_all(void(*fn)(string key, T value)) {
	for (map<string, T>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		fn(it->first, it->second);
}

#endif
