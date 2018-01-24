#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string FILE_NAME = "numbers.txt";

bool read_vector(ifstream &in_file, vector<double> &vec);
void show(vector<double> &vec);

int main(void) {
    vector<double> numbers;
    ifstream in_file;

    in_file.open(FILE_NAME.c_str());
    if (!in_file.fail()) {
        while (read_vector(in_file, numbers))
            show(numbers);
    }
    else
        cout << "Could not open " << FILE_NAME << endl;

    cin.get();
    return 0;
}

bool read_vector(ifstream &in_file, vector<double> &vec) {
    string line;
    vec.clear();
    getline(in_file, line);
    if (in_file.fail())
        return false;
    while (!in_file.fail() && line != "") {
        vec.push_back(stod(line));
        getline(in_file, line);
    }
    return true;
}

void show(vector<double> &vec) {
    cout << "[";
    for (int number : vec)
        cout << number << ", ";
    cout << "]" << endl;
}
