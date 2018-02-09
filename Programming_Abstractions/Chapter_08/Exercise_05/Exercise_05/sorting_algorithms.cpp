#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> &vec);
void selection_sort(vector<int> &vec);
void merge_sort(vector<int> &vec);
void merge(vector<int> &vec, vector<int> &v1, vector<int> &v2);
void quick_sort(vector<int> &vec);
void quick_sort(vector<int> &vec, int start, int finish);
int partition(vector<int> &vec, int start, int finish);
void swap(vector<int> &vec, int i, int j);

int main(void) {
	vector<int> vec1 = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec1);
	selection_sort(vec1);
	show(vec1);

	vector<int> vec2 = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec2);
	merge_sort(vec2);
	show(vec2);

	vector<int> vec3 = { 1, 4, 5, 2, 6, 1, 8, 0 };
	show(vec3);
	quick_sort(vec3);
	show(vec3);

	cin.get();
	return 0;
}

void selection_sort(vector<int> &vec) {
	int n = vec.size();
	for (int lh = 0; lh < n; lh++) {
		int rh = lh;
		for (int i = lh + 1; i < n; i++) {
			if (vec[i] < vec[rh])
				rh = i;
		}
		swap(vec, lh, rh);
	}
}

void merge_sort(vector<int> &vec) {
	int n = vec.size();
	if (n <= 1)
		return;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			v1.push_back(vec[i]);
		else
			v2.push_back(vec[i]);
	}
	merge_sort(v1);
	merge_sort(v2);
	vec.clear();
	merge(vec, v1, v2);
}

void merge(vector<int> &vec, vector<int> &v1, vector<int> &v2) {
	int n1 = v1.size();
	int n2 = v2.size();
	int p1 = 0;
	int p2 = 0;
	while (p1 < n1 && p2 < n2) {
		if (v1[p1] < v2[p2])
			vec.push_back(v1[p1++]);
		else
			vec.push_back(v2[p2++]);
	}
	while (p1 < n1)
		vec.push_back(v1[p1++]);
	while (p2 < n2)
		vec.push_back(v2[p2++]);
}

void quick_sort(vector<int> &vec) {
	quick_sort(vec, 0, vec.size() - 1);
}

void quick_sort(vector<int> &vec, int start, int finish) {
	if (start >= finish)
		return;
	int boundary = partition(vec, start, finish);
	quick_sort(vec, start, boundary - 1);
	quick_sort(vec, boundary + 1, finish);
}

int partition(vector<int> &vec, int start, int finish) {
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
}

void show(vector<int> &vec) {
	cout << "[";
	for (int number : vec)
		cout << number << ", ";
	cout << "]" << endl;
}

void swap(vector<int> &vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}