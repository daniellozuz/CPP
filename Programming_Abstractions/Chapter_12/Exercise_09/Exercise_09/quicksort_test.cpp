#include <iostream>
#include "Quicksort.h"

using namespace std;

const int SIZE = 9;

int operator_cmp(double one, double two);

int main(void) {
	double vec[SIZE] = { 1.1, 6.0, 2.0, 4.0, 8.0, 3.0, 7.0, 9.0, 5.0 };

	Quicksort<double> quick;
	quick.sort(vec, SIZE, operator_cmp);

	for (int i = 0; i < SIZE; i++)
		cout << vec[i] << endl;

	cin.get();
	return 0;
}

int operator_cmp(double one, double two) {
	if (one == two)
		return 0;
	if (one < two)
		return -1;
	return 1;
}
