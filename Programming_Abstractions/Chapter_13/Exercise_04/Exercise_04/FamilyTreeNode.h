#ifndef _familytreenode_h
#define _familytreenode_h

#include <string>
#include <vector>

using namespace std;

class FamilyTreeNode {
public:
	FamilyTreeNode(string name);
	~FamilyTreeNode();
	string get_name();
	void add_child(FamilyTreeNode *child);
	FamilyTreeNode *get_parent();
	vector<FamilyTreeNode *> get_children();
private:
	string name;
	vector<FamilyTreeNode *> children;
	FamilyTreeNode *parent;
};

#include "FamilyTreeNode.hpp"

#endif
