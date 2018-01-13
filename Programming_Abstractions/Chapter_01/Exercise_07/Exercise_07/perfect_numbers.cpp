#include <iostream>

#define LOWER 1
#define UPPER 9999

using namespace std;

bool IsPerfect(int number);

int main(void) {
    for (int number = LOWER; number <= UPPER; number++) {
        if (IsPerfect(number))
            cout << number << endl;
    }

    cin.get();
    return 0;
}

bool IsPerfect(int number) {
    int sumOfProperDivisors = 0;

    for (int divisor = 1; divisor < number; divisor++) {
        if (number % divisor == 0)
            sumOfProperDivisors += divisor;
    }

    if (sumOfProperDivisors == number)
        return true;
    return false;
}
