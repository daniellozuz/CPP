#include "EditorBuffer.h"
#include <iostream>

using namespace std;

EditorBuffer::EditorBuffer() {
	start = cursor = NULL;
}

EditorBuffer::~EditorBuffer() {
	cell_t *cp = start;
	while (cp != NULL) {
		cell_t *next = cp->link;
		delete cp;
		cp = next;
	}
}

void EditorBuffer::move_cursor_forward() {
	if (cursor == NULL)
		cursor = start;
	else if (cursor->link != NULL)
		cursor = cursor->link;
}

void EditorBuffer::move_cursor_backward() {
	cell_t *cp = start;
	if (cursor == start)
		cursor = NULL;
	if (cursor != NULL) {
		while (cp->link != cursor)
			cp = cp->link;
		cursor = cp;
	}
}

void EditorBuffer::move_cursor_to_start() {
	cursor = NULL;
}

void EditorBuffer::move_cursor_to_end() {
	cursor = start;
	if (cursor != NULL) {
		while (cursor->link != NULL)
			move_cursor_forward();
	}
}

void EditorBuffer::insert_character(char ch) {
	cell_t *cp = new cell_t;
	cp->ch = ch;
	if (cursor == NULL) {
		cp->link = start;
		start = cp;
	}
	else {
		cp->link = cursor->link;
		cursor->link = cp;
	}
	cursor = cp;
}

void EditorBuffer::delete_character() {
	if (cursor == NULL) {
		if (start != NULL) {
			cell_t *old_cell = start;
			start = start->link;
			delete old_cell;
		}
	}
	else {
		cell_t *cp = start;
		while (cp != cursor)
			cp = cp->link;
		if (cursor->link != NULL) {
			cell_t *old_cell = cursor->link;
			cursor->link = old_cell->link;
			delete old_cell;
		}
	}
}

void EditorBuffer::display() {
	if (start != NULL) {
		for (cell_t *cp = start; cp != NULL; cp = cp->link)
			cout << ' ' << cp->ch;
		cout << endl;
		cell_t *cp = start;
		if (cursor != NULL) {
			for (cp; cp != cursor; cp = cp->link)
				cout << "  ";
			cout << "  ";
		}
		cout << '^' << endl;
	}
}
