#include <iostream>

using namespace std;

bool is_measurable(int target, int weights[], int n_weights);

int main(void) {
    int sample_weights[] = { 1, 3 };
    int n_sample_weights = 2;

    cout << is_measurable(2, sample_weights, n_sample_weights) << endl;
    cout << is_measurable(5, sample_weights, n_sample_weights) << endl;

    cin.get();
    return 0;
}

bool is_measurable(int target, int weights[], int n_weights) {
    if (target == 0)
        return true;
    if (n_weights == 0)
        return false;
    return is_measurable(target, weights, n_weights - 1) ||
        is_measurable(target + weights[n_weights - 1], weights, n_weights - 1) ||
        is_measurable(target - weights[n_weights - 1], weights, n_weights - 1);
}
