#ifndef _charstack_h
#define _charstack_h

#include <vector>

using namespace std;

class CharStack {
public:
	CharStack();
	~CharStack();
	int size();
	bool is_empty();
	void clear();
	void push(char element);
	char pop();
	char peek();

private:
	vector<char> vec;
};

#endif
