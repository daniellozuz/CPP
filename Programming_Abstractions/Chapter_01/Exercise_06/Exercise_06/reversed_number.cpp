#include <iostream>

using namespace std;

int main(void) {
    long number;
    long reversedNumber = 0L;

    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (number > 0) {
        reversedNumber *= 10;
        reversedNumber += number % 10;
        number /= 10;
    }

    cout << "The reversed integer is " << reversedNumber;
    
    cin.get();
    return 0;
}
