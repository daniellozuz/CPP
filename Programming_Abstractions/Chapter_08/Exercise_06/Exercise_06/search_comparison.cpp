#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZES[] = { 10, 20, 40, 100, 200, 400, 1000, 2000, 4000, 10000 };

vector<int> random_sorted_vector(int size);
int choose(vector<int> &vec);
void show(vector<int> &vec);


int main(void) {
	vector<int> vec = random_sorted_vector(10);
	show(vec);

	cin.get();
	return 0;
}

vector<int> random_sorted_vector(int size) {
	vector<int> vec;
	for (int i = 0; i < size; i++)
		vec.push_back(rand());
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
