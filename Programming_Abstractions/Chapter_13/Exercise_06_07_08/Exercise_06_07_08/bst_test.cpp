#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int cmp_fn(string one, string two);

int main(void) {
	BST<string> tree(cmp_fn);
	
	cout << tree.height() << endl;

	tree.add("First");
	tree.add("Second");
	tree.add("Third");
	tree.add("Fourth");
	tree.add("Fifth");
	tree.add("Sixth");

	cout << tree.height() << endl;

	cin.get();
	return 0;
}

int cmp_fn(string one, string two) {
	if (one == two)
		return 0;
	return (one < two) ? -1 : 1;
}
