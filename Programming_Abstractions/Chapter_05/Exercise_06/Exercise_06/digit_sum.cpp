#include <iostream>

using namespace std;

int digit_sum(unsigned int number);

int main(void) {
    cout << digit_sum(1729) << endl;
    cout << digit_sum(11) << endl;
    cout << digit_sum(0) << endl;

    cin.get();
    return 0;
}

int digit_sum(unsigned int number) {
    if (number < 10)
        return number;
    return number % 10 + digit_sum(number / 10);
}
