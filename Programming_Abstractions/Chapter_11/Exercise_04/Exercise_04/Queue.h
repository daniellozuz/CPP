#ifndef _queue_h
#define _queue_h

template <typename T>
class Queue {
public:
	Queue();
	~Queue();
	int size();
	bool is_empty();
	void clear();
	void enqueue(T elem);
	void enqueue(T elem, double priority);
	T dequeue();
	T peek();
	void reverse();
private:
	struct cell_t {
		cell_t *next;
		T element;
		double priority;
	};
	cell_t *head;
	cell_t *tail;
	int count;
};

#include "Queue.hpp"

#endif
