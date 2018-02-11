#ifndef _scanner_h
#define _scanner_h

#include <string>

using namespace std;

class Scanner {
public:
	enum space_option_t { PreserveSpaces, IgnoreSpaces };
	enum string_option_t { ScanQuotesAsStrings, IgnoreQuotes };
	enum number_option_t { ScanNumbersAsWords, ScanNumbersAsIntegers, ScanNumbersAsReals };

	Scanner();
	~Scanner();

	void set_input(string str);
	string next_token();
	bool has_more_tokens();
	void set_space_option(space_option_t option);
	space_option_t get_space_option();
	void set_string_option(string_option_t option);
	void set_number_option(number_option_t option);

private:
	string buffer;
	int buffer_length;
	int current_position;
	space_option_t space_option;
	string_option_t string_option;
	number_option_t number_option;

	void skip_spaces();
	int scan_to_end_of_identifier();
	int scan_to_end_of_quote();
	int scan_to_end_of_integer();
	int scan_to_end_of_real();
};

#endif
