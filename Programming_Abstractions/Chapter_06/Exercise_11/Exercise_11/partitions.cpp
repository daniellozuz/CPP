#include <iostream>

using namespace std;

int number_of_partitions(int numbers[], int length, int target);

int main(void) {
    int sample_set[] = { 1, 3, 4, 5 };
    
    cout << number_of_partitions(sample_set, 4, 5) << endl;
    cout << number_of_partitions(sample_set, 4, 11) << endl;

    cin.get();
    return 0;
}

int number_of_partitions(int numbers[], int length, int target) {
    if (target == 0)
        return 1;
    if (length == 0)
        return 0;
    return number_of_partitions(numbers, length - 1, target - numbers[length - 1]) + number_of_partitions(numbers, length - 1, target);
}
