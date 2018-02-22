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
	void backspace_character();
	void display();
	void move_cursor_forward_by_one_word();
	void move_cursor_backward_by_one_word();
	void delete_one_word();
	void backspace_one_word();

private:
	struct cursor_t {
		int before, after;
	};

	char *buffer;
	int capacity;
	cursor_t cursor;

	void expand_capacity();
};

#endif
