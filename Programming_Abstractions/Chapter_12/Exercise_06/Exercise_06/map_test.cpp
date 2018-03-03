#include <iostream>
#include <exception>
#include "Map.h"

using namespace std;

const int LIMIT = 100;

int main(void) {
	Map<int> hash_map;
	for (int i = 0; i < LIMIT; i++) {
		hash_map.put(to_string(i), i);
		cout << hash_map.size() << "   ";
		cout << hash_map.get(to_string(i)) << endl;
	}

	hash_map.clear();
	cout << hash_map.size() << endl;

	for (int i = 0; i < LIMIT; i++)
		hash_map.put(to_string(i), i);

	for (int i = 0; i < LIMIT; i++) {
		hash_map.remove(to_string(i));
		cout << hash_map.size() << "   ";
	}

	cin.get();
	return 0;
}
