#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

const int LIMIT = 10000;
const int N_CYCLES = 100;
const int SIZES[] = { 10, 20, 40, 100, 200, 400, 1000, 2000, 4000, 10000 };

void sort(vector<int> &vec);
void show(vector<int> &vec);
double measure_sorting_time(int size);
vector<int> create_random_vector(int size);

int main(void) {
	cout << "     N | Time (msec)" << endl;
	cout << "-------+------------" << endl;
	for (int size : SIZES)
		cout << setw(6) << size << " |  " << setw(10) << setprecision(2) << 1000 * measure_sorting_time(size) << endl;

	cin.get();
	return 0;
}

void sort(vector<int> &vec) {
	vector<int> new_vec;
	int amounts[LIMIT] = { 0 };
	for (int number : vec)
		amounts[number]++;
	for (int i = 0; i < LIMIT; i++) {
		for (int j = 0; j < amounts[i]; j++)
			new_vec.push_back(i);
	}
	vec = new_vec;
}

void show(vector<int> &vec) {
	cout << '[';
	for (int number : vec)
		cout << number << ", ";
	cout << ']' << endl;
}

double measure_sorting_time(int size) {
	double start = double(clock()) / CLOCKS_PER_SEC;
	for (int i = 0; i < N_CYCLES; i++) {
		vector<int> vec = create_random_vector(size);
		sort(vec);
	}
	return (double(clock()) / CLOCKS_PER_SEC - start) / N_CYCLES;
}

vector<int> create_random_vector(int size) {
	vector<int> vec;
	for (int i = 0; i < size; i++)
		vec.push_back(rand() % LIMIT);
	return vec;
}

