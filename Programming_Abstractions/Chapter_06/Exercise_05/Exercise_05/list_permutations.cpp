#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void list_permutations(string str);
void recursive_permute_helper(string prefix, string rest);

int main(void) {
    list_permutations("ABAB");

    cin.get();
    return 0;
}

void list_permutations(string str) {
    sort(str.begin(), str.end());
    recursive_permute_helper("", str);
}

void recursive_permute_helper(string prefix, string rest) {
    if (rest == "")
        cout << prefix << endl;
    for (int i = 0; i < rest.length(); i++) {
        if (i == 0 || rest[i] != rest[i - 1])
            recursive_permute_helper(prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1));
    }
}
