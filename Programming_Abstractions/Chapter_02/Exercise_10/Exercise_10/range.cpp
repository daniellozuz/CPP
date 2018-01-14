#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

void show_range(int numbers[], int numbers_count);

int main(void) {
    int numbers[MAX_SIZE];
    int numbers_count = 0;
    int number;

    cout << "Enter the elements of the array, one per line." << endl;
    cout << "Use negative number to signal the end of the list." << endl;

    while (true) {
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (number < 0)
            break;
        numbers[numbers_count++] = number;
    }

    show_range(numbers, numbers_count);

    cin.get();
    return 0;
}

void show_range(int numbers[], int numbers_count) {
    int lowest = 100;
    int highest = 0;
    for (int i = 0; i < numbers_count; i++) {
        if (numbers[i] > highest)
            highest = numbers[i];
        if (numbers[i] < lowest)
            lowest = numbers[i];
    }
    cout << "The range of values is " << lowest << "-" << highest << endl;
}
