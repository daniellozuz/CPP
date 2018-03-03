#ifndef _map_h
#define _map_h

#include <string>
#include <exception>

using namespace std;

template <typename T>
class Map {
public:
	Map();
	~Map();

	struct cell_t {
		string key;
		T value;
		cell_t *link;
	};

	int size();
	bool is_empty();
	void clear();
	void put(string key, T value);
	T get(string key);
	bool contains_key(string key);
	void remove(string key);
	T &operator[](string key);
	void copy_entries_into(Map &target);

	class Iterator {
	public:
		Iterator();
		bool has_next();
		string next();
	private:
		Map * mp;
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
	int hash(string s);
	cell_t *find_cell(cell_t *chain, string key);
	void delete_chain(cell_t *chain);
};

#include "Map.hpp"

#endif
