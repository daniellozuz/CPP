#include "EditorBuffer.h"
#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 10;
const int INITIAL_LINES = 8;
const char NEW_LINE = '/';

EditorBuffer::EditorBuffer() {
	max_lines = INITIAL_LINES;
	n_lines = 1;
	lines = new line_t[max_lines];
	for (int i = 0; i < max_lines; i++) {
		lines[i].capacity = INITIAL_CAPACITY;
		lines[i].buffer = new char[INITIAL_CAPACITY];
		lines[i].length = 0;
	}
	cursor.line = 0;
	cursor.position = 0;
}

EditorBuffer::~EditorBuffer() {
	for (int i = 0; i < max_lines; i++)
		delete[] lines[i].buffer;
	delete lines;
}

void EditorBuffer::move_cursor_forward() {
	if (lines[cursor.line].buffer[cursor.position] == NEW_LINE) {
		cursor.line++;
		cursor.position = 0;
	}
	else if (cursor.position < lines[cursor.line].length)
		cursor.position++;
}

void EditorBuffer::move_cursor_backward() {
	if (cursor.position > 0)
		cursor.position--;
	else if (cursor.line > 0) {
		cursor.line--;
		cursor.position = lines[cursor.line].length - 1;
	}
}

void EditorBuffer::move_cursor_to_start() {
	cursor.line = 0;
	cursor.position = 0;
}

void EditorBuffer::move_cursor_to_end() {
	cursor.line = n_lines - 1;
	cursor.position = lines[cursor.line].length;
}

void EditorBuffer::insert_character(char ch) {
	if (ch == NEW_LINE) {
		if (n_lines == max_lines)
			expand_lines();
		for (int i = n_lines - 1; i > cursor.line; i--)
			lines[i + 1] = lines[i];
		line_t new_line;
		new_line.length = 0;
		new_line.capacity = lines[cursor.position].length;
		new_line.buffer = new char[new_line.capacity];
		lines[cursor.line + 1] = new_line;
		for (int i = 0; i < lines[cursor.line].length - cursor.position; i++)
			lines[cursor.line + 1].buffer[i] = lines[cursor.line].buffer[i + cursor.position];
		lines[cursor.line + 1].length = lines[cursor.line].length - cursor.position;
		lines[cursor.line].buffer[cursor.position] = ch;
		lines[cursor.line].length = cursor.position + 1;
		cursor.position = 0;
		cursor.line++;
		n_lines++;
	}
	else {
		if (lines[cursor.line].length == lines[cursor.line].capacity)
			expand_capacity();
		for (int i = lines[cursor.line].length; i > cursor.position; i--)
			lines[cursor.line].buffer[i] = lines[cursor.line].buffer[i - 1];
		lines[cursor.line].buffer[cursor.position] = ch;
		lines[cursor.line].length++;
		cursor.position++;
	}
}

void EditorBuffer::delete_character() {
	if (cursor.position < lines[cursor.line].length) {
		if (lines[cursor.line].buffer[cursor.position] == NEW_LINE) {
			line_t new_line;
			new_line.capacity = lines[cursor.line + 1].length + cursor.position;
			new_line.length = new_line.capacity;
			new_line.buffer = new char[new_line.capacity];
			for (int i = 0; i <= cursor.position; i++)
				new_line.buffer[i] = lines[cursor.line].buffer[i];
			for (int i = 0; i < lines[cursor.line + 1].length; i++)
				new_line.buffer[cursor.position + i] = lines[cursor.line + 1].buffer[i];
			lines[cursor.line] = new_line;
			for (int i = cursor.line + 1; i < n_lines - 1; i++)
				lines[i] = lines[i + 1];
			n_lines--;
		}
		else {
			for (int i = cursor.position + 1; i < lines[cursor.line].length; i++)
				lines[cursor.line].buffer[i - 1] = lines[cursor.line].buffer[i];
			lines[cursor.line].length--;
		}
	}
}

void EditorBuffer::display() {
	for (int i = 0; i < n_lines; i++) {
		for (int j = 0; j < lines[i].length; j++)
			cout << ' ' << lines[i].buffer[j];
		cout << endl;
		if (cursor.line == i) {
			for (int j = 0; j < cursor.position; j++)
				cout << "  ";
			cout << '^' << endl;
		}
	}
}

void EditorBuffer::expand_capacity() {
	char *old_array = lines[cursor.line].buffer;
	lines[cursor.line].capacity *= 2;
	lines[cursor.line].buffer = new char[lines[cursor.line].capacity];
	for (int i = 0; i < lines[cursor.line].length; i++)
		lines[cursor.line].buffer[i] = old_array[i];
	delete[] old_array;
}

void EditorBuffer::expand_lines() {
	line_t *old_lines = lines;
	max_lines *= 2;
	lines = new line_t[max_lines];
	for (int i = 0; i < cursor.line; i++)
		lines[i] = old_lines[i];
	delete[] old_lines;
}
