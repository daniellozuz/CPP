#include <iostream>

#define PRECISION 100

using namespace std;

int main(void) {
    double area = 0.0;
    double width = 2.0 / PRECISION;
    
    for (int i = 0; i < PRECISION; i++)
        area += width * sqrt(2 * 2 - i * i * width * width);
    
    cout << "Approximation of pi equals " << area << endl;

    cin.get();
    return 0;
}
