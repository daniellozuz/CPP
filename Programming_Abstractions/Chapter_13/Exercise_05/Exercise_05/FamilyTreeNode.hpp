#ifdef _familytreenode_h

FamilyTreeNode::FamilyTreeNode(string name) {
	this->name = name;
	this->parent = NULL;
}

FamilyTreeNode::~FamilyTreeNode() {
}

string FamilyTreeNode::get_name() {
	return name;
}

void FamilyTreeNode::add_child(FamilyTreeNode *child) {
	child->parent = this;
	children.push_back(child);
}

FamilyTreeNode *FamilyTreeNode::get_parent() {
	return parent;
}

vector<FamilyTreeNode *> FamilyTreeNode::get_children() {
	return children;
}

#endif
