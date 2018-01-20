#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool equal_ignoring_case(string str1, string str2);

int main(void) {
    cout << equal_ignoring_case("Dupa", "Dup") << endl;
    cout << equal_ignoring_case("Du!a", "Du!a") << endl;
    cout << equal_ignoring_case("", "") << endl;
    cout << equal_ignoring_case("Dupa", "") << endl;

    cin.get();
    return 0;
}

bool equal_ignoring_case(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    for (int i = 0; i < str1.length(); i++) {
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;
    }
    return true;
}
