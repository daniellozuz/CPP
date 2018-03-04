#ifndef _map_h
#define _map_h

#include <string>
#include <exception>

using namespace std;

template <typename key_T, typename value_T>
class Map {
public:
	Map(int(*cmp)(key_T, key_T), int(*hash)(key_T));
	~Map();

	struct cell_t {
		key_T key;
		value_T value;
		cell_t *link;
	};

	int size();
	bool is_empty();
	void clear();
	void put(key_T key, value_T value);
	value_T get(key_T key);
	bool contains_key(key_T key);
	void remove(key_T key);
	value_T &operator[](key_T key);
	void copy_entries_into(Map &target);
	void map_all(void(*fn)(key_T key, value_T value));
	void map_all(void(*fn)(key_T key, value_T value, key_T &client_data), key_T &client_data);

	class Iterator {
	public:
		Iterator();
		bool has_next();
		key_T next();
	private:
		Map *mp;
		int bucket;
		cell_t *cell;
		Iterator(Map *mp);
		friend class Map;
	};
	friend class Iterator;

	Iterator iterator();

private:
	static const int INITIAL_SIZE = 100;
	cell_t **buckets;
	int n_buckets;
	int n_entries;
	int(*hash)(key_T s);
	int(*cmp)(key_T one, key_T two);
	cell_t *find_cell(cell_t *chain, key_T key);
	void delete_chain(cell_t *chain);
};

#include "Map.hpp"

#endif
