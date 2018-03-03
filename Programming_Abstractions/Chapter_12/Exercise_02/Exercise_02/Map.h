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
	struct key_value_pair_t {
		string key;
		T value;
	};

	static const int INITIAL_CAPACITY = 100;
	key_value_pair_t *pairs;
	int capacity;
	int count;

	int find_key(string key);
	void expand_capacity();
	int binary_search(string key, int low, int high);
	int find_position_to_insert(string key, int low, int high);
	void make_space_at(int index);
};

#include "Map.hpp"

#endif
