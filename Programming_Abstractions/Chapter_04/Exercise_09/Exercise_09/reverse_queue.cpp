#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const string S1 = "And the first one now";
const string S2 = "Will later be last";
const string S3 = "For the times they are a - changin";

void reverse_queue(queue<string> &q);
void show(queue<string> &q);

int main(void) {
    queue<string> q;
    q.push(S1);
    q.push(S2);
    q.push(S3);
    
    show(q);
    reverse_queue(q);
    show(q);

    cin.get();
    return 0;
}

void reverse_queue(queue<string> &q) {
    stack<string> temp_stack;
    while (!q.empty()) {
        temp_stack.push(q.front());
        q.pop();
    }
    while (!temp_stack.empty()) {
        q.push(temp_stack.top());
        temp_stack.pop();
    }
}

void show(queue<string> &q) {
    queue<string> new_q;
    cout << "[";
    while (!q.empty()) {
        new_q.push(q.front());
        cout << q.front() << ", ";
        q.pop();
    }
    cout << "]" << endl;
    new_q.swap(q);
}
