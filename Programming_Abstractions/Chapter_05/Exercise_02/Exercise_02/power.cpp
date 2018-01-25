#include <iostream>

using namespace std;

int raise_integer_to_power(int number, int power);

int main(void) {
    cout << raise_integer_to_power(1, 0) << endl;
    cout << raise_integer_to_power(7, 0) << endl;
    cout << raise_integer_to_power(2, 5) << endl;
    cout << raise_integer_to_power(4, 2) << endl;
    cout << raise_integer_to_power(0, 0) << endl; // Error handling not implemented.

    cin.get();
    return 0;
}

int raise_integer_to_power(int number, int power) {
    if (power == 0)
        return 1;
    return number * raise_integer_to_power(number, power - 1);
}
