#include <iostream>

#define LIMIT 10000

using namespace std;

int main(void) {
    double result = 0.0;

    for (int i = 1; i <= LIMIT; i++) {
        if (i % 2 == 1)
            result += 1.0 / (2 * i - 1);
        else
            result -= 1.0 / (2 * i - 1);
    }

    cout << "The approximation of pi equals " << 4 * result << endl;

    cin.get();
    return 0;
}
