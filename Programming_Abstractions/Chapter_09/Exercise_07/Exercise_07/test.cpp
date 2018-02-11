#include <iostream>
#include "Scanner.h"

using namespace std;

int main(void) {
	Scanner scanner;

	scanner.set_input("\"Hello, world.\"And again\nhello\tworld.3.14 3rd 3.14-17.5E-9Finish");
	scanner.set_space_option(Scanner::IgnoreSpaces);
	scanner.set_string_option(Scanner::ScanQuotesAsStrings);
	scanner.set_number_option(Scanner::ScanNumbersAsReals);

	while (scanner.has_more_tokens())
		cout << scanner.next_token() << endl;

	cin.get();
	return 0;
}
