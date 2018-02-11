#include "scanner.h"
#include <cctype>
#include <iostream>

Scanner::Scanner() {
	buffer = "";
	space_option = PreserveSpaces;
	string_option = IgnoreQuotes;
}

Scanner::~Scanner() {
}

void Scanner::set_input(string str) {
	buffer = str;
	len = buffer.length();
	cp = 0;
}

string Scanner::next_token() {
	if (cp == -1)
		cout << "Error, set_input has not been called!";
	if (space_option == IgnoreSpaces)
		skip_spaces();
	int start = cp;
	if (start >= len)
		return "";
	if (string_option == ScanQuotesAsStrings && (buffer[start] == '\"')) {
		cp++;
		int finish = scan_to_end_of_quote();
		return buffer.substr(start, finish - start + 1);
	}
	else if (isalnum(buffer[cp])) {
		int finish = scan_to_end_of_identifier();
		return buffer.substr(start, finish - start + 1);
	}
	cp++;
	return buffer.substr(start, 1);
}

bool Scanner::has_more_tokens() {
	if (cp == -1)
		cout << "Error, set_input has not been called!";
	if (space_option == IgnoreSpaces)
		skip_spaces();
	return (cp < len);
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

void Scanner::skip_spaces() {
	while (cp < len && isspace(buffer[cp]))
		cp++;
}

int Scanner::scan_to_end_of_identifier() {
	while (cp < len && isalnum(buffer[cp]))
		cp++;
	return cp - 1;
}

int Scanner::scan_to_end_of_quote() {
	while (cp < len && buffer[cp] != '\"')
		cp++;
	return cp++;
}
