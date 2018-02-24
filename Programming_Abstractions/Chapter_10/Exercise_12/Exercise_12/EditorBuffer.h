#ifndef _editorbuffer_h
#define _editorbuffer_h

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
		char ch;
		cell_t *prev;
		cell_t *next;
	};
	cell_t *start;
	cell_t *cursor;
};

#endif
