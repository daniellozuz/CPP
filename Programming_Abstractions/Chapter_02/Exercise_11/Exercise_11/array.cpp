#include <iostream>

using namespace std;

const int SIZE = 10;

int *index_array(int size);
void show(int numbers[], int number_count);

int main(void) {
    int *ip;
    
    ip = index_array(SIZE);
    show(ip, SIZE);

    cin.get();
    return 0;
}

int *index_array(int size) {
    int *new_array = new int[size];
    for (int i = 0; i < size; i++)
        new_array[i] = i;
    return new_array;
}

void show(int numbers[], int number_count) {
    for (int i = 0; i < number_count; i++)
        cout << numbers[i] << endl;
}
