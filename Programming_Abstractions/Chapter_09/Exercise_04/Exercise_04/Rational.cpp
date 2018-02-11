#include "Rational.h"
#include <iostream>

Rational::Rational(long int num, long int den) {
	this->num = num;
	this->den = den;
	reduce();
}

Rational::~Rational() {
}

void Rational::reduce() {
	int sign, numerator, denominator, common;
	if ((this->num > 0 && this->den > 0) || (this->num < 0 && this->den < 0))
		sign = 1;
	else
		sign = -1;
	numerator = abs(this->num);
	denominator = abs(this->den);
	common = gcd(numerator, denominator);
	this->num = sign * numerator / common;
	this->den = denominator / common;
}

long int Rational::gcd(long int a, long int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void Rational::add(Rational r) {
	this->num = this->num * r.den + this->den * r.num;
	this->den *= r.den;
	reduce();
}

void Rational::sub(Rational r) {
	this->num = this->num * r.den - this->den * r.num;
	this->den *= r.den;
	reduce();
}

void Rational::mul(Rational r) {
	this->num *= r.num;
	this->den *= r.den;
	reduce();
}

void Rational::div(Rational r) {
	if (r.num == 0)
		throw std::invalid_argument("Division by zero!");
	this->num *= r.den;
	this->den *= r.num;
	reduce();
}

bool Rational::equals(Rational r) {
	return (this->num == r.num && this->den == r.den);
}

int Rational::compare_to(Rational r) {
	Rational temp1(this->num, this->den);
	temp1.num *= r.den;
	temp1.den *= r.den;
	Rational temp2(r.num, r.den);
	temp2.num *= this->den;
	temp2.den *= this->den;
	if (temp1.num > temp2.num)
		return 1;
	else if (temp1.num == temp2.num)
		return 0;
	else
		return -1;
}

string Rational::to_string() {
	if (this->den == 1)
		return std::to_string(this->num);
	else
		return std::to_string(this->num) + "/" + std::to_string(this->den);
}
