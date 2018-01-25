#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string get_line(void);
void help_command(void);
double calculate(string &line);
vector<string> tokenize(string &line);
bool is_operator(string &token);
void apply_operator(char op, stack<double> &operand_stack);

int main() {
    stack<double> operand_stack;

    cout << "RPN Calculator Simulation (type H for help)" << endl;
    while (true) {
        string line = get_line();
        if (line == "" || toupper(line[0]) == 'H')
            help_command();
        else if (toupper(line[0]) == 'Q')
            break;
        else
            cout << calculate(line) << endl;
    }

    cin.get();
    return 0;
}

string get_line(void) {
    string line;
    cout << "> ";
    getline(cin, line);
    return line;
}

void help_command() {
    cout << "Enter expressions in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which they apply." << endl;
    cout << " Q -- Quit the program" << endl;
    cout << " H -- Display this help message" << endl;
}

double calculate(string &line) {
    vector<string> tokens = tokenize(line);
    stack<double> operand_stack;
    for (string token : tokens) {
        if (is_operator(token))
            apply_operator(token[0], operand_stack);
        else
            operand_stack.push(stod(token));
    }
    return operand_stack.top();
}

vector<string> tokenize(string &line) {
    vector<string> tokens;
    string token;
    line += ' ';
    for (char ch : line) {
        if (isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
            token.push_back(ch);
    }
    return tokens;
}

bool is_operator(string &token) {
    return (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

void apply_operator(char op, stack<double> &operand_stack) {
    double result;
    double rhs = operand_stack.top();
    operand_stack.pop();
    double lhs = operand_stack.top();
    operand_stack.pop();
    switch (op) {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
        default: cout << "Illegal operator!" << endl;
    }
    operand_stack.push(result);
}
