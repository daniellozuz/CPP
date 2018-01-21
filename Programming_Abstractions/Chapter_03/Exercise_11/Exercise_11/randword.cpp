#include <iostream>
#include <string>
#include <fstream>
#include "randword.h"

const string FILE_NAME = "words.txt";

static string *words;

int word_count = 0;

void init_dictionary(string file_name) {
    ifstream in_file;
    string word;
    in_file.open(FILE_NAME.c_str());
    if (in_file.fail()) {
        cout << "ERROR! Could not open " << FILE_NAME << endl;
        return;
    }
    getline(in_file, word);
    while (!in_file.fail()) {
        string *new_words = new string[word_count + 1];
        for (int i = 0; i < word_count; i++)
            new_words[i] = words[i];
        new_words[word_count++] = word;
        words = new_words;
        getline(in_file, word);
    }
}

string choose_random_word(void) {
    return words[rand() % word_count];
}
