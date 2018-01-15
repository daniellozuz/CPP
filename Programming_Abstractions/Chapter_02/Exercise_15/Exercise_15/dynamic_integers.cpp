#include <iostream>

using namespace std;

const int SENTINEL = 0;

int *get_dynamic_integer_array(int sentinel, int &integer_count);
void show(int integers[], int integer_count);

int main(void) {
    int integer_count = 0;

    int *integers = get_dynamic_integer_array(SENTINEL, integer_count);
    show(integers, integer_count);

    cin.get();
    return 0;
}

int *get_dynamic_integer_array(int sentinel, int &integer_count) {
    int *numbers = new int;
    while (true) {
        int number;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (number == sentinel)
            break;
        int *new_numbers = new int[integer_count + 1];
        for (int i = 0; i < integer_count; i++)
            new_numbers[i] = numbers[i];
        new_numbers[integer_count++] = number;
        numbers = new_numbers;
    }
    return numbers;
}

void show(int integers[], int integer_count) {
    for (int i = 0; i < integer_count; i++)
        cout << integers[i] << ", ";
    cout << endl;
}
