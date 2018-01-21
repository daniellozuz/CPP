#include <iostream>
#include <vector>

using namespace std;

void remove_zero_elements(vector<int> &vec);
void show(vector<int> &vec);

int main(void) {
    vector<int> numbers = { 0, 7, 12, -5, 0, 13, 6, 0, 7};
    show(numbers);
    remove_zero_elements(numbers);
    show(numbers);

    cin.get();
    return 0;
}

void remove_zero_elements(vector<int> &vec) {
    vector<int> new_vec;
    for (int number : vec) {
        if (number != 0)
            new_vec.push_back(number);
    }
    vec = new_vec;
}

void show(vector<int> &vec) {
    cout << "[";
    for (int number : vec)
        cout << number << ", ";
    cout << "]" << endl;
}
