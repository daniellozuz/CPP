#include <iostream>

using namespace std;

int fib(int n);

int main(void) {
    cout << fib(0) << endl;
    cout << fib(1) << endl;
    cout << fib(2) << endl;
    cout << fib(3) << endl;

    cin.get();
    return 0;
}

int fib(int n) {
    int t1 = 0;
    int t2 = 1;
    int temp;
    if (n == 0)
        return t1;
    for (int i = 2; i <= n; i++) {
        temp = t2;
        t2 += t1;
        t1 = temp;
    }
    return t2;
}
