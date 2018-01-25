#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 25;

void simulate(vector<vector<bool>> &mousetraps);
void iteration(vector<vector<bool>> &mousetraps, vector<int> &balls_airborne_times_remaining);
void decrement_time(vector<int> &balls_airborne_times_remaining);
void remove_fallen(vector<int> &balls_airborne_times_remaining);
double get_released_percentage(vector<vector<bool>> &mousetraps);
void show(vector<vector<bool>> &mousetraps);
void show(vector<int> &balls_airborne_times_remaining);
void show_report(int time_elapsed, int max_balls_airborne, double released_percentage);

int main(void) {
    vector<vector<bool>> mousetraps(SIZE, vector<bool>(SIZE, true));

    simulate(mousetraps);

    cin.get();
    return 0;
}

void simulate(vector<vector<bool>> &mousetraps) {
    vector<int> balls_airborne_times_remaining = { 1 };
    int time_elapsed = 0;
    int max_balls_airborne = 0;
    show(balls_airborne_times_remaining);
    show(mousetraps);
    while (!balls_airborne_times_remaining.empty()) {
        iteration(mousetraps, balls_airborne_times_remaining);
        max_balls_airborne = max(max_balls_airborne, int(balls_airborne_times_remaining.size()));
        show(balls_airborne_times_remaining);
        show(mousetraps);
        time_elapsed++;
    }
    show_report(time_elapsed, max_balls_airborne, get_released_percentage(mousetraps));
}

void iteration(vector<vector<bool>> &mousetraps, vector<int> &balls_airborne_times_remaining) {
    decrement_time(balls_airborne_times_remaining);
    for (int i = 0; i < balls_airborne_times_remaining.size(); i++) {
        if (balls_airborne_times_remaining[i] == 0) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            if (mousetraps[x][y]) {
                balls_airborne_times_remaining.push_back(rand() % 4 + 1);
                balls_airborne_times_remaining.push_back(rand() % 4 + 1);
                mousetraps[x][y] = false;
            }
        }
    }
    remove_fallen(balls_airborne_times_remaining);
}

void decrement_time(vector<int> &balls_airborne_times_remaining) {
    for (int i = 0; i < balls_airborne_times_remaining.size(); i++)
        balls_airborne_times_remaining[i]--;
}

void remove_fallen(vector<int> &balls_airborne_times_remaining) {
    for (int i = balls_airborne_times_remaining.size() - 1; i >= 0; i--) {
        if (balls_airborne_times_remaining[i] == 0)
            balls_airborne_times_remaining.erase(balls_airborne_times_remaining.begin() + i);
    }
}

double get_released_percentage(vector<vector<bool>> &mousetraps) {
    int released = 0;
    int total = 0;
    for (int i = 0; i < mousetraps.size(); i++) {
        for (int j = 0; j < mousetraps[i].size(); j++) {
            if (!mousetraps[i][j])
                released++;
            total++;
        }
    }
    return double(released) / total;
}

void show(vector<vector<bool>> &mousetraps) {
    cout << "Mousetraps in a box (1 - loaded; 0 - released):" << endl;
    for (int i = 0; i < mousetraps.size(); i++) {
        for (int j = 0; j < mousetraps[i].size(); j++)
            cout << mousetraps[i][j] << " ";
        cout << endl;
    }
}

void show(vector<int> &balls_airborne_times_remaining) {
    cout << "Balls airborne (numbers indicate times in the air left)." << endl;
    cout << "[";
    for (int i = 0; i < balls_airborne_times_remaining.size(); i++)
        cout << balls_airborne_times_remaining[i] << ", ";
    cout << "]" << endl;
}

void show_report(int time_elapsed, int max_balls_airborne, double released_percentage) {
    cout << "REPORT" << endl;
    cout << "Time elapsed: " << time_elapsed << endl;
    cout << "Maximum number of balls in the air: " << max_balls_airborne << endl;
    cout << "Percentage of traps released: " << 100 * released_percentage << endl;
}
