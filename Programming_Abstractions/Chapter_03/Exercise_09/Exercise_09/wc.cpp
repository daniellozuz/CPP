#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int calc_lines(string file_name);
int calc_words(string file_name);
int calc_chars(string file_name);

int main(void) {
    int lines, words, chars;
    string file_name = "twinkle.txt";

    lines = calc_lines(file_name);
    words = calc_words(file_name);
    chars = calc_chars(file_name);

    cout << "File: " << file_name << endl;
    cout << "Lines: " << setw(4) << lines << endl;
    cout << "Words: " << setw(4) << words << endl;
    cout << "Chars: " << setw(4) << chars << endl;

    cin.get();
    return 0;
}

int calc_lines(string file_name) {
    char ch;
    int lines = 0;
    ifstream in_file;
    in_file.open(file_name.c_str());
    if (in_file.fail())
        cout << "ERROR! Could not open " << file_name << endl;
    while ((ch = in_file.get()) != EOF) {
        if (ch == '\n')
            lines++;
    }
    in_file.close();
    return lines;
}

int calc_words(string file_name) {
    char ch, next_ch;
    int words = 0;
    ifstream in_file;
    in_file.open(file_name.c_str());
    if (in_file.fail())
        cout << "ERROR! Could not open " << file_name << endl;
    while ((ch = in_file.get()) != EOF) {
        next_ch = in_file.get();
        in_file.unget();
        if (!isspace(ch) && isspace(next_ch))
            words++;
    }
    in_file.close();
    return words;
}

int calc_chars(string file_name) {
    char ch;
    int chars = 0;
    ifstream in_file;
    in_file.open(file_name.c_str());
    if (in_file.fail())
        cout << "ERROR! Could not open " << file_name << endl;
    while ((ch = in_file.get()) != EOF)
        chars++;
    in_file.close();
    return chars;
}
