#include <iostream>

using namespace std;

int combinations(int n, int k);

int main(void) {
    cout << combinations(0, 0) << endl;
    cout << combinations(2, 0) << endl;
    cout << combinations(4, 3) << endl;
    cout << combinations(4, 2) << endl;

    cin.get();
    return 0;
}

int combinations(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return combinations(n - 1, k - 1) + combinations(n - 1, k);
}
