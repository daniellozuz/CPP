#include "NumStack.h"
#include <vector>

using namespace std;

NumStack::NumStack() {
}

NumStack::~NumStack() {
}

int NumStack::size() {
	return vec.size();
}

bool NumStack::is_empty() {
	return vec.empty();
}

void NumStack::clear() {
	vec.clear();
}

void NumStack::push(double element) {
	vec.push_back(element);
}

double NumStack::pop() {
	double element = vec.back();
	vec.pop_back();
	return element;
}

double NumStack::peek() {
	return vec.back();
}
