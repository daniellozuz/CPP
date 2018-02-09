#include <iostream>
#include <vector>

using namespace std;

int majority_element(vector<int> &vec);
int find_candidate(vector<int> &vec);
bool is_majority(vector<int> &vec, int candidate);

int main(void) {
	vector<int> vec = { 0, 1, 2, 2, 1, 2, 2, 3, 1, 2, 2 };
	cout << majority_element(vec);

	cin.get();
	return 0;
}

int majority_element(vector<int> &vec) {
	int candidate = find_candidate(vec);
	return (is_majority(vec, candidate)) ? candidate : -1;
}

int find_candidate(vector<int> &vec) {
	int solution_index = 0;
	int count = 1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == vec[solution_index])
			count++;
		else
			count--;
		if (count == 0) {
			solution_index = i;
			count = 1;
		}
	}
	return vec[solution_index];
}

bool is_majority(vector<int> &vec, int candidate) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == candidate)
			count++;
	}
	return (count > vec.size() / 2);
}
