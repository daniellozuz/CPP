#ifndef _numstack_h
#define _numstack_h

#include <vector>

using namespace std;

class NumStack {
public:
	NumStack();
	~NumStack();
	int size();
	bool is_empty();
	void clear();
	void push(double element);
	double pop();
	double peek();

private:
	vector<double> vec;
};

#endif
