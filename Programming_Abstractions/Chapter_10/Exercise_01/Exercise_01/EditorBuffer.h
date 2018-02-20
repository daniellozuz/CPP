#ifndef _editorbuffer_h
#define _editorbuffer_h

class EditorBuffer {
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
	void expand_capacity();
	void expand_lines();

private:
	struct line_t {
		int capacity;
		char *buffer;
		int length;
	};
	struct cursor_t {
		int line;
		int position;
	};

	line_t *lines;
	int max_lines;
	int n_lines;
	cursor_t cursor;
};

#endif
