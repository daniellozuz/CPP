#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZES[] = { 10, 20, 40, 100, 200, 400, 1000, 2000, 4000, 10000 };
const int N_SIZES = sizeof SIZES / sizeof SIZES[0];
const int REPETITIONS = 10;

int linear_search(vector<int> &vec, int target, int &comparisons);
int binary_search(vector<int> &vec, int target, int &comparisons);
int binary_search(vector<int> &vec, int target, int start, int end, int &comparisons);
vector<int> random_sorted_vector(int size);
int choose(vector<int> &vec);
void show(vector<int> &vec);

int main(void) {
	vector<int> vec;
	int linear_comparisons, binary_comparisons;

	cout << "     N |  Linear  |  Binary " << endl;
	cout << "-------+----------+---------" << endl;
	for (int i = 0; i < N_SIZES; i++) {
		linear_comparisons = 0;
		binary_comparisons = 0;
		for (int j = 0; j < REPETITIONS; j++) {
			vec = random_sorted_vector(SIZES[i]);
			linear_search(vec, rand() % SIZES[i], linear_comparisons);
			binary_search(vec, rand() % SIZES[i], binary_comparisons);
		}
		cout << setw(6) << SIZES[i] << " | ";
		cout << setw(7) << setprecision(4) << double(linear_comparisons) / REPETITIONS << "  | ";
		cout << setw(7) << setprecision(4) << double(binary_comparisons) / REPETITIONS << endl;
	}

	cin.get();
	return 0;
}

int linear_search(vector<int> &vec, int target, int &comparisons) {
	for (int i = 0; i < vec.size(); i++) {
		comparisons++;
		if (vec[i] == target)
			return i;
	}
	return -1;
}

int binary_search(vector<int> &vec, int target, int &comparisons) {
	return binary_search(vec, target, 0, vec.size() - 1, comparisons);
}

int binary_search(vector<int> &vec, int target, int start, int end, int &comparisons) {
	if (start > end)
		return -1;
	int middle = (start + end) / 2;
	comparisons++;
	if (vec[middle] == target)
		return middle;
	comparisons++;
	if (target < vec[middle])
		return binary_search(vec, target, start, middle - 1, comparisons);
	return binary_search(vec, target, middle + 1, end, comparisons);
}

vector<int> random_sorted_vector(int size) {
	vector<int> vec;
	for (int i = 0; i < size; i++)
		vec.push_back(rand() % size);
	sort(vec.begin(), vec.end());
	return vec;
}

int choose(vector<int> &vec) {
	return vec[rand() % vec.size()];
}

void show(vector<int> &vec) {
	cout << "[";
	for (int number : vec)
		cout << number << ", ";
	cout << "]" << endl;
}
