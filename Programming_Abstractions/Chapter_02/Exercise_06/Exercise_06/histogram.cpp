#include <iostream>
#include <iomanip>

using namespace std;

const int HISTOGRAM_RESOLUTION = 11;

void show(int histogram[]);
void calculate_histogram(int histogram[], int numbers[], int number_count);

int main(void) {
    int exam_scores[] = { 100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80 };
    int exam_scores_count = sizeof exam_scores / sizeof exam_scores[0];
    int histogram[HISTOGRAM_RESOLUTION];
    
    calculate_histogram(histogram, exam_scores, exam_scores_count);
    show(histogram);

    cin.get();
    return 0;
}

void show(int histogram[]) {
    for (int i = 0; i < HISTOGRAM_RESOLUTION; i++) {
        cout << setw(3) << 10 * i << ": ";
        for (int j = 0; j < histogram[i]; j++)
            cout << "*";
        cout << endl;
    }
}

void calculate_histogram(int histogram[], int numbers[], int number_count) {
    for (int i = 0; i < HISTOGRAM_RESOLUTION; i++)
        histogram[i] = 0;
    for (int i = 0; i < number_count; i++)
        histogram[numbers[i] / 10]++;
}
