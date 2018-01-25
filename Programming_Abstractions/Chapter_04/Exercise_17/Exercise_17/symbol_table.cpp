#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

void list(map<string, string> &symbol_table);
bool is_assignment(string &line);
void assign(map<string, string> &symbol_table, string &line);
bool is_display_request(string &line);
void display(map<string, string> &symbol_table, string &line);

int main(void) {
    map<string, string> symbol_table;
    string line;

    getline(cin, line);
    while (line != "quit") {
        if (line == "list")
            list(symbol_table);
        else if (is_assignment(line))
            assign(symbol_table, line);
        else if (is_display_request(line))
            display(symbol_table, line);
        else
            cout << "Invalid command." << endl;
        getline(cin, line);
    }

    cin.get();
    return 0;
}

void list(map<string, string> &symbol_table) {
    for (const auto &p : symbol_table)
        cout << p.first << " = " << p.second << endl;
}

bool is_assignment(string &line) {
    for (char ch : line) {
        if (ch == '=')
            return true;
    }
    return false;
}

void assign(map<string, string> &symbol_table, string &line) {
    symbol_table[line.substr(0, line.find_first_of('=') - 1)] = line.substr(line.find_first_of('=') + 2);
}

bool is_display_request(string &line) {
    for (char ch : line) {
        if (!isalpha(ch))
            return false;
    }
    return true;
}

void display(map<string, string> &symbol_table, string &line) {
    cout << symbol_table[line] << endl;
}
