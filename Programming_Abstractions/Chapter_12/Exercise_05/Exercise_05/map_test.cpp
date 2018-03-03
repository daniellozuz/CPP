#include <iostream>
#include <cmath>
#include "Map.h"

using namespace std;

const int LIMIT = 20000;

int main(void) {
	Map<int> hash_map;

	for (int i = 0; i < LIMIT; i++)
		hash_map.put(to_string(i), i);

	cin.get();
	return 0;
}
