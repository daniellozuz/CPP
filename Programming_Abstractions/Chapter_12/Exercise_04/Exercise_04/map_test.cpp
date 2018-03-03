#include <iostream>
#include "Map.h"

using namespace std;

int main(void) {
	Map<int> hash_map;

	hash_map.put("1", 1);
	hash_map.put("2", 2);
	hash_map.put("1", 3);					// "1" overwritten.
	hash_map.insert("2", 4);				// Another "2" added (it hides previous "2" until removed).

	hash_map.remove("1");					// No "1" anymore. 'hash_map.get("1");' Results in an error.

	cout << hash_map.get("2") << endl;		// Returns 4.
	hash_map.remove("2");					// Previous "2" unveiled.
	cout << hash_map.get("2") << endl;		// Returns 2.

	cin.get();
	return 0;
}
