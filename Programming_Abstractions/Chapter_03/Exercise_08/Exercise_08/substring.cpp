#include <iostream>
#include <string>

using namespace std;

string substring(string str, int pos, int len);

int main(void) {
    cout << substring("Daniel", 2, 2) << endl;
    cout << substring("Daniel", 0, 2) << endl;
    cout << substring("Daniel", 2, 0) << endl;
    cout << substring("Daniel", 2, -2) << endl;
    cout << substring("Daniel", -2, 2) << endl;
    cout << substring("Daniel", 2, 9) << endl;

    cin.get();
    return 0;
}

string substring(string str, int pos, int len) {
    string new_str = "";
    if (len < 0)
        len = 0;
    if (pos < 0)
        pos = 0;
    if (len > str.length() - pos)
        len = str.length() - pos;
    if (pos > str.length() - 1)
        return new_str;
    for (int i = pos; i < pos + len; i++)
        new_str += str[i];
    return new_str;
}
