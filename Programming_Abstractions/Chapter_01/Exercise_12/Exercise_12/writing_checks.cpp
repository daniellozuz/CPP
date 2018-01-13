#include <iostream>

#define LIMIT 999999

using namespace std;

void Print(int number);
void PrintOneDigit(int digit);
void PrintTwoDigits(int number);
void PrintThreeDigits(int number);

int main(void) {
    int number;

    cout << "Enter numbers in figures; use a negative value to stop.";
    
    while (true) {
        cout << endl << "Number: ";
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (number < 0 || number > LIMIT)
            break;

        Print(number);
    }
    
    return 0;
}

void Print(int number) {
    if (number == 0) {
        cout << "zero";
        return;
    }
    if (number >= 1000) {
        PrintThreeDigits(number / 1000);
        number %= 1000;
        cout << " thousand ";
    }
    PrintThreeDigits(number);
}

void PrintOneDigit(int digit) {
    switch (digit) {
        case 0: break;
        case 1: cout << "one"; break;
        case 2: cout << "two"; break;
        case 3: cout << "three"; break;
        case 4: cout << "four"; break;
        case 5: cout << "five"; break;
        case 6: cout << "six"; break;
        case 7: cout << "seven"; break;
        case 8: cout << "eight"; break;
        case 9: cout << "nine"; break;
        default: cout << "Error!";
    }
}

void PrintTwoDigits(int number) {
    if (number >= 10 && number <= 19) {
        switch (number) {
            case 10: cout << "ten"; break;
            case 11: cout << "eleven"; break;
            case 12: cout << "twelve"; break;
            case 13: cout << "thirteen"; break;
            case 14: cout << "fourteen"; break;
            case 15: cout << "fifteen"; break;
            case 16: cout << "sixteen"; break;
            case 17: cout << "seventeen"; break;
            case 18: cout << "eighteen"; break;
            case 19: cout << "nineteen"; break;
            default: cout << "Error!";
        }
    }
    else {
        switch (number / 10) {
            case 0: break;
            case 1: cout << "Error!"; break;
            case 2: cout << "twenty"; break;
            case 3: cout << "thirty"; break;
            case 4: cout << "forty"; break;
            case 5: cout << "fifty"; break;
            case 6: cout << "sixty"; break;
            case 7: cout << "seventy"; break;
            case 8: cout << "eighty"; break;
            case 9: cout << "ninety"; break;
            default: cout << "Error!";
        }
        if (number > 20 && number % 10 != 0)
            cout << "-";
        PrintOneDigit(number % 10);
    }
}

void PrintThreeDigits(int number) {
    if (number >= 100) {
        PrintOneDigit(number / 100);
        cout << " hundred ";
    }
    PrintTwoDigits(number % 100);
}
