#include <iostream>
#include <string>

using namespace std;

string encode(string str, int key);

int main(void) {
    cout << encode("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 4) << endl;
    cout << encode("This is a secret message.", 13) << endl;
    cout << encode("IBM-9000", -1) << endl;

    cin.get();
    return 0;
}

string encode(string str, int key) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] + key - 'A') % 26 + 'A';
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] + key - 'a') % 26 + 'a';
    }
    return str;
}
