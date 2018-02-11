#ifndef _rational_h
#define _rational_h

#include <string>

using namespace std;

class Rational
{
public:
	Rational(long int num, long int den);
	~Rational();
	void add(Rational r);
	void sub(Rational r);
	void mul(Rational r);
	void div(Rational r);
	bool equals(Rational r);
	int compare_to(Rational r);
	string to_string();

private:
	long int num, den;
	void reduce();
	long int gcd(long int a, long int b);
};

#endif
