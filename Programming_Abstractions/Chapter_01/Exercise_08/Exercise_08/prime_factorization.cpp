#include <iostream>

using namespace std;

void Factor(int number);

int main(void) {
    int number;

    cout << "Enter number to be factored: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Factor(number);

    cin.get();
    return 0;
}

void Factor(int number) {
    int divisor = 2;

    while (number > 1) {
        if (number % divisor == 0) {
            number /= divisor;
            cout << divisor;
            if (number > 1)
                cout << " * ";
            divisor = 2;
            continue;
        }
        divisor++;
    }
}
