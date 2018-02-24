#include "EditorBuffer.h"
#include <iostream>

using namespace std;

EditorBuffer::EditorBuffer() {
	start = new cell_t;
	start->next = start;
	start->prev = start;
	start->length = 0;
	cursor.cell = start;
	cursor.position = 0;
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
	if (cursor.position < cursor.cell->length)
		cursor.position++;
	else if (cursor.cell->next != start) {
		cursor.cell = cursor.cell->next;
		cursor.position = 1;
	}
}

void EditorBuffer::move_cursor_backward() {
	if (cursor.position > 1)
		cursor.position--;
	else if (cursor.cell->prev != start) {
		cursor.cell = cursor.cell->prev;
		cursor.position = cursor.cell->length;
	}
}

void EditorBuffer::move_cursor_to_start() {
	cursor.cell = start;
	cursor.position = 0;
}

void EditorBuffer::move_cursor_to_end() {
	cursor.cell = start->prev;
	cursor.position = cursor.cell->length;
}

void EditorBuffer::insert_character(char ch) {
	if (cursor.cell != start) {
		if (cursor.cell->length < BLOCK_SIZE) {
			for (int i = cursor.cell->length; i > cursor.position; i--)
				cursor.cell->block[i] = cursor.cell->block[i - 1];
			cursor.cell->block[cursor.position] = ch;
			cursor.cell->length++;
			cursor.position++;
		}
		else {
			cell_t *cp = new cell_t;
			for (int i = 0; i < BLOCK_SIZE / 2; i++) {
				cp->block[i] = cursor.cell->block[BLOCK_SIZE / 2 + i - 1];
			}
			cp->length = BLOCK_SIZE / 2;
			cp->next = cursor.cell->next;
			cp->prev = cursor.cell;
			cp->next->prev = cp;
			cursor.cell->next = cp;
			cursor.cell->length = BLOCK_SIZE / 2;
			if (cursor.position <= BLOCK_SIZE / 2) {
				for (int i = cursor.cell->length; i > cursor.position; i--)
					cursor.cell->block[i] = cursor.cell->block[i - 1];
				cursor.cell->block[cursor.position] = ch;
				cursor.cell->length++;
				cursor.position++;
			}
			else {
				cursor.cell = cp;
				cursor.position -= BLOCK_SIZE / 2;
				for (int i = cursor.cell->length; i > cursor.position; i--)
					cursor.cell->block[i] = cursor.cell->block[i - 1];
				cursor.cell->block[cursor.position] = ch;
				cursor.cell->length++;
				cursor.position++;
			}
		}
	}
	else {
		cell_t *cp = new cell_t;
		cp->block[0] = ch;
		cp->length = 1;
		cp->next = cursor.cell->next;
		cp->prev = start;
		cp->next->prev = cp;
		cursor.cell->next = cp;
		cursor.position = 1;
	}
}

void EditorBuffer::delete_character() {
	/*if (cursor->next != start) {
		cell_t *old_cell = cursor->next;
		cursor->next = old_cell->next;
		old_cell->next->prev = cursor;
		delete old_cell;
	}*/
}

void EditorBuffer::display() {
	for (cell_t *cp = start->next; cp != start; cp = cp->next) {
		for (int i = 0; i < cp->length; i++)
			cout << ' ' << cp->block[i];
	}
	cout << endl;
	for (cell_t *cp = start; cp != cursor.cell; cp = cp->next) {
		for (int i = 0; i < cp->length; i++)
			cout << "  ";
	}
	for (int i = 0; i < cursor.position; i++)
		cout << "  ";
	cout << '^' << endl;
}
