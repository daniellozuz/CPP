#ifdef _quicksort_h

template<typename T>
Quicksort<T>::Quicksort() {
}

template<typename T>
Quicksort<T>::~Quicksort() {
}

template<typename T>
void Quicksort<T>::sort(T *elements, int n, int (*cmp)(T, T)) {
	quicksort(elements, 0, n - 1, cmp);
}

template<typename T>
void Quicksort<T>::quicksort(T *elements, int start, int finish, int (*cmp)(T, T)){
	if (start >= finish)
		return;
	int boundary = partition(elements, start, finish, cmp);
	quicksort(elements, start, boundary - 1, cmp);
	quicksort(elements, boundary + 1, finish, cmp);
}

template<typename T>
int Quicksort<T>::partition(T *elements, int start, int finish, int (*cmp)(T, T)) {
	T pivot = elements[start];
	int left = start + 1;
	int right = finish;
	while (true) {
		while (left < right && !(cmp(elements[right], pivot) == -1))
			right--;
		while (left < right && cmp(elements[left], pivot) == -1)
			left++;
		if (left == right)
			break;
		T temp = elements[left];
		elements[left] = elements[right];
		elements[right] = temp;
	}
	if (!(cmp(elements[left], pivot) == -1))
		return start;
	elements[start] = elements[left];
	elements[left] = pivot;
	return left;
}

#endif
