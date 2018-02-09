#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 10000;

void sort(vector<int> &vec);
void show(vector<int> &vec);

int main(void) {
	vector<int> vec = { 5, 7, 2, 999, 2, 2, 657, 11 };
	
	show(vec);
	sort(vec);
	show(vec);

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
