#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> NUMERALS = { { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };

int roman_to_arabic(string roman);

int main(void) {
	cout << roman_to_arabic("MCMLXIX") << endl;
	cout << roman_to_arabic("I") << endl;

	cin.get();
	return 0;
}

int roman_to_arabic(string roman) {
	int arabic = 0;
	for (int i = 0; i < roman.length() - 1; i++) {
		if (NUMERALS[roman[i + 1]] > NUMERALS[roman[i]])
			arabic -= NUMERALS[roman[i]];
		else
			arabic += NUMERALS[roman[i]];
	}
	arabic += NUMERALS[roman[roman.length() - 1]];
	return arabic;
}
