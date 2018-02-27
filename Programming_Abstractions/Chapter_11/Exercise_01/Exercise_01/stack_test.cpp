#include <iostream>
#include "Stack.h"

using namespace std;

int main(void) {
	Stack<int> stack;

	for (int i = 0; i < 10; i++)
		stack.push(i);
	
	stack.clear();

	for (int i = 0; i < 10; i++)
		stack.push(i);

	for (int i = 0; i < 10; i++) {
		cout << stack.peek() << "  ";
		cout << stack.pop() << "  ";
		cout << stack.size() << "  ";
		cout << stack.is_empty() << endl;
	}

	cin.get();
	return 0;
}
