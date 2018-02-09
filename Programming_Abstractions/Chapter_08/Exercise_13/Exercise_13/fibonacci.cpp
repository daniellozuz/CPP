#include <iostream>

using namespace std;

int fibonacci(int term);
double raise_to_power(double number, int power);

int main(void) {
	for (int i = 0; i < 10; i++)
		cout << fibonacci(i) << endl;

	cin.get();
	return 0;
}

int fibonacci(int term) {
	double sqrt5 = sqrt(5);
	double golden_ratio = (sqrt5 + 1) / 2;
	return round(raise_to_power(golden_ratio, term) / sqrt5);
}

double raise_to_power(double number, int power) {
	if (power == 0)
		return 1;
	double partial_result = raise_to_power(number, power / 2);
	if (power % 2 == 0)
		return partial_result * partial_result;
	return partial_result * partial_result * number;
}
