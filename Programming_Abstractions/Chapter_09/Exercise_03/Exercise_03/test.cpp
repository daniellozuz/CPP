#include <iostream>
#include "Rational.h"

using namespace std;

int main(void) {
	Rational number1 = Rational(1, 2);
	Rational number2 = Rational(5, -3);
	Rational number3 = Rational(-1, -2);
	Rational number = Rational(0, 1);
	
	cout << number1.to_string() << endl;
	cout << number2.to_string() << endl;
	cout << number3.to_string() << endl << endl;

	cout << number1.equals(number2) << endl;
	cout << number1.equals(number3) << endl << endl;

	cout << number1.compare_to(number3) << endl;
	cout << number1.compare_to(number2) << endl;
	cout << number2.compare_to(number1) << endl << endl;

	number = Rational(1, 2);
	number.add(number2);
	cout << number.to_string() << endl;

	number = Rational(1, 2);
	number.sub(number1);
	cout << number.to_string() << endl;

	number = Rational(1, 2);
	number.mul(number2);
	cout << number.to_string() << endl;

	number = Rational(1, 2);
	number.div(number1);
	cout << number.to_string() << endl;

	number = Rational(1, 2);
	Rational problematic_number = Rational(0, 1);
	try {
		number.div(problematic_number);
	}
	catch (invalid_argument &e) {
		cout << e.what() << endl;
	}
	cout << number.to_string() << endl;

	cin.get();
	return 0;
}
