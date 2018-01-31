#include <iostream>
#include <string>

using namespace std;

void list_permutations(string str);
void recursive_permute_helper(string prefix, string rest);

int main(void) {
    list_permutations("ABC");

    cin.get();
    return 0;
}

void list_permutations(string str) {
    recursive_permute_helper("", str);
}

void recursive_permute_helper(string prefix, string rest) {
    if (rest == "")
        cout << "{" << prefix << "}" << endl;
    else {
        recursive_permute_helper(prefix + rest[0], rest.substr(1));
        recursive_permute_helper(prefix, rest.substr(1));
    }
}
