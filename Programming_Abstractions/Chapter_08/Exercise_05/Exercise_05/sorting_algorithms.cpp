#include <iostream>
#include <vector>

using namespace std;

const int NUMBERS[] = { 1, 4, 5, 2, 6, 1, 8, 0 };
const int SIZE = sizeof NUMBERS / sizeof NUMBERS[0];

void show(int *vec, int size);
void selection_sort(int *vec, int size);
void merge_sort(int **vec, int size);
void merge(int **vec, int *v1, int size1, int *v2, int size2);
void quick_sort(int *vec, int size);
void quick_sort(int *vec, int start, int finish);
int partition(int *vec, int start, int finish);
void swap(int *vec, int i, int j);
void append(int **vec, int size, int value);

int main(void) {
	int *vec1 = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		vec1[i] = NUMBERS[i];
	show(vec1, SIZE);
	selection_sort(vec1, SIZE);
	show(vec1, SIZE);

	int *vec2 = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		vec2[i] = NUMBERS[i];
	show(vec2, SIZE);
	merge_sort(&vec2, SIZE);
	show(vec2, SIZE);
	
	int *vec3 = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		vec3[i] = NUMBERS[i];
	show(vec3, SIZE);
	quick_sort(vec3, SIZE);
	show(vec3, SIZE);
	
	cin.get();
	return 0;
}

void selection_sort(int *vec, int size) {
	for (int left = 0; left < size; left++) {
		int right = left;
		for (int i = left + 1; i < size; i++) {
			if (vec[i] < vec[right])
				right = i;
		}
		swap(vec, left, right);
	}
}

void merge_sort(int **vec, int size) {
	if (size <= 1)
		return;
	int *v1 = new int[0];
	int v1_size = 0;
	int *v2 = new int[0];
	int v2_size = 0;
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			append(&v1, v1_size++, (*vec)[i]);
		else
			append(&v2, v2_size++, (*vec)[i]);
	}
	merge_sort(&v1, v1_size);
	merge_sort(&v2, v2_size);
	merge(vec, v1, v1_size, v2, v2_size);
}

void append(int **vec, int size, int value) {
	int *new_vec = new int[size + 1];
	for (int i = 0; i < size; i++)
		new_vec[i] = (*vec)[i];
	new_vec[size] = value;
	*vec = new_vec;
}

void merge(int **vec, int *v1, int size1, int *v2, int size2) {
	int *new_vec = new int[0];
	int i1 = 0;
	int i2 = 0;
	while (i1 < size1 && i2 < size2) {
		if (v1[i1] < v2[i2]) {
			append(&new_vec, i1 + i2, v1[i1]);
			i1++;
		}
		else {
			append(&new_vec, i1 + i2, v2[i2]);
			i2++;
		}
	}
	while (i1 < size1) {
		append(&new_vec, i1 + i2, v1[i1]);
		i1++;
	}
	while (i2 < size2) {
		append(&new_vec, i1 + i2, v2[i2]);
		i2++;
	}
	*vec = new_vec;
}

void quick_sort(int *vec, int size) {
	quick_sort(vec, 0, size - 1);
}

void quick_sort(int *vec, int start, int finish) {
	if (start >= finish)
		return;
	int boundary = partition(vec, start, finish);
	quick_sort(vec, start, boundary - 1);
	quick_sort(vec, boundary + 1, finish);
}

int partition(int *vec, int start, int finish) {
	int pivot = vec[start];
	int left = start + 1;
	int right = finish;
	while (true) {
		while (left < right && vec[right] >= pivot)
			right--;
		while (left < right && vec[left] < pivot)
			left++;
		if (left == right)
			break;
		swap(vec, left, right);
	}
	if (vec[left] >= pivot)
		return start;
	vec[start] = vec[left];
	vec[left] = pivot;
	return left;
}

void show(int *vec, int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << vec[i] << ", ";
	cout << "]" << endl << endl;
}

void swap(int *vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}