#ifndef _stach_h
#define _stack_h

#include <iostream>

using namespace std;

const int BLOCK_SIZE = 4;

template <typename element_t>
class Stack {
public:
	Stack();
	~Stack();
	int size();
	bool is_empty();
	void clear();
	void push(element_t element);
	element_t pop();
	element_t peek();
private:
	struct cell_t {
		element_t data[BLOCK_SIZE];
		cell_t *link;
	};
	cell_t *list;
	int count;
	int length;
};

#include "Stack.hpp"

#endif
