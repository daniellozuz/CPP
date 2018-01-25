#include <iostream>
#include <string>

using namespace std;

string integer_to_string(int number);

int main(void) {
    cout << integer_to_string(2) << endl;
    cout << integer_to_string(221243) << endl;

    cin.get();
    return 0;
}

string integer_to_string(int number) {
    if (number < 10)
        return string(1, char('0' + number));
    return integer_to_string(number / 10) + string(1, char('0' + number % 10));
}
