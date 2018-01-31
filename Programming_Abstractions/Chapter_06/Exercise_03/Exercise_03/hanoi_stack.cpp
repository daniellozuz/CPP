#include <iostream>
#include <stack>

using namespace std;

struct task_t {
    int n_disks;
    char start;
    char finish;
    char temp;
};

void move_disk(char start, char finish);

int main(void) {
    stack<task_t> tasks;
    tasks.push(task_t{ 3, 'A', 'B', 'C' });

    while (!tasks.empty()) {
        task_t task = tasks.top();
        tasks.pop();
        if (task.n_disks != 1) {
            tasks.push(task_t{ task.n_disks - 1, task.temp, task.finish, task.start });
            tasks.push(task_t{ 1, task.start, task.finish, task.temp });
            tasks.push(task_t{ task.n_disks - 1, task.start, task.temp, task.finish });
        }
        else
            move_disk(task.start, task.finish);
    }

    cin.get();
    return 0;
}

void move_disk(char start, char finish) {
    cout << start << " -> " << finish << endl;
}
