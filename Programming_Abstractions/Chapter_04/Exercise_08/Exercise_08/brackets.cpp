#include <iostream>
#include <stack>
#include <string>

using namespace std;

const string PROPER = "{ s = 2 * (a[2] + 3); x = (1 + (2)); }";
const string IMPROPER1 = "(([])";
const string IMPROPER2 = ")(";
const string IMPROPER3 = "{(})";

bool check_brackets(string str);
bool is_bracket(char ch);
bool is_matched(char ch1, char ch2);

int main(void) {
    cout << check_brackets(PROPER) << endl;
    cout << check_brackets(IMPROPER1) << endl;
    cout << check_brackets(IMPROPER2) << endl;
    cout << check_brackets(IMPROPER3) << endl;

    cin.get();
    return 0;
}

bool check_brackets(string str) {
    stack<char> brackets;
    for (int i = 0; i < str.length(); i++) {
        if (is_bracket(str[i])) {
            if (brackets.empty() || !is_matched(brackets.top(), str[i]))
                brackets.push(str[i]);
            else
                brackets.pop();
        }
    }
    return brackets.empty();
}

bool is_bracket(char ch) {
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

bool is_matched(char ch1, char ch2) {
    return ((ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']'));
}
