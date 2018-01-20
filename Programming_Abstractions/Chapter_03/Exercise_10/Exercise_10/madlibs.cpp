#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string OUT_FILE_NAME = "result.txt";

void play_madlibs(ifstream &in_file, ofstream &out_file);
void show_file_contents(string file_name);

int main(void) {
    string file_name;
    ifstream in_file;
    ofstream out_file;

    cout << "Input file: ";
    getline(cin, file_name);

    in_file.open(file_name.c_str());
    if (in_file.fail())
        cout << "ERROR! Cannot open " << file_name;
    else{
        out_file.open(OUT_FILE_NAME.c_str());
        if (out_file.fail())
            cout << "ERROR! Cannot open " << OUT_FILE_NAME;
        else {
            play_madlibs(in_file, out_file);
            in_file.close();
            out_file.close();
            show_file_contents(OUT_FILE_NAME);
        }
    }
    
    cin.get();
    return 0;
}

void show_file_contents(string file_name) {
    ifstream in_file;
    char ch;
    in_file.open(file_name.c_str());
    if (in_file.fail())
        cout << "ERROR! Cannot open " << file_name;
    while ((ch = in_file.get()) != EOF)
        cout << ch;
    in_file.close();
}

void play_madlibs(ifstream &in_file, ofstream &out_file) {
    char ch;
    string buffer;
    while ((ch = in_file.get()) != EOF) {
        if (ch == '<') {
            cout << "\t";
            while ((ch = in_file.get()) != '>')
                cout << ch;
            cout << ": ";
            getline(cin, buffer);
            for (int i = 0; i < buffer.length(); i++)
                out_file.put(buffer[i]);
        }
        else
            out_file.put(ch);
    }
}
