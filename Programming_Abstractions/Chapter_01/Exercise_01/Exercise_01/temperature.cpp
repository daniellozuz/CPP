#include <iostream>

using namespace std;

int main() {
    double celsius, fahrenheit;

    cout << "Convert temperature from Celsius to Fahrenheit." << endl;
    cin >> celsius;

    fahrenheit = 9 * celsius / 5 + 32;

    cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit." << endl;
    getchar(); getchar(); /* Shame! */
    
    return 0;
}
