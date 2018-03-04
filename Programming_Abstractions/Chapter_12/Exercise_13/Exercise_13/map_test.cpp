#include <iostream>
#include "Map.h"

using namespace std;

const int LIMIT = 50;

int compare_function(int one, int two);
int hash_function(int key);

int main(void) {
	Map<int, string> hash_map(compare_function, hash_function);

	for (int i = 0; i < LIMIT; i++) {
		hash_map.put(i, to_string(i));
		cout << hash_map.get(i) << endl;
	}

	Map<int, string>::Iterator iterator = hash_map.iterator();
	while (iterator.has_next())
		cout << "Key: " << iterator.next() << endl;

	cout << hash_map[2] << endl;
	hash_map[2] = "7";
	cout << hash_map[2] << endl;

	Map<int, string> hash_map1(compare_function, hash_function);
	Map<int, string> hash_map2(compare_function, hash_function);

	for (int i = 0; i < LIMIT; i++)
		hash_map1.put(i, to_string(i));

	hash_map1.copy_entries_into(hash_map2);

	for (int i = 0; i < LIMIT; i++)
		cout << hash_map2.get(i) << endl;

	cin.get();
	return 0;
}

int compare_function(int one, int two) {
	if (one == two)
		return 0;
	if (one < two)
		return -1;
	return 1;
}

int hash_function(int key) {
	return key + 1;
}
