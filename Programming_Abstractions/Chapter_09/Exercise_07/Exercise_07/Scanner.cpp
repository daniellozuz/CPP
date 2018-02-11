#include "scanner.h"
#include <cctype>
#include <iostream>

Scanner::Scanner() {
	buffer = "";
	space_option = PreserveSpaces;
	string_option = IgnoreQuotes;
	number_option = ScanNumbersAsWords;
}

Scanner::~Scanner() {
}

void Scanner::set_input(string str) {
	buffer = str;
	buffer_length = buffer.length();
	current_position = 0;
}

string Scanner::next_token() {
	int finish;
	if (current_position == -1)
		cout << "Error, set_input has not been called!";
	if (space_option == IgnoreSpaces)
		skip_spaces();
	int start = current_position;
	if (start >= buffer_length)
		return "";
	if (string_option == ScanQuotesAsStrings && (buffer[start] == '\"')) {
		current_position++;
		finish = scan_to_end_of_quote();
		return buffer.substr(start, finish - start + 1);
	}
	else if (isalnum(buffer[current_position])) {
		if (number_option == ScanNumbersAsIntegers && isdigit(buffer[current_position]))
			finish = scan_to_end_of_integer();
		else if (number_option == ScanNumbersAsReals && isdigit(buffer[current_position]))
			finish = scan_to_end_of_real();
		else
			finish = scan_to_end_of_identifier();
		return buffer.substr(start, finish - start + 1);
	}
	current_position++;
	return buffer.substr(start, 1);
}

bool Scanner::has_more_tokens() {
	if (current_position == -1)
		cout << "Error, set_input has not been called!";
	if (space_option == IgnoreSpaces)
		skip_spaces();
	return (current_position < buffer_length);
}

void Scanner::set_space_option(space_option_t option) {
	space_option = option;
}

Scanner::space_option_t Scanner::get_space_option() {
	return space_option;
}

void Scanner::set_string_option(string_option_t option) {
	string_option = option;
}

void Scanner::set_number_option(number_option_t option) {
	number_option = option;
}

void Scanner::skip_spaces() {
	while (current_position < buffer_length && isspace(buffer[current_position]))
		current_position++;
}

int Scanner::scan_to_end_of_identifier() {
	while (current_position < buffer_length && isalnum(buffer[current_position]))
		current_position++;
	return current_position - 1;
}

int Scanner::scan_to_end_of_quote() {
	while (current_position < buffer_length && buffer[current_position] != '\"')
		current_position++;
	return current_position++;
}

int Scanner::scan_to_end_of_integer() {
	while (current_position < buffer_length && isdigit(buffer[current_position]))
		current_position++;
	return current_position - 1;
}

int Scanner::scan_to_end_of_real() {
	int state = 0;
	while (true) {
		switch (state) {
		case 0:
			if (isdigit(buffer[current_position])) {
				state = 1;
				current_position++;
			}
			else
				return current_position - 1;
			break;
		case 1:
			if (isdigit(buffer[current_position]))
				current_position++;
			else if (buffer[current_position] == '.') {
				state = 2;
				current_position++;
			}
			else if (buffer[current_position] == 'E') {
				state = 3;
				current_position++;
			}
			else
				return current_position - 1;
			break;
		case 2:
			if (isdigit(buffer[current_position]))
				current_position++;
			else if (buffer[current_position] == 'E') {
				state = 3;
				current_position++;
			}
			else
				return current_position - 1;
			break;
		case 3:
			if (isdigit(buffer[current_position])) {
				state = 5;
				current_position++;
			}
			else if (buffer[current_position] == '+' || buffer[current_position] == '-') {
				state = 4;
				current_position++;
			}
			else
				return current_position - 1;
			break;
		case 4:
			if (isdigit(buffer[current_position])) {
				state = 5;
				current_position++;
			}
			else
				return current_position - 1;
			break;
		case 5:
			if (isdigit(buffer[current_position]))
				current_position++;
			else
				return current_position - 1;
			break;
		}
	}
}
