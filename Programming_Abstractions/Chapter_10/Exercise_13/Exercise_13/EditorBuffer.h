#ifndef _editorbuffer_h
#define _editorbuffer_h

const int BLOCK_SIZE = 4;

class EditorBuffer
{
public:
	EditorBuffer();
	~EditorBuffer();

	void move_cursor_forward();
	void move_cursor_backward();
	void move_cursor_to_start();
	void move_cursor_to_end();
	void insert_character(char ch);
	void delete_character();
	void display();

private:
	
	struct cell_t {
		char block[BLOCK_SIZE];
		int length;
		cell_t *prev;
		cell_t *next;
	};
	struct cursor_t {
		cell_t *cell;
		int position;
	};
	cell_t *start;
	cursor_t cursor;
};

#endif
