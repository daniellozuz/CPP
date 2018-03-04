#include <iostream>

using namespace std;

const int SIZE = 10;

template<typename T>
int binary_search(T key, T *elements, int n, int(*cmp)(T, T));
template<typename T>
int binary_search_helper(T key, T *elements, int low, int high, int(*cmp)(T, T));
template <typename T>
int operator_cmp(T one, T two);

int main(void) {
	int vec[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << binary_search(1, vec, SIZE, operator_cmp) << endl;
	cout << binary_search(5, vec, SIZE, operator_cmp) << endl;
	cout << binary_search(10, vec, SIZE, operator_cmp) << endl;
	cout << binary_search(50, vec, SIZE, operator_cmp) << endl;

	cin.get();
	return 0;
}

template<typename T>
int binary_search(T key, T *elements, int n, int(*cmp)(T, T)) {
	return binary_search_helper(key, elements, 0, n - 1, cmp);
}

template<typename T>
int binary_search_helper(T key, T *elements, int low, int high, int(*cmp)(T, T)) {
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (cmp(key, elements[mid]) == 0)
		return mid;
	if (cmp(key, elements[mid]) == -1)
		return binary_search_helper(key, elements, low, mid - 1, cmp);
	return binary_search_helper(key, elements, mid + 1, high, cmp);
}

template <typename T>
int operator_cmp(T one, T two) {
	if (one == two)
		return 0;
	if (one < two)
		return -1;
	return 1;
}