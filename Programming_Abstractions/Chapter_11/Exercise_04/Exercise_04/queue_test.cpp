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
	cout << endl;

	q.enqueue(7, 2.0);
	q.enqueue(4, 3.0);
	q.enqueue(2, 1.0);
	q.enqueue(3, 2.0);
	q.enqueue(4, 2.0);
	
	cout << (q.dequeue() == 2) << endl;
	cout << (q.dequeue() == 7) << endl;
	cout << (q.dequeue() == 3) << endl;
	cout << (q.dequeue() == 4) << endl;
	cout << (q.dequeue() == 4) << endl;

	cin.get();
	return 0;
}
