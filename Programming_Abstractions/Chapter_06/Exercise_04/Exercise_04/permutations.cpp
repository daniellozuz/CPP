#include <iostream>
#include <string>

using namespace std;

void recursive_permute(string str, int start);
void recursive_permute_helper(string prefix, string rest);

int main(void) {
    recursive_permute("ABCD", 2);

    cin.get();
    return 0;
}

void recursive_permute(string str, int start) {
    recursive_permute_helper(str.substr(0, start), str.substr(start));
}

void recursive_permute_helper(string prefix, string rest) {
    if (rest == "")
        cout << prefix << endl;
    for (int i = 0; i < rest.length(); i++)
        recursive_permute_helper(prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1));
}
