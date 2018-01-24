#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <tuple>

using namespace std;

const int NUMBER_OF_QUEUES = 2;
const int NUMBER_OF_CASHIERS = 2;
const long GOAL = 100;
const int SIMULATION_TIME = 20000;
const double ARRIVAL_PROBABILITY = 0.10;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;

tuple<int, long, long> run_simulation(int exercise, int queues, int cashiers, bool show_results);
vector<queue<int>> create_queues(int queues);
vector<int> create_service(int cashiers);
void iteration(int t, vector<queue<int>> &qs, int queues, int cashiers, vector<int> &cashier_service_times_remaining, int &customers_served, long &total_waiting_time, long &total_q_length);
bool random_chance(double probability);
void arrive(vector<queue<int>> &qs, int t);
int random_integer(int minimum, int maximum);
void report_results(int exercise, int queues, int cashiers, int customers_served, long total_waiting_time, long total_q_length);
void find_staff_needed(int exercise, long goal);

int main(void) {
    srand(time(NULL));

    run_simulation(0, 1, 1, true);
    run_simulation(10, NUMBER_OF_QUEUES, NUMBER_OF_QUEUES, true);
    run_simulation(11, 1, NUMBER_OF_CASHIERS, true);
    find_staff_needed(12, GOAL);

    cin.get();
    return 0;
}

tuple<int, long, long> run_simulation(int exercise, int queues, int cashiers, bool show_results) {
    vector<queue<int>> qs = create_queues(queues);
    vector<int> cashier_service_times_remaining = create_service(cashiers);
    int customers_served = 0;
    long total_waiting_time = 0;
    long total_q_length = 0;
    for (int t = 0; t < SIMULATION_TIME; t++)
        iteration(t, qs, queues, cashiers, cashier_service_times_remaining, customers_served, total_waiting_time, total_q_length);
    if (show_results)
        report_results(exercise, queues, cashiers, customers_served, total_waiting_time, total_q_length);
    return make_tuple(customers_served, total_waiting_time, total_q_length);
}

vector<queue<int>> create_queues(int queues) {
    vector<queue<int>> qs;
    for (int i = 0; i < queues; i++) {
        queue<int> q;
        qs.push_back(q);
    }
    return qs;
}

vector<int> create_service(int cashiers) {
    vector<int> cashier_service_times_remaining;
    for (int i = 0; i < cashiers; i++)
        cashier_service_times_remaining.push_back(0);
    return cashier_service_times_remaining;
}

void iteration(int t, vector<queue<int>> &qs, int queues, int cashiers, vector<int> &cashier_service_times_remaining, int &customers_served, long &total_waiting_time, long &total_q_length) {
    if (random_chance(ARRIVAL_PROBABILITY))
        arrive(qs, t);
    for (int i = 0; i < cashiers; i++) {
        if (cashier_service_times_remaining[i] > 0) {
            cashier_service_times_remaining[i]--;
            if (cashier_service_times_remaining[i] == 0)
                customers_served++;
        }
        else if (!qs[i % queues].empty()) {
            total_waiting_time += t - qs[i % queues].front();
            qs[i % queues].pop();
            cashier_service_times_remaining[i] = random_integer(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }
        total_q_length += qs[i % queues].size();
    }
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

int random_integer(int minimum, int maximum) {
    return minimum + rand() % (maximum - minimum + 1);
}

void report_results(int exercise, int queues, int cashiers, int customers_served, long total_waiting_time, long total_q_length) {
    cout << "Simulation " << exercise << " results given the following parameters : " << endl;
    cout << fixed << setprecision(2);
    cout << " SIMULATION_TIME: " << setw(8) << SIMULATION_TIME << endl;
    cout << " NUMBER_OF_QUEUES: " << setw(7) << queues << endl;
    cout << " NUMBER_OF_CASHIERS: " << setw(5) << cashiers << endl;
    cout << " ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
    cout << " MIN_SERVICE_TIME: " << setw(7) << MIN_SERVICE_TIME << endl;
    cout << " MAX_SERVICE_TIME: " << setw(7) << MAX_SERVICE_TIME << endl;
    cout << "Customers served: " << setw(8) << customers_served << endl;
    cout << "Average waiting time: " << setw(7) << double(total_waiting_time) / customers_served << endl;
    cout << "Average queue length: " << setw(7) << double(total_q_length) / SIMULATION_TIME / queues << endl;
    cout << endl;
}

void find_staff_needed(int exercise, long goal) {
    int queues = 1;
    int cashiers = 0;
    int customers_served = 1;
    long total_waiting_time = LONG_MAX;
    long total_q_length;
    while (total_waiting_time / customers_served > goal)
        tie(customers_served, total_waiting_time, total_q_length) = run_simulation(exercise, queues, ++cashiers, false);
    report_results(exercise, queues, cashiers, customers_served, total_waiting_time, total_q_length);
    cout << cashiers << " cashiers needed to get below " << GOAL << " average waiting time." << endl;
}
