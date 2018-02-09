#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &vec);
void quick_sort(vector<int> &vec, int start, int end);
int partition(vector<int> &vec, int start, int end);
void swap(vector<int> &vec, int i, int j);
int median(int n1, int n2, int n3);
void show(vector<int> &vec);

int main(void) {
	vector<int> vec = { 1, 5, 2, 7, 2, 8, 0, 2, 7, 3 };
	
	quick_sort(vec);
	show(vec);

	cin.get();
	return 0;
}

void quick_sort(vector<int> &vec) {
	quick_sort(vec, 0, vec.size() - 1);
}

void quick_sort(vector<int> &vec, int start, int end) {
	cout << endl << "Sorting from " << start << " to " << end << endl;
	show(vec);
	if (start >= end)
		return;
	int boundary = partition(vec, start, end);
	quick_sort(vec, start, boundary - 1);
	quick_sort(vec, boundary + 1, end);
}

int partition(vector<int> &vec, int start, int end) {
	int pivot = median(vec[start], vec[(start + end) / 2], vec[end]);
	int left = start;
	int right = end;
	while (true) {
		while (left < right && vec[right] >= pivot)
			right--;
		while (left < right && vec[left] < pivot)
			left++;
		if (left == right)
			break;
		swap(vec, left, right);
	}
	if (vec[start] > vec[left])
		swap(vec, start, left);
	return left;
}

int median(int n1, int n2, int n3) {
	return (n1 > n2) ? (n3 > n1 ? n1 : (n2 > n3 ? n2 : n3)) : (n3 > n2 ? n2 : (n1 > n3 ? n1 : n3));
}

void swap(vector<int> &vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

void show(vector<int> &vec) {
	cout << "[";
	for (int number : vec)
		cout << number << ", ";
	cout << "]" << endl;
}
