#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<char, string> KEYPAD = {
    { '2', "ABC" },
    { '3', "DEF" },
    { '4', "GHI" },
    { '5', "JKL" },
    { '6', "MNO" },
    { '7', "PQRS" },
    { '8', "TUV" },
    { '9', "WXYZ" },
};

void list_mnemonics(string numbers);
void list_mnemonics_helper(string prefix, string rest);

int main(void) {
    list_mnemonics("723");

    cin.get();
    return 0;
}

void list_mnemonics(string numbers) {
    list_mnemonics_helper("", numbers);
}

void list_mnemonics_helper(string prefix, string rest) {
    if (rest == "")
        cout << prefix << endl;
    else {
        for (int i = 0; i < KEYPAD.at(rest[0]).length(); i++)
            list_mnemonics_helper(prefix + KEYPAD.at(rest[0])[i], rest.substr(1));
    }
}
