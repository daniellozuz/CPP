#ifndef _map_h
#define _map_h

#include <string>

using namespace std;

template <typename T>
class Map {
public:
	Map();
	~Map();

	int size();
	bool is_empty();
	void clear();
	void put(string key, T value);
	void insert(string key, T value);
	T get(string key);
	bool contains_key(string key);
	void remove(string key);
	void display_hash_table_statistics();

private:
	static const int INITIAL_SIZE = 100;
	struct cell_t {
		string key;
		T value;
		cell_t *link;
	};
	cell_t **buckets;
	int n_buckets;
	int n_entries;
	int hash(string s);
	cell_t *find_cell(cell_t *chain, string key);
	void delete_chain(cell_t *chain);
};

#include "Map.hpp"

#endif
