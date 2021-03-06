#include "EditorBuffer.h"
#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 6;

EditorBuffer::EditorBuffer() {
	capacity = INITIAL_CAPACITY;
	buffer = new char[capacity];
	cursor.before = 0;
	cursor.after = capacity;
}

EditorBuffer::~EditorBuffer() {
	delete[] buffer;
}

void EditorBuffer::move_cursor_forward() {
	if (cursor.after != capacity)
		buffer[cursor.before++] = buffer[cursor.after++];
}

void EditorBuffer::move_cursor_backward() {
	if (cursor.before != 0)
		buffer[--cursor.after] = buffer[--cursor.before];
}

void EditorBuffer::move_cursor_to_start() {
	while (cursor.before != 0)
		move_cursor_backward();
}

void EditorBuffer::move_cursor_to_end() {
	while (cursor.after != capacity)
		move_cursor_forward();
}

void EditorBuffer::insert_character(char ch) {
	if (cursor.before == cursor.after)
		expand_capacity();
	buffer[cursor.before++] = ch;
}

void EditorBuffer::delete_character() {
	if (cursor.after != capacity)
		cursor.after++;
}

void EditorBuffer::backspace_character() {
	if (cursor.before != 0)
		cursor.before--;
}

void EditorBuffer::display() {
	for (int i = 0; i < cursor.before; i++)
		cout << ' ' << buffer[i];
	for (int i = cursor.after; i < capacity; i++)
		cout << ' ' << buffer[i];
	cout << endl;
	for (int i = 0; i < cursor.before; i++)
		cout << "  ";
	cout << '^' << endl;
}

void EditorBuffer::move_cursor_forward_by_one_word() {
	while ((cursor.after != capacity) && (!isalnum(buffer[cursor.after])))
		move_cursor_forward();
	while ((cursor.after != capacity) && (isalnum(buffer[cursor.after])))
		move_cursor_forward();
}

void EditorBuffer::move_cursor_backward_by_one_word() {
	while ((cursor.before != 0) && (!isalnum(buffer[cursor.before - 1])))
		move_cursor_backward();
	while ((cursor.before != 0) && (isalnum(buffer[cursor.before - 1])))
		move_cursor_backward();
}

void EditorBuffer::delete_one_word() {
	while ((cursor.after != capacity) && (!isalnum(buffer[cursor.after])))
		delete_character();
	while ((cursor.after != capacity) && (isalnum(buffer[cursor.after])))
		delete_character();
}

void EditorBuffer::backspace_one_word() {
	while ((cursor.before != 0) && (!isalnum(buffer[cursor.before - 1])))
		backspace_character();
	while ((cursor.before != 0) && (isalnum(buffer[cursor.before - 1])))
		backspace_character();
}

void EditorBuffer::expand_capacity() {
	char *old_buffer = buffer;
	buffer = new char[2 * capacity];
	for (int i = 0; i < cursor.before; i++)
		buffer[i] = old_buffer[i];
	for (int i = cursor.after; i < capacity; i++)
		buffer[capacity + i] = old_buffer[i];
	cursor.after += capacity;
	capacity *= 2;
	delete[] old_buffer;
}
