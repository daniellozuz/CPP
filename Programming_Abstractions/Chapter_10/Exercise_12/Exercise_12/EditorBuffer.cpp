#include "EditorBuffer.h"
#include <iostream>

using namespace std;

EditorBuffer::EditorBuffer() {
	start = cursor = new cell_t;
	start->next = start;
	start->prev = start;
}

EditorBuffer::~EditorBuffer() {
	cell_t *cp = start;
	while (cp->next != start) {
		cell_t *next = cp->next;
		delete cp;
		cp = next;
	}
}

void EditorBuffer::move_cursor_forward() {
	if (cursor->next != start)
		cursor = cursor->next;
}

void EditorBuffer::move_cursor_backward() {
	if (cursor != start)
		cursor = cursor->prev;
}

void EditorBuffer::move_cursor_to_start() {
	cursor = start;
}

void EditorBuffer::move_cursor_to_end() {
	cursor = start->prev;
}

void EditorBuffer::insert_character(char ch) {
	cell_t *cp = new cell_t;
	cp->ch = ch;
	cp->next = cursor->next;
	cp->prev = cursor;
	cp->next->prev = cp;
	cursor->next = cp;
	cursor = cp;
}

void EditorBuffer::delete_character() {
	if (cursor->next != start) {
		cell_t *old_cell = cursor->next;
		cursor->next = old_cell->next;
		old_cell->next->prev = cursor;
		delete old_cell;
	}
}

void EditorBuffer::display() {
	for (cell_t *cp = start->next; cp != start; cp = cp->next)
		cout << ' ' << cp->ch;
	cout << endl;
	for (cell_t *cp = start; cp != cursor; cp = cp->next)
		cout << "  ";
	cout << '^' << endl;
}
