#include <iostream>
#include "Scanner.h"

using namespace std;

int main(void) {
	Scanner scanner;

	scanner.set_input("\"Hello, world.\"And again\nhello\tworld.");
	scanner.set_space_option(Scanner::IgnoreSpaces);
	scanner.set_string_option(Scanner::ScanQuotesAsStrings);

	while (scanner.has_more_tokens())
		cout << scanner.next_token() << endl;
	
	cin.get();
	return 0;
}
