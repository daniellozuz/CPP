#include <iostream>
#include <string>

using namespace std;

void generate_binary_code(int n_bits);
void recursive_permute_helper(string prefix, int n_bits);

int main(void) {
    generate_binary_code(3);

    cin.get();
    return 0;
}

void generate_binary_code(int n_bits) {
    recursive_permute_helper("", n_bits);
}

void recursive_permute_helper(string prefix, int n_bits) {
    if (n_bits) {
        recursive_permute_helper(prefix + '0', n_bits - 1);
        recursive_permute_helper(prefix + '1', n_bits - 1);
    }
    else
        cout << prefix << endl;
}
