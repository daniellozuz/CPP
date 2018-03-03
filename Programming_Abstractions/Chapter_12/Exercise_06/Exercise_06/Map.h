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
	T get(string key);
	bool contains_key(string key);
	void remove(string key);

private:
	static const int SIZE = 100;
	struct cell_t {
		string key;
		T value;
		bool is_occupied;
	};
	cell_t *buckets;
	int n_buckets;
	int n_entries;
	int hash(string s);
	int find_bucket(string key);
};

#include "Map.hpp"

#endif
