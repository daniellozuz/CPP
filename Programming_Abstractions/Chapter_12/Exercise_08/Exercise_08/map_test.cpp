#include <iostream>
#include "Map.h"

using namespace std;

const int LIMIT = 50;

int main(void) {
	Map<int> hash_map1, hash_map2;

	for (int i = 0; i < LIMIT; i++)
		hash_map1.put(to_string(i), i);

	hash_map1.copy_entries_into(hash_map2);

	for (int i = 0; i < LIMIT; i++)
		cout << hash_map2.get(to_string(i)) << endl;

	cin.get();
	return 0;
}
