#include <iostream>

using namespace std;

int cannonball(unsigned int height);

int main(void) {
    for (unsigned int i = 0; i < 5; i++)
        cout << cannonball(i) << endl;

    cin.get();
    return 0;
}

int cannonball(unsigned int height) {
    if (height == 0)
        return 0;
    return height * height + cannonball(height - 1);
}
