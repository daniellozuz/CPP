#include <iostream>

using namespace std;

int main() {
    double celsius;

    cout << "Convert temperature from Celsius to Farenheit." << endl;
    cin >> celsius;

    cout << celsius << " Celsius is " << 9 * celsius / 5 + 32 << " Farenheit." << endl;
    getchar(); getchar(); /* Shame! */
    
    return 0;
}
