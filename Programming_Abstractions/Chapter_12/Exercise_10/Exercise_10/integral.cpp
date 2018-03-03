#include <iostream>
#include <cmath>

using namespace std;

double integrate(double(*fn)(double), double start, double end, int precision);

int main(void) {
	cout << integrate(sin, 0, 3.1415926, 18) << endl;

	cin.get();
	return 0;
}

double integrate(double(*fn)(double), double start, double end, int precision) {
	double area = 0.0;
	double width = (end - start) / precision;
	for (int i = 0; i < precision; i++)
		area += width * fn(start + i * width + width / 2);
	return area;
}
