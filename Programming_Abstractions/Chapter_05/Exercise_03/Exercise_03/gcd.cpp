#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(void) {
    cout << gcd(13, 13) << " Expected: 13" << endl;
    cout << gcd(37, 600) << " Expected: 1" << endl;
    cout << gcd(20, 100) << " Expected: 20" << endl;
    cout << gcd(624129, 2061517) << " Expected: 18913" << endl;

    cin.get();
    return 0;
}

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
