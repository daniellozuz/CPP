#include <iostream>
#include <fstream>
#include <string>

#include "FamilyTreeNode.h"

using namespace std;

struct family_node_t {
	string name;
	vector<family_node_t *> children;
};

FamilyTreeNode *read_family_tree(string filename);
void insert(FamilyTreeNode &node, string child, string parent);
void display_family_tree(FamilyTreeNode &node);
void display_family_tree(FamilyTreeNode &node, int tabulation);

int main(void) {
	FamilyTreeNode *tree = read_family_tree("normandy.txt");
	display_family_tree(*tree);

	cin.get();
	return 0;
}

FamilyTreeNode *read_family_tree(string filename) {
	ifstream in_file;
	in_file.open(filename.c_str());
	if (!in_file.fail()) {
		string root, line;
		getline(in_file, root);
		FamilyTreeNode *tree = new FamilyTreeNode(root);
		getline(in_file, line);
		while (!in_file.fail()) {
			string child, parent;
			int colon = line.find(":");
			child = line.substr(0, colon);
			parent = line.substr(colon + 1);
			insert(*tree, child, parent);
			getline(in_file, line);
		}
		return tree;
	}
	return NULL;
}

void insert(FamilyTreeNode &node, string child, string parent) {
	if (node.get_name() == parent)
		node.add_child(new FamilyTreeNode(child));
	else {
		for (FamilyTreeNode *child_node : node.get_children())
			insert(*child_node, child, parent);
	}
}

void display_family_tree(FamilyTreeNode &node) {
	display_family_tree(node, 0);
}

void display_family_tree(FamilyTreeNode &node, int tabulation) {
	for (int i = 0; i < tabulation; i++)
		cout << "  ";
	if (node.get_parent() != NULL)
		cout << node.get_name() << "    (Child of: " << node.get_parent()->get_name() << ")" << endl;
	else
		cout << node.get_name() << endl;
	for (FamilyTreeNode *branch : node.get_children())
		display_family_tree(*branch, tabulation + 1);
}
