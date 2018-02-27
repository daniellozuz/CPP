#include <iostream>
#include "Vector.h"

using namespace std;

int main(void) {
	Vector<int> vec;

	cout << (vec.is_empty() == 1);

	for (int i = 0; i < 10; i++) {
		vec.add(i);
		cout << (vec.size() == i + 1);
		cout << (vec.is_empty() == 0);
		cout << (vec.get_at(i) == i);
	}

	vec.set_at(2, 99);
	cout << (vec.get_at(2) == 99);

	cout << (vec.get_at(5) == 5);
	vec.insert_at(5, -2);
	cout << (vec.get_at(5) == -2);
	vec.remove_at(5);
	cout << (vec.get_at(5) == 5);

	vec.clear();
	cout << (vec.is_empty() == 1);
	cout << (vec.size() == 0);

	cin.get();
	return 0;
}
