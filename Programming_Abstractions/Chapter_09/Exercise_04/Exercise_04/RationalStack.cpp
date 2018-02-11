#include "RationalStack.h"
#include <vector>

using namespace std;

RationalStack::RationalStack() {
}

RationalStack::~RationalStack() {
}

int RationalStack::size() {
	return vec.size();
}

bool RationalStack::is_empty() {
	return vec.empty();
}

void RationalStack::clear() {
	vec.clear();
}

void RationalStack::push(Rational element) {
	vec.push_back(element);
}

Rational RationalStack::pop() {
	Rational element = vec.back();
	vec.pop_back();
	return element;
}

Rational RationalStack::peek() {
	return vec.back();
}