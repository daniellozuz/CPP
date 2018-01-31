#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generate_gray_code(int n_bits);
vector<int> recursive_permute_helper(string prefix, int n_bits);

int main(void) {
    generate_gray_code(3);

    cin.get();
    return 0;
}

void generate_gray_code(int n_bits) {
    recursive_permute_helper("", n_bits);
}

vector<int> recursive_permute_helper(string prefix, int n_bits) {
    if (n_bits == 0) {
        cout << prefix << endl;
    }
    for (int i = 0; i < recursive_permute_helper('0' + prefix, n_bits - 1).size(); i++) {

    }
    for(string suffix : recursive_permute_helper('0' + prefix, n_bits - 1))
    


}
