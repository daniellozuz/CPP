#ifndef _rationalstack_h
#define _rationalstack_h

#include "Rational.h"
#include <vector>

using namespace std;

class RationalStack {
public:
	RationalStack();
	~RationalStack();
	int size();
	bool is_empty();
	void clear();
	void push(Rational element);
	Rational pop();
	Rational peek();

private:
	vector<Rational> vec;
};

#endif