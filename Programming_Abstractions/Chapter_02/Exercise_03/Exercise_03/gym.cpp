#include <iostream>

using namespace std;

const int MAX_JUDGES = 100;
const double MIN_SCORE = 0.0;
const double MAX_SCORE = 10.0;

void read_all_scores(double scores[], int number_of_judges);
double get_score(int judge);
void discard_biased_judges(double scores[], int &number_of_judges);
double mean(double array[], int n);

int main() {
    double scores[MAX_JUDGES];
    int number_of_judges;

    cout << "Enter number of judges (at least 3): ";
    cin >> number_of_judges;
    if (number_of_judges > MAX_JUDGES)
        cout << "Too many judges, provide less than " << MAX_JUDGES;

    read_all_scores(scores, number_of_judges);
    discard_biased_judges(scores, number_of_judges);
    cout << "The average score is " << mean(scores, number_of_judges) << endl;
    
    cin.get();
    return 0;
}

void read_all_scores(double scores[], int number_of_judges) {
    for (int i = 0; i < number_of_judges; i++)
        scores[i] = get_score(i + 1);
}

double get_score(int judge) {
    double score;
    while (true) {
        cout << "Score for judge #" << judge << ": ";
        cin >> score;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (score >= MIN_SCORE && score <= MAX_SCORE)
            return score;
        cout << "That score is out of range. Try again." << endl;
    }
}

void discard_biased_judges(double scores[], int &number_of_judges) {
    int lowest = 10;
    int highest = 0;
    for (int i = 0; i < number_of_judges; i++) {
        if (scores[i] > highest)
            highest = scores[i];
        if (scores[i] < lowest)
            lowest = scores[i];
    }
    for (int i = 0; i < number_of_judges; i++) {
        if (scores[i] == highest) {
            for (int j = i; j < number_of_judges - 1; j++)
                scores[j] = scores[j + 1];
            break;
        }
    }
    number_of_judges--;
    for (int i = 0; i < number_of_judges; i++) {
        if (scores[i] == lowest) {
            for (int j = i; j < number_of_judges - 1; j++)
                scores[j] = scores[j + 1];
            break;
        }
    }
    number_of_judges--;
}

double mean(double array[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total += array[i];
    return total / n;
}
