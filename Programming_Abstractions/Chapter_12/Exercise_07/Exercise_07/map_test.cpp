#include <iostream>
#include "Map.h"

using namespace std;

const int LIMIT = 50;

int main(void) {
	Map<int> hash_map;

	for (int i = 0; i < LIMIT; i++) {
		hash_map.put(to_string(i), i);
		cout << hash_map.get(to_string(i)) << endl;
	}

	Map<int>::Iterator iterator = hash_map.iterator();
	while (iterator.has_next())
		cout << "Key: " << iterator.next() << endl;

	cout << hash_map["2"] << endl;
	hash_map["2"] = 7;
	cout << hash_map["2"] << endl;

	cin.get();
	return 0;
}
