#include <iostream>

using namespace std;

int digit_sum(unsigned int number);
int digital_root(unsigned int number);

int main(void) {
    cout << digital_root(1729) << endl;
    cout << digital_root(19) << endl;
    cout << digital_root(0) << endl;

    cin.get();
    return 0;
}

int digit_sum(unsigned int number) {
    if (number < 10)
        return number;
    return number % 10 + digit_sum(number / 10);
}

int digital_root(unsigned int number) {
    if (number < 10)
        return number;
    return digital_root(digit_sum(number));
}
