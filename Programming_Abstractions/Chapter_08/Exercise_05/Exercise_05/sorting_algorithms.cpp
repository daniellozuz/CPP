#include <iostream>
#include <vector>

using namespace std;

void show(int vec[], int size);
void selection_sort(int vec[], int size);
int *merge_sort(int vec[], int size);
int *merge(int v1[], int size1, int v2[], int size2);
//void quick_sort(int vec[], int size);
//void quick_sort(int vec[], int start, int finish);
//int partition(int vec[], int start, int finish);
void swap(int vec[], int i, int j);
int *append(int vec[], int size, int value);

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
	/*
	int vec4[8] = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec4, 8);
	quick_sort(vec4, 8);
	show(vec4, 8);
	*/
	cin.get();
	return 0;
}

void selection_sort(int vec[], int size) {
	for (int lh = 0; lh < size; lh++) {
		int rh = lh;
		for (int i = lh + 1; i < size; i++) {
			if (vec[i] < vec[rh])
				rh = i;
		}
		swap(vec, lh, rh);
	}
}

int *merge_sort(int vec[], int size) {
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

int *append(int vec[], int size, int value) {
	int *new_vec = new int[size + 1];
	for (int i = 0; i < size; i++)
		new_vec[i] = vec[i];
	new_vec[size] = value;
	return new_vec;
}

int *merge(int v1[], int size1, int v2[], int size2) {
	int *new_vec = new int[0];
	int p1 = 0;
	int p2 = 0;
	while (p1 < size1 && p2 < size2) {
		if (v1[p1] < v2[p2]) {
			new_vec = append(new_vec, p1 + p2, v1[p1]);
			p1++;
		}
		else {
			new_vec = append(new_vec, p1 + p2, v2[p2]);
			p2++;
		}
	}
	while (p1 < size1) {
		new_vec = append(new_vec, p1 + p2, v1[p1]);
		p1++;
	}
	while (p2 < size2) {
		new_vec = append(new_vec, p1 + p2, v2[p2]);
		p2++;
	}
	return new_vec;
}

/*void quick_sort(vector<int> &vec) {
	quick_sort(vec, 0, vec.size() - 1);
}*/

/*void quick_sort(vector<int> &vec, int start, int finish) {
	if (start >= finish)
		return;
	int boundary = partition(vec, start, finish);
	quick_sort(vec, start, boundary - 1);
	quick_sort(vec, boundary + 1, finish);
}*/

/*int partition(vector<int> &vec, int start, int finish) {
	int pivot = vec[start];
	int lh = start + 1;
	int rh = finish;
	while (true) {
		while (lh < rh && vec[rh] >= pivot)
			rh--;
		while (lh < rh && vec[lh] < pivot)
			lh++;
		if (lh == rh)
			break;
		swap(vec, lh, rh);
	}
	if (vec[lh] >= pivot)
		return start;
	vec[start] = vec[lh];
	vec[lh] = pivot;
	return lh;
}*/

void show(int vec[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << vec[i] << ", ";
	cout << "]" << endl << endl;
}

void swap(int vec[], int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}