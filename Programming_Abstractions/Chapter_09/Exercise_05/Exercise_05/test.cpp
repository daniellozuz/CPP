#include <iostream>
#include "LabelGenerator.h"

using namespace std;

int main() {
	LabelGenerator figure_numbers("Figure", 1);
	LabelGenerator point_numbers("P", 0);

	cout << "Figure numbers: ";
	for (int i = 0; i < 3; i++) {
		if (i > 0) cout << ", ";
		cout << figure_numbers.next_label();
	}

	cout << endl << "Point numbers: ";
	for (int i = 0; i < 5; i++) {
		if (i > 0) cout << ", ";
		cout << point_numbers.next_label();
	}

	cout << endl << "More figures: ";
	for (int i = 0; i < 3; i++) {
		if (i > 0) cout << ", ";
		cout << figure_numbers.next_label();
	}

	cin.get();
	return 0;
}