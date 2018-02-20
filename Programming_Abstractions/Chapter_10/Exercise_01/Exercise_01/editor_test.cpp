#include "EditorBuffer.h"
#include <iostream>
#include <string>

using namespace std;

void execute_command(EditorBuffer &buffer, string line);

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
