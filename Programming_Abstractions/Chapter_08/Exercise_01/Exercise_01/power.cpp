#include <iostream>

using namespace std;

double raise_to_power(double number, int power);

int main(void) {
	cout << raise_to_power(3.0, 3) << endl;
	cout << raise_to_power(2.0, 10) << endl;

	cin.get();
	return 0;
}

double raise_to_power(double number, int power) {
	if (power == 0)
		return 1;
	double partial_result = raise_to_power(number, power / 2);
	if (power % 2 == 0)
		return partial_result * partial_result;
	return partial_result * partial_result * number;
}
