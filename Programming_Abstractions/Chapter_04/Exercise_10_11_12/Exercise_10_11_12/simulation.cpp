#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>

using namespace std;

const int NUMBER_OF_QUEUES = 2;
const int NUMBER_OF_CASHIERS = 2;
const long GOAL = 100;
const int SIMULATION_TIME = 20000;
const double ARRIVAL_PROBABILITY = 0.10;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;

struct results_t {
    int n_served;
    long total_waiting_time;
    long total_q_length;
};

results_t run_simulation(int n_exercise, int n_queues, int n_cashiers, bool show_results);
void simulate_staff_needed(int n_exercise, long goal);
void report_results(int exercise_number, int n_queues, int n_cashiers, int n_served, long total_waiting_time, long total_q_length);
int random_integer(int minimum, int maximum);
bool random_chance(double probability);
void arrive(vector<queue<int>> &qs, int t);

int main(void) {
    srand(time(NULL));

    run_simulation(0, 1, 1, true);
    run_simulation(10, NUMBER_OF_QUEUES, NUMBER_OF_QUEUES, true);
    run_simulation(11, 1, NUMBER_OF_CASHIERS, true);
    simulate_staff_needed(12, GOAL);

    cin.get();
    return 0;
}

results_t run_simulation(int n_exercise, int n_queues, int n_cashiers, bool show_results) {
    vector<queue<int>> qs;
    for (int i = 0; i < n_queues; i++) {
        queue<int> q;
        qs.push_back(q);
    }
    vector<int> service_times_remaining;
    for (int i = 0; i < n_cashiers; i++)
        service_times_remaining.push_back(0);
    int n_served = 0;
    long total_waiting_time = 0;
    long total_q_length = 0;
    for (int t = 0; t < SIMULATION_TIME; t++) {
        if (random_chance(ARRIVAL_PROBABILITY))
            arrive(qs, t);
        for (int i = 0; i < n_cashiers; i++) {
            if (service_times_remaining[i] > 0) {
                service_times_remaining[i]--;
                if (service_times_remaining[i] == 0)
                    n_served++;
            }
            else if (!qs[i % n_queues].empty()) {
                total_waiting_time += t - qs[i % n_queues].front();
                qs[i % n_queues].pop();
                service_times_remaining[i] = random_integer(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
            }
            total_q_length += qs[i % n_queues].size();
        }
    }
    if (show_results)
        report_results(n_exercise, n_queues, n_cashiers, n_served, total_waiting_time, total_q_length);
    results_t results;
    results.n_served = n_served;
    results.total_waiting_time = total_waiting_time;
    results.total_q_length = total_q_length;
    return results;
}

void simulate_staff_needed(int n_exercise, long goal) {
    int n_queues = 1;
    int n_cashiers = 0;
    int n_served = 1;
    long total_waiting_time = LONG_MAX;
    long total_q_length;
    while (total_waiting_time / n_served > goal) {
        n_cashiers++;
        results_t results = run_simulation(n_exercise, n_queues, n_cashiers, false);
        n_served = results.n_served;
        total_waiting_time = results.total_waiting_time;
        total_q_length = results.total_q_length;
    }
    report_results(n_exercise, n_queues, n_cashiers, n_served, total_waiting_time, total_q_length);
    cout << n_cashiers << " cashiers needed to get below " << GOAL << " average waiting time." << endl;
}

void report_results(int exercise_number, int n_queues, int n_cashiers, int n_served, long total_waiting_time, long total_q_length) {
    cout << "Simulation " << exercise_number << " results given the following parameters : " << endl;
    cout << fixed << setprecision(2);
    cout << " SIMULATION_TIME: " << setw(8) << SIMULATION_TIME << endl;
    cout << " NUMBER_OF_QUEUES: " << setw(7) << n_queues << endl;
    cout << " NUMBER_OF_CASHIERS: " << setw(5) << n_cashiers << endl;
    cout << " ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
    cout << " MIN_SERVICE_TIME: " << setw(7) << MIN_SERVICE_TIME << endl;
    cout << " MAX_SERVICE_TIME: " << setw(7) << MAX_SERVICE_TIME << endl;
    cout << "Customers served: " << setw(8) << n_served << endl;
    cout << "Average waiting time: " << setw(7) << double(total_waiting_time) / n_served << endl;
    cout << "Average queue length: " << setw(7) << double(total_q_length) / SIMULATION_TIME / n_queues << endl;
    cout << endl;
}

int random_integer(int minimum, int maximum) {
    return minimum + rand() % (maximum - minimum + 1);
}

bool random_chance(double probability) {
    return (double(rand()) / RAND_MAX) < probability;
}

void arrive(vector<queue<int>> &qs, int t) {
    int shortest_index = 0;
    long shortest_length = LONG_MAX;
    for (int i = 0; i < qs.size(); i++) {
        if (qs[i].size() < shortest_length) {
            shortest_length = qs[i].size();
            shortest_index = i;
        }
    }
    qs[shortest_index].push(t);
}
