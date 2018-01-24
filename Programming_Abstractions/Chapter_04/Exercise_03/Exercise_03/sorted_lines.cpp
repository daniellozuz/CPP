#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string FILE_NAME = "text.txt";

void sort_text_file(ifstream &in_file, vector<string> &lines);
void insert(vector<string> &lines, string line);
void show(vector<string> &lines);

int main(void) {
    vector<string> lines;
    ifstream in_file;

    in_file.open(FILE_NAME.c_str());
    if (!in_file.fail())
        sort_text_file(in_file, lines);
    show(lines);

    cin.get();
    return 0;
}

void sort_text_file(ifstream &in_file, vector<string> &lines) {
    string line;
    getline(in_file, line);
    while (!in_file.fail()) {
        insert(lines, line);
        getline(in_file, line);
    }
}

void insert(vector<string> &lines, string line) {
    for (int i = 0; i < lines.size(); i++) {
        if (line < lines[i]) {
            lines.insert(lines.begin() + i, line);
            return;
        }
    }
    lines.insert(lines.begin() + lines.size(), line);
}

void show(vector<string> &lines) {
    for (string line : lines)
        cout << line << endl;
}
