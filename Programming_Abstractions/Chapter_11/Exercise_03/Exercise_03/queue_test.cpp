#include <iostream>
#include "Queue.h"

using namespace std;

int main(void) {
	Queue<int> q;

	for (int i = 9; i >= 0; i--)
		q.enqueue(i);
	q.reverse();

	for (int i = 0; i < 10; i++) {
		cout << (q.size() == 10 - i);
		cout << (!q.is_empty());
		cout << (q.peek() == i);
		cout << (q.dequeue() == i) << endl;
	}
	cout << (q.is_empty()) << endl;

	cin.get();
	return 0;
}
