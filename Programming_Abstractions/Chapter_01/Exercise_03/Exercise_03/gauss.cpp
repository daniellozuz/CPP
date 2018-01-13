#include <iostream>

#define START 1
#define END 100

using namespace std;

int main(void) {
    cout << "The sum of numbers between " << START << " and " << END;
    cout << " equals " << (START + END) * (END - START + 1) / 2 << endl;
    
    cin.get();
    return 0;
}
