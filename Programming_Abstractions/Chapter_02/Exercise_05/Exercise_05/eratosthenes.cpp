#include <iostream>

using namespace std;

const int LIMIT = 1000;

void show(int numbers[], int numbers_count);
void sieve(int numbers[], int &numbers_count);
void remove_number(int numbers[], int numbers_count, int index);

int main(void) {
    int numbers[LIMIT - 1];
    int numbers_count = LIMIT - 1;

    for (int i = 0; i < LIMIT - 1; i++)
        numbers[i] = i + 2;

    sieve(numbers, numbers_count);
    show(numbers, numbers_count);

    cin.get();
    return 0;
}

void show(int numbers[], int numbers_count) {
    for (int i = 0; i < numbers_count; i++)
        cout << numbers[i] << endl;
}

void sieve(int numbers[], int &numbers_count) {
    for (int primes_found = 1; primes_found < numbers_count; primes_found++) {
        for (int i = primes_found; i < numbers_count; i++) {
            if (numbers[i] % numbers[primes_found - 1] == 0)
                remove_number(numbers, numbers_count--, i--);
        }
    }
}

void remove_number(int numbers[], int numbers_count, int index) {
    for (int i = index; i < numbers_count - 1; i++)
        numbers[i] = numbers[i + 1];
}
