#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int cmp_fn(string one, string two);

int main(void) {
	BST<string> tree(cmp_fn);

	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("First");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("Second");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("Third");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("Fourth");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("Fifth");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	tree.add("Sixth");
	cout << tree.height() << "  " << tree.is_balanced() << endl;
	
	cout << tree.has_binary_search_property() << endl;

	tree.show();

	cin.get();
	return 0;
}

int cmp_fn(string one, string two) {
	if (one == two)
		return 0;
	return (one < two) ? -1 : 1;
}
