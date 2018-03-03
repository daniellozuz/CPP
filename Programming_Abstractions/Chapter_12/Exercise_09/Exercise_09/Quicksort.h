#ifndef _quicksort_h
#define _quicksort_h

template<typename T>
class Quicksort {
public:
	Quicksort();
	~Quicksort();
	void sort(T *elements, int n, int (*cmp)(T, T));

private:
	void quicksort(T *elements, int start, int finish, int (*cmp)(T, T));
	int partition(T *elements, int start, int finish, int(*cmp)(T, T));
};

#include "Quicksort.hpp"

#endif
