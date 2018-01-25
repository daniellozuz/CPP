#include <iostream>
#include <iomanip>

using namespace std;

int count_fib1(int n, int &calls);
int count_fib2(int n, int &calls);
int additive_sequence(int n, int t0, int t1, int &calls);

int main(void) {
    int calls_fib1;
    int calls_fib2;

    cout << "This program compares the performance of two" << endl;
    cout << "algorithms to compute the Fibonacci sequence." << endl;
    cout << "Number of calls :" << endl;
    cout << setw(6) << "N" << setw(6) << "fib1" << setw(6) << "fib2" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i <= 12; i++) {
        calls_fib1 = 0;
        calls_fib2 = 0;
        count_fib1(i, calls_fib1);
        count_fib2(i, calls_fib2);
        cout << setw(6) << i << setw(6) << calls_fib1 << setw(6) << calls_fib2 << endl;
    }

    cin.get();
    return 0;
}

int count_fib1(int n, int &calls) {
    calls++;
    if (n < 2)
        return n;
    return count_fib1(n - 1, calls) + count_fib1(n - 2, calls);
}

int count_fib2(int n, int &calls) {
    return additive_sequence(n, 0, 1, calls);
}

int additive_sequence(int n, int t0, int t1, int &calls) {
    calls++;
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return additive_sequence(n - 1, t1, t0 + t1, calls);
}
