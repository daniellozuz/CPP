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
	T dequeue();
	T peek();
	void reverse();
private:
	static const int INITIAL_CAPACITY = 100;
	T *elements;
	int capacity;
	int head;
	int count;
	void expand_capacity();
};

#include "Queue.hpp"

#endif
