#ifndef _map_h
#define _map_h

#include <string>
#include <map>

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
	T &operator[](string key);
	void map_all(void (*fn)(string key, T value));

private:
	map<string, T> my_map;
};

#include "Map.hpp"

#endif