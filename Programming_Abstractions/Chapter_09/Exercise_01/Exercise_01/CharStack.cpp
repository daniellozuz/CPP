#include "CharStack.h"
#include <vector>

using namespace std;

CharStack::CharStack() {
}

CharStack::~CharStack() {
}

int CharStack::size() {
	return vec.size();
}

bool CharStack::is_empty() {
	return vec.empty();
}

void CharStack::clear() {
	vec.clear();
}

void CharStack::push(char element) {
	vec.push_back(element);
}

char CharStack::pop() {
	char element = vec.back();
	vec.pop_back();
	return element;
}

char CharStack::peek() {
	return vec.back();
}
