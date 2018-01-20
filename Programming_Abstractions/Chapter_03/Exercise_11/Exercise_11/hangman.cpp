#include <iostream>
#include <string>
#include "randword.h"

using namespace std;

const string FILE_NAME = "words.txt";

void welcome(void);
void play(string word);
bool found(char letter, string word, string solution);
bool won(string solution);

int main(void) {
    string word;

    //init_dictionary(FILE_NAME.c_str());
    //word = choose_random_word();
    word = string("gowno");
    welcome();
    play(word);
    
    cin.get();
    return 0;
}

void welcome(void) {
    cout << "Welcome to Hangman!" << endl;
    cout << "I will guess a secret word. On each turn, you guess a letter.";
    cout << "If the letter is in the secret word, I will show you where it appears; ";
    cout << "if not, a part of your body gets strung up on the scaffold.";
    cout << "The object is to guess the word before you are hung.";
}

void play(string word) {
    char letter;
    int guesses_left = 8;
    string solution = "";
    for (int i = 0; i < word.length(); i++)
        solution += "-";
    while (true) {
        if (won(solution)) {
            cout << "You guessed the word: " << word << endl;
            cout << "You win.";
            break;
        }
        if (guesses_left == 0) {
            cout << "Sorry, you lost." << endl;
            cout << "The solution was: " << word << endl;
            break;
        }
        cout << "The word now looks like this: " << solution << endl;
        cout << "You have 8 guesses left." << endl;
        cout << "Guess a letter : ";
        cin >> letter;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!found(letter, word, solution))
            guesses_left--;
    }
}

bool found(char letter, string word, string solution) {
    bool found = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            found = true;
            solution[i] = word[i];
        }
    }
    return found;
}

bool won(string solution) {
    for (int i = 0; i < solution.length(); i++) {
        if (solution[i] == '-')
            return false;
    }
    return true;
}
