#include <iostream>
#include <vector>

using namespace std;

const int CROSSOVER_SIZE = 7;

void sort(vector<int> &vec);
void insertion_sort(vector<int> &vec);
void hybrid_sort(vector<int> &vec);
void hybrid_sort(vector<int> &vec, int start, int end);
int partition(vector<int> &vec, int start, int end);
void swap(vector<int> &vec, int i, int j);
int median(int n1, int n2, int n3);
void show(vector<int> &vec);

int main(void) {
	vector<int> vec = { 1, 5, 2, 7, 2, 8, 0, 2, 7, 3, 1, 5, 2, 6, 8, 2, 6, 9, 3, 2, 6, 8, 9, 3, 2, 5, 7, 9 };

	sort(vec);
	show(vec);

	cin.get();
	return 0;
}

void sort(vector<int> &vec) {
	hybrid_sort(vec);
}

void insertion_sort(vector<int> &vec, int start, int end) {
	for (int i = start + 1; i <= end; i++) {
		int j;
		int tmp = vec[i];
		for (j = i - 1; j >= start && vec[j] > tmp; j--)
			vec[j + 1] = vec[j];
		vec[j + 1] = tmp;
	}
}

void insertion_sort(vector<int> &vec) {
	insertion_sort(vec, 0, vec.size() - 1);
}

void hybrid_sort(vector<int> &vec) {
	hybrid_sort(vec, 0, vec.size() - 1);
}

void hybrid_sort(vector<int> &vec, int start, int end) {
	if (end - start < CROSSOVER_SIZE) {
		insertion_sort(vec, start, end);
		return;
	}
	int boundary = partition(vec, start, end);
	hybrid_sort(vec, start, boundary);
	hybrid_sort(vec, boundary + 1, end);
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
