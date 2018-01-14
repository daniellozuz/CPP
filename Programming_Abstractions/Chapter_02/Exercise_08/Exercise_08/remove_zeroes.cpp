#include <iostream>

using namespace std;

void remove_zero_elements(int numbers[], int &number_count);
void show(int numbers[], int number_count);

int main(void) {
    int numbers[] = { 65, 0, 95, 0, 0, 79, 82, 0, 84, 94, 86, 90, 0 };
    int number_count = sizeof numbers / sizeof numbers[0];

    remove_zero_elements(numbers, number_count);
    show(numbers, number_count);
    
    cin.get();
    return 0;
}

void remove_zero_elements(int numbers[], int &number_count) {
    int new_number_count = 0;
    for (int i = 0; i < number_count; i++) {
        if (numbers[i] != 0)
            numbers[new_number_count++] = numbers[i];
    }
    number_count = new_number_count;
}

void show(int numbers[], int number_count) {
    for (int i = 0; i < number_count; i++)
        cout << numbers[i] << endl;
}
