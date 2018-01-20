#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string capitalize(string str);

int main(void) {
    cout << capitalize("BOOLEAN") << endl;
    cout << capitalize("boolean") << endl;
    cout << capitalize("BOOL34N") << endl;
    
    cin.get();
    return 0;
}

string capitalize(string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}
