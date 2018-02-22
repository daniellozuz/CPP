#include "EditorBuffer.h"
#include <iostream>
#include <string>

using namespace std;

void execute_command(EditorBuffer &buffer, string line);
void execute_command_once(EditorBuffer &buffer, string line);
bool is_integer_followed_by_letter(string line);

int main(void) {
	EditorBuffer buffer;

	while (true) {
		cout << "*";
		string command;
		getline(cin, command);
		if (command != "")
			execute_command(buffer, command);
		buffer.display();
	}

	return 0;
}

void execute_command(EditorBuffer &buffer, string line) {
	if (isalpha(line[0]))
		execute_command_once(buffer, line);
	else if (is_integer_followed_by_letter(line)) {
		int repetition_count = stoi(line.substr(0, line.length() - 1));
		for (int i = 0; i < repetition_count; i++)
			execute_command_once(buffer, string(1, line.back()));
	}
	else
		cout << "Illegal command" << endl;
}

void execute_command_once(EditorBuffer &buffer, string line) {
	switch (toupper(line[0])) {
	case 'I':
		for (int i = 1; i < line.length(); i++)
			buffer.insert_character(line[i]);
		break;
	case 'D':
		buffer.delete_character();
		break;
	case 'F':
		buffer.move_cursor_forward();
		break;
	case 'B':
		buffer.move_cursor_backward();
		break;
	case 'J':
		buffer.move_cursor_to_start();
		break;
	case 'E':
		buffer.move_cursor_to_end();
		break;
	case 'Q':
		exit(0);
	default:
		cout << "Illegal command" << endl;
		break;
	}
}

bool is_integer_followed_by_letter(string line) {
	if ((line.length() < 2) || !isalpha(line.back()))
		return false;
	for (int i = 0; i < line.length() - 1; i++) {
		if (!isdigit(line[i]))
			return false;
	}
	return true;
}
