#include <iostream>
#include <iomanip>

using namespace std;

int Round(double number);

int main(void) {
    double n1 = 8.675;
    double n2 = 0.175;
    double n3 = -1.675;
    double n4 = 0.0;
    double n5 = 0.5;
    double n6 = 1.5;

    cout << setw(6) << n1 << " after rounding is: " << Round(n1) << endl;
    cout << setw(6) << n2 << " after rounding is: " << Round(n2) << endl;
    cout << setw(6) << n3 << " after rounding is: " << Round(n3) << endl;
    cout << setw(6) << n4 << " after rounding is: " << Round(n4) << endl;
    cout << setw(6) << n5 << " after rounding is: " << Round(n5) << endl;
    cout << setw(6) << n6 << " after rounding is: " << Round(n6) << endl;

    cin.get();
    return 0;
}

int Round(double number) {
    if (number > 0)
        return int(number + 0.5);
    return int(number - 0.5);
}
