#include <iostream>

using namespace std;

int main() {
    double celsius, fahrenheit;

    cout << "Convert temperature from Celsius to Fahrenheit." << endl;
    cin >> celsius;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    fahrenheit = 9 * celsius / 5 + 32;

    cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit." << endl;
    
    cin.get();
    return 0;
}
