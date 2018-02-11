#include <iostream>
#include "CharStack.h"

using namespace std;

int main(void) {
	CharStack stack;

	stack.push('d');
	stack.push('u');
	stack.push('p');
	stack.push('a');
	cout << stack.peek() << endl;
	cout << stack.pop() << endl;
	cout << stack.peek() << endl;
	cout << stack.size() << endl;
	cout << stack.is_empty() << endl;
	stack.clear();
	cout << stack.is_empty() << endl;

	cin.get();
	return 0;
}
