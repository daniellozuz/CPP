#include <iostream>

using namespace std;

int main(void) {
    int n;
    int sum = 0;

    cout << "Please enter an integer:" << endl;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 1; i < 2 * n; i += 2)
        sum += i;

    cout << "The sum of the first " << n << " odd numbers is " << sum << endl;
    
    cin.get();
    return 0;
}
