#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int cmp_fn(string one, string two);

int main(void) {
	BST<string> tree(cmp_fn);

	cin.get();
	return 0;
}

int cmp_fn(string one, string two) {
	if (one == two)
		return 0;
	return (one < two) ? -1 : 1;
}
