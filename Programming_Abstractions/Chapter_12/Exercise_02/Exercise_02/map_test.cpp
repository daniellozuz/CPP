#include <iostream>
#include "Map.h"

using namespace std;

int main(void) {
	Map<int> roman_numerals;
	roman_numerals.put("I", 1);
	roman_numerals.put("V", 5);
	roman_numerals.put("X", 10);
	roman_numerals.put("L", 50);
	roman_numerals.put("C", 100);
	roman_numerals.put("D", 500);
	roman_numerals.put("M", 1000);

	cout << roman_numerals.get("I") << endl;
	cout << roman_numerals.get("V") << endl;
	cout << roman_numerals.get("X") << endl;
	cout << roman_numerals.get("L") << endl;
	cout << roman_numerals.get("C") << endl;
	cout << roman_numerals.get("D") << endl;
	cout << roman_numerals.get("M") << endl;

	cin.get();
	return 0;
}
