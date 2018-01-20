#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    int number_of_trials;
    double sum_of_values = 0.0;

    cout << "This program averages a series of random numbers between 0 and 1." << endl;
    cout << "How many trials: ";
    cin >> number_of_trials;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < number_of_trials; i++)
        sum_of_values += double(rand()) / RAND_MAX;

    cout << "The average value after " << number_of_trials << " trials is " << sum_of_values / number_of_trials;
    
    cin.get();
    return 0;
}
