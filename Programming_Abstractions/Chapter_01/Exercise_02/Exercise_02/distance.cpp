#include <iostream>

using namespace std;

int main() {
    double meters, inches;
    int feet;

    cout << "Convert meters to feet and inches." << endl;
    cin >> meters;

    inches = meters / 0.0254;
    feet = inches / 12;
    inches -= 12 * feet;

    cout << meters << " meters is " << feet << " feet and " << inches << " inches." << endl;
    getchar(); getchar();

    return 0;
}
