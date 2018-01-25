#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<string, string> LETTERS_TO_MORSE{
    { "A", ".-" },
    { "B", "-..." },
    { "C", "-.-." },
    { "D", "-.." },
    { "E", "." },
    { "F", "..-." },
    { "G", "--." },
    { "H", "...." },
    { "I", ".." },
    { "J", ".---" },
    { "K", "-.-" },
    { "L", ".-.." },
    { "M", "--" },
    { "N", "-." },
    { "O", "---" },
    { "P", ".--." },
    { "Q", "--.-" },
    { "R", ".-." },
    { "S", "..." },
    { "T", "-" },
    { "U", "..-" },
    { "V", "...-" },
    { "W", ".--" },
    { "X", "-..-" },
    { "Y", "-.--" },
    { "Z", "--.." },
};

const map<string, string> MORSE_TO_LETTERS{
    { ".-", "A" },
    { "-...", "B" },
    { "-.-.", "C" },
    { "-..", "D" },
    { ".", "E" },
    { "..-.", "F" },
    { "--.", "G" },
    { "....", "H" },
    { "..", "I" },
    { ".---", "J" },
    { "-.-", "K" },
    { ".-..", "L" },
    { "--", "M" },
    { "-.", "N" },
    { "---", "O" },
    { ".--.", "P" },
    { "--.-", "Q" },
    { ".-.", "R" },
    { "...", "S" },
    { "-", "T" },
    { "..-", "U" },
    { "...-", "V" },
    { ".--", "W" },
    { "-..-", "X" },
    { "-.--", "Y" },
    { "--..", "Z" },
};

string translate(string line);

int main(void) {
    string line;

    getline(cin, line);
    while (line != "") {
        cout << translate(line) << endl;
        getline(cin, line);
    }

    cin.get();
    return 0;
}

string translate(string line) {
    line += " ";
    string result = "";
    string temp = "";
    if (line[0] == '-' || line[0] == '.') {
        for (char ch : line) {
            if (ch == '-' || ch == '.')
                temp.push_back(ch);
            else {
                if (!temp.empty()) {
                    result += MORSE_TO_LETTERS.at(temp);
                    temp.clear();
                }
            }
        }
    }
    else {
        for (char ch : line) {
            if (ch >= 'A' && ch < 'Z')
                result += LETTERS_TO_MORSE.at(string(1, ch)) + " ";
        }
    }
    return result;
}
