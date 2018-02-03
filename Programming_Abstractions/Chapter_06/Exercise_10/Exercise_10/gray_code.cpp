#include <iostream>
#include <vector>

using namespace std;

void generate_gray_code(int n_bits);
vector<vector<int>> recursive_gray_code_helper(int n_bits);
void show(vector<vector<int>> gray_code);

int main(void) {
    generate_gray_code(3);

    cin.get();
    return 0;
}

void generate_gray_code(int n_bits) {
    vector<vector<int>> gray_code = recursive_gray_code_helper(n_bits);
    show(gray_code);
}

vector<vector<int>> recursive_gray_code_helper(int n_bits) {
    if (n_bits == 0)
        return { {} };
    vector<vector<int>> gray_code;
    vector<vector<int>> part1 = recursive_gray_code_helper(n_bits - 1);
    for (int i = 0; i < part1.size(); i++) {
        vector<int> sth = part1[i];
        sth.insert(sth.begin(), 0);
        gray_code.push_back(sth);
    }
    vector<vector<int>> part2 = recursive_gray_code_helper(n_bits - 1);
    for (int i = part2.size() - 1; i >= 0; i--) {
        vector<int> sth = part2[i];
        sth.insert(sth.begin(), 1);
        gray_code.push_back(sth);
    }
    return gray_code;
}

void show(vector<vector<int>> gray_code) {
    for (vector<int> vec : gray_code) {
        for (int number : vec)
            cout << number << " ";
        cout << endl;
    }
}
