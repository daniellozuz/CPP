#include <iostream>
#include <string>

using namespace std;

string reverse(string str);

int main(void) {
    cout << reverse("program") << endl;

    cin.get();
    return 0;
}

string reverse(string str) {
    if (str == "")
        return str;
    return reverse(str.substr(1)) + string(1, str[0]);
}
