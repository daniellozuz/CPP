#include <iostream>

#define SENTINEL 0

using namespace std;

int main(void) {
    int number;
    int largest = 0;

    while (true) {
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (number == SENTINEL) break;
        largest = (number > largest) ? number : largest;
    }

    cout << "The largest value is " << largest << endl;
    
    cin.get();
    return 0;
}
