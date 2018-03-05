#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct family_node_t {
	string name;
	vector<family_node_t *> children;
};

family_node_t *read_family_tree(string filename);
void insert(family_node_t * &tree, string child, string parent);
void display_family_tree(family_node_t * &tree);
void display_family_tree(family_node_t * &tree, int tabulation);

int main(void) {
	family_node_t *tree = read_family_tree("normandy.txt");
	display_family_tree(tree);

	cin.get();
	return 0;
}

family_node_t *read_family_tree(string filename) {
	ifstream in_file;
	family_node_t *tree = NULL;
	in_file.open(filename.c_str());
	if (!in_file.fail()) {
		string root, line;
		getline(in_file, root);
		tree = new family_node_t;
		tree->name = root;
		getline(in_file, line);
		while (!in_file.fail()) {
			string child, parent;
			int colon = line.find(":");
			child = line.substr(0, colon);
			parent = line.substr(colon + 1);
			insert(tree, child, parent);
			getline(in_file, line);
		}
	}
	return tree;
}

void insert(family_node_t * &tree, string child, string parent) {
	if (tree->name == parent) {
		family_node_t *node = new family_node_t;
		node->name = child;
		tree->children.push_back(node);
	}
	else {
		for (family_node_t *branch : tree->children)
			insert(branch, child, parent);
	}
}

void display_family_tree(family_node_t * &tree) {
	display_family_tree(tree, 0);
}

void display_family_tree(family_node_t * &tree, int tabulation) {
	for (int i = 0; i < tabulation; i++)
		cout << "  ";
	cout << tree->name << endl;
	for (family_node_t *branch : tree->children)
		display_family_tree(branch, tabulation + 1);
}
