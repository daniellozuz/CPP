#include <iostream>
#include "Map.h"

using namespace std;

const int LIMIT = 50;

int compare_function(string one, string two);
int hash_function(string key);
void show_key_value_pair(string key, int value);
void find_longest_key(string key, int value, string &result);
string longest_key(Map<string, int> &hash_map);

int main(void) {
	Map<string, int> hash_map(compare_function, hash_function);

	for (int i = 0; i < LIMIT; i++) {
		hash_map.put(to_string(i), i);
		cout << hash_map.get(to_string(i)) << endl;
	}

	Map<string, int>::Iterator iterator = hash_map.iterator();
	while (iterator.has_next())
		cout << "Key: " << iterator.next() << endl;

	cout << hash_map["2"] << endl;
	hash_map["2"] = 7;
	cout << hash_map["2"] << endl;

	Map<string, int> hash_map1(compare_function, hash_function);
	Map<string, int> hash_map2(compare_function, hash_function);

	for (int i = 0; i < LIMIT; i++)
		hash_map1.put(to_string(i), i);

	hash_map1.copy_entries_into(hash_map2);

	for (int i = 0; i < LIMIT; i++)
		cout << hash_map2.get(to_string(i)) << endl;

	hash_map1.put(to_string(100), 100);
	cout << hash_map1.get(to_string(100)) << endl;

	hash_map1.map_all(show_key_value_pair);

	cout << longest_key(hash_map1) << endl;

	cin.get();
	return 0;
}

int compare_function(string one, string two) {
	if (one == two)
		return 0;
	if (one < two)
		return -1;
	return 1;
}

int hash_function(string key) {
	const long MULTIPLIER = -1664117991L;
	unsigned long hashcode = 0;
	for (int i = 0; i < key.length(); i++)
		hashcode = hashcode * MULTIPLIER + key[i];
	return int(hashcode & (unsigned(-1) >> 1));
}

void show_key_value_pair(string key, int value) {
	cout << "Key: " << key << " Value: " << value << endl;
}

void find_longest_key(string key, int value, string &result) {
	if (key.length() > result.length())
		result = key;
}

string longest_key(Map<string, int> &hash_map) {
	string result = "";
	hash_map.map_all(find_longest_key, result);
	return result;
}