#include <iostream>

using namespace std;

bool is_sorted(int integers[], int amount);

int main(void) {
    int sorted_integers[] = { 1, 2, 3, 3, 4, 5, 6, 7 };
    int unsorted_integers[] = { 1, 2, 3, 4, 3, 6, 7 };
    int sorted_integers_length = sizeof sorted_integers / sizeof sorted_integers[0];
    int unsorted_integers_length = sizeof unsorted_integers / sizeof unsorted_integers[0];

    cout << "Expected true: " << is_sorted(sorted_integers, sorted_integers_length) << endl;
    cout << "Expected false: " << is_sorted(unsorted_integers, unsorted_integers_length) << endl;

    cin.get();
    return 0;
}

bool is_sorted(int integers[], int amount) {
    for (int i = 0; i < amount - 1; i++) {
        if (integers[i + 1] < integers[i])
            return false;
    }
    return true;
}
