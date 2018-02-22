#include "EditorBuffer.h"
#include <iostream>
#include <string>

using namespace std;

void execute_command(EditorBuffer &buffer, string line);
void execute_command_once(EditorBuffer &buffer, string line);
void execute_word_command(EditorBuffer &buffer, string line);
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
	if (isalpha(line[0])) {
		if (toupper(line[0]) != 'W')
			execute_command_once(buffer, line);
		else if (line.length() == 2)
			execute_word_command(buffer, string(1, line[1]));
	}
	else if (is_integer_followed_by_letter(line)) {
		int repetition_count = stoi(line.substr(0, line.length() - 1));
		if (repetition_count >= 0) {
			if (toupper(line.back()) == 'C')
				buffer.copy(repetition_count);
			else {
				for (int i = 0; i < repetition_count; i++)
					execute_command_once(buffer, string(1, line.back()));
			}
		}
		else {
			char command = ' ';
			if (toupper(line.back()) == 'F')
				command = 'B';
			if (toupper(line.back()) == 'B')
				command = 'F';
			if (toupper(line.back()) == 'D')
				command = 'U';
			if (toupper(line.back()) == 'U')
				command = 'D';
			if (command != ' ') {
				repetition_count *= -1;
				for (int i = 0; i < repetition_count; i++)
					execute_command_once(buffer, string(1, command));
			}
			else
				cout << "Illegal command" << endl;
		}
	}
	else
		cout << "Illegal command" << endl;
}

void execute_word_command(EditorBuffer &buffer, string line) {
	switch (toupper(line[0])) {
	case 'F':
		buffer.move_cursor_forward_by_one_word();
		break;
	case 'B':
		buffer.move_cursor_backward_by_one_word();
		break;
	case 'D':
		buffer.delete_one_word();
		break;
	case 'U':
		buffer.backspace_one_word();
		break;
	default:
		cout << "Illegal command" << endl;
		break;
	}
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
	case 'U':
		buffer.backspace_character();
		break;
	case 'P':
		buffer.paste();
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
	int i = (line[0] == '-') ? 1 : 0;
	for (i; i < line.length() - 1; i++) {
		if (!isdigit(line[i]))
			return false;
	}
	return true;
}
