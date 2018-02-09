#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &vec);
void show(vector<int> &vec);

int main(void) {
	vector<int> vec = { 56, 25, 37, 58, 95, 19, 73, 30 };
	
	show(vec);
	sort(vec);
	show(vec);

	cin.get();
	return 0;
}

void sort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
		int j;
		int tmp = vec[i];
		for (j = i - 1; j >= 0 && vec[j] > tmp; j--)
			vec[j + 1] = vec[j];
		vec[j + 1] = tmp;
	}
}

void show(vector<int> &vec) {
	cout << '[';
	for (int number : vec)
		cout << number << ", ";
	cout << ']' << endl;
}
