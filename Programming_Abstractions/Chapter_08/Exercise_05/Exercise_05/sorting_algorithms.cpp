#include <iostream>
#include <vector>

using namespace std;

void show(int *vec, int size);
void selection_sort(int *vec, int size);
int *merge_sort(int *vec, int size);
int *merge(int *v1, int size1, int *v2, int size2);
void quick_sort(int *vec, int size);
void quick_sort(int *vec, int start, int finish);
int partition(int *vec, int start, int finish);
void swap(int *vec, int i, int j);
int *append(int *vec, int size, int value);

int main(void) {
	int vec1[8] = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec1, 8);
	selection_sort(vec1, 8);
	show(vec1, 8);

	int vec2[8] = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec2, 8);
	int *vec3;
	vec3 = merge_sort(vec2, 8);
	show(vec3, 8);
	
	int vec4[8] = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec4, 8);
	quick_sort(vec4, 8);
	show(vec4, 8);
	
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

int *merge_sort(int *vec, int size) {
	if (size <= 1)
		return vec;
	int *v1 = new int[0];
	int v1_size = 0;
	int *v2 = new int[0];
	int v2_size = 0;
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			v1 = append(v1, v1_size++, vec[i]);
		else
			v2 = append(v2, v2_size++, vec[i]);
	}
	v1 = merge_sort(v1, v1_size);
	v2 = merge_sort(v2, v2_size);
	vec = merge(v1, v1_size, v2, v2_size);
	return vec;
}

int *append(int *vec, int size, int value) {
	int *new_vec = new int[size + 1];
	for (int i = 0; i < size; i++)
		new_vec[i] = vec[i];
	new_vec[size] = value;
	return new_vec;
}

int *merge(int *v1, int size1, int *v2, int size2) {
	int *new_vec = new int[0];
	int i1 = 0;
	int i2 = 0;
	while (i1 < size1 && i2 < size2) {
		if (v1[i1] < v2[i2]) {
			new_vec = append(new_vec, i1 + i2, v1[i1]);
			i1++;
		}
		else {
			new_vec = append(new_vec, i1 + i2, v2[i2]);
			i2++;
		}
	}
	while (i1 < size1) {
		new_vec = append(new_vec, i1 + i2, v1[i1]);
		i1++;
	}
	while (i2 < size2) {
		new_vec = append(new_vec, i1 + i2, v2[i2]);
		i2++;
	}
	return new_vec;
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