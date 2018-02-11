#include <iostream>
#include <string>
#include <vector>
#include "RationalStack.h"

using namespace std;

string get_line(void);
void help_command(void);
Rational calculate(string &line);
vector<string> tokenize(string &line);
bool is_operator(string &token);
void apply_operator(char op, RationalStack &operand_stack);

int main() {
	RationalStack operand_stack;

	cout << "RPN Calculator Simulation (type H for help)" << endl;
	while (true) {
		string line = get_line();
		if (line == "" || toupper(line[0]) == 'H')
			help_command();
		else if (toupper(line[0]) == 'Q')
			break;
		else
			cout << calculate(line).to_string() << endl;
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

Rational calculate(string &line) {
	vector<string> tokens = tokenize(line);
	RationalStack operand_stack;
	for (string token : tokens) {
		if (is_operator(token))
			apply_operator(token[0], operand_stack);
		else
			operand_stack.push(Rational(stoi(token), 1));
	}
	return operand_stack.peek();
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

void apply_operator(char op, RationalStack &operand_stack) {
	Rational rhs = operand_stack.peek();
	operand_stack.pop();
	Rational lhs = operand_stack.peek();
	operand_stack.pop();
	switch (op) {
	case '+': lhs.add(rhs); break;
	case '-': lhs.sub(rhs); break;
	case '*': lhs.mul(rhs); break;
	case '/': lhs.div(rhs); break;
	default: cout << "Illegal operator!" << endl;
	}
	operand_stack.push(lhs);
}
