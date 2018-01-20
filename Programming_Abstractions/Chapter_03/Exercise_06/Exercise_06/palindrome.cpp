#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str);

int main(void) {
    cout << is_palindrome("boob") << endl;
    cout << is_palindrome("boon") << endl;
    cout << is_palindrome("") << endl;
    cout << is_palindrome("b") << endl;
    cout << is_palindrome("booB") << endl;

    cin.get();
    return 0;
}

bool is_palindrome(string str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (str[i] != str[length - 1 - i])
            return false;
    }
    return true;
}
