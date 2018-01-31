#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const string FILE_NAME = "words.txt";

const map<char, string> KEYPAD = {
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" },
};

void load(vector<string> &words);
void list_mnemonic_words(string numbers);
void list_mnemonic_words_helper(string prefix, string rest, vector<string> &words);
void display_words_only(string prefix, vector<string> &words);

int main(void) {
    list_mnemonic_words("723");

    cin.get();
    return 0;
}

void list_mnemonic_words(string numbers) {
    vector<string> words;
    load(words);
    list_mnemonic_words_helper("", numbers, words);
}

void list_mnemonic_words_helper(string prefix, string rest, vector<string> &words) {
    if (rest == "")
        display_words_only(prefix, words);
    else {
        for (int i = 0; i < KEYPAD.at(rest[0]).length(); i++)
            list_mnemonic_words_helper(prefix + KEYPAD.at(rest[0])[i], rest.substr(1), words);
    }
}

void display_words_only(string prefix, vector<string> &words) {
    if (binary_search(words.begin(), words.end(), prefix))
        cout << prefix << endl;
}

void load(vector<string> &words) {
    ifstream in_file;
    string line;
    in_file.open(FILE_NAME.c_str());
    while (getline(in_file, line))
        words.push_back(line);
    in_file.close();
}
