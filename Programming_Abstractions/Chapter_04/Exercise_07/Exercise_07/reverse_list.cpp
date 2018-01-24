#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int number;
    stack<int> numbers;

    cout << "Enter a list of integers, ending with 0:" << endl;
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (number != 0) {
        numbers.push(number);
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Those integers in reverse order are:" << endl;
    while (!numbers.empty()) {
        cout << numbers.top() << endl;
        numbers.pop();
    }

    cin.get();
    return 0;
}
