#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

const string FILE_NAME = "macbeth.txt";

void create_frequency_table(ifstream &in_file, map<string, int> &word_counts);
vector<string> split(string &line);
void convert_to_lower_case(string &word);
bool is_all_alpha(string &str);
void display_word_counts(map<string, int> &word_counts);

int main(void) {
    ifstream in_file;
    map<string, int> word_counts;

    in_file.open(FILE_NAME.c_str());
    
    create_frequency_table(in_file, word_counts);
    
    in_file.close();

    display_word_counts(word_counts);

    cin.get();
    return 0;
}

void create_frequency_table(ifstream &in_file, map<string, int> &word_counts) {
    string line;
    while (getline(in_file, line)) {
        for (string word : split(line)) {
            convert_to_lower_case(word);
            if (is_all_alpha(word)) {
                if (word_counts.find(word) == word_counts.end())
                    word_counts[word] = 1;
                else
                    word_counts[word]++;
            }
        }
    }
}

vector<string> split(string &line) {
    vector<string> result;
    string temp;
    line += " ";
    for (char ch : line) {
        if (ch != ' ')
            temp.push_back(ch);
        else {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        }
    }
    return result;
}

void convert_to_lower_case(string &word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] += 'a' - 'A';
    }
}

bool is_all_alpha(string &str) {
    for (char ch : str) {
        if (!isalpha(ch))
            return false;
    }
    return true;
}

void display_word_counts(map<string, int> &word_counts) {
    for (const auto &p : word_counts)
        cout << left << setw(15) << p.first << right << setw(5) << p.second << endl;
}
