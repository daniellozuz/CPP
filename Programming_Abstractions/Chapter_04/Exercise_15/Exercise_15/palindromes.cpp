#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILE_NAME = "words.txt";

bool is_palindrome(string str);

int main(void) {
    ifstream in_file;
    string word;

    in_file.open(FILE_NAME.c_str());
    
    while (getline(in_file, word)) {
        if (is_palindrome(word))
            cout << word << endl;
    }

    in_file.close();

    cin.get();
    return 0;
}

bool is_palindrome(string str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (str[i] != str[length - i - 1])
            return false;
    }
    return true;
}
