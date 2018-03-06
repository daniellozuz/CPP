#ifdef _bst_h

template <typename T>
BST<T>::BST(int(*cmp_fn)(T one, T two)) {
	root = NULL;
	this->cmp_fn = cmp_fn;
}

template <typename T>
BST<T>::~BST() {
	recursively_free_tree(root);
}

template <typename T>
void BST<T>::recursively_free_tree(node_t *t) {
	if (t != NULL) {
		recursively_free_tree(t->left);
		recursively_free_tree(t->right);
		delete t;
	}
}

template <typename T>
T *BST<T>::find(T key) {
	node_t *found = recursively_find_node(root, key);
	if (found != NULL)
		return &found->data;
	return NULL;
}

template <typename T>
typename BST<T>::node_t *BST<T>::recursively_find_node(node_t *t, T key) {
	if (t == NULL)
		return NULL;
	int sign = cmp_fn(key, t->data);
	if (sign == 0)
		return t;
	if (sign < 0)
		return recursively_find_node(t->left, key);
	return recursively_find_node(t->right, key);
}

template <typename T>
bool BST<T>::add(T data) {
	return recursively_add_node(root, data);
}

template <typename T>
bool BST<T>::recursively_add_node(node_t * & t, T data) {
	if (t == NULL) {
		t = new node_t;
		t->data = data;
		t->left = t->right = NULL;
		return true;
	}
	int sign = cmp_fn(data, t->data);
	if (sign == 0) {
		t->data = data;
		return false;
	}
	if (sign < 0)
		return recursively_add_node(t->left, data);
	return recursively_add_node(t->right, data);
}

template <typename T>
bool BST<T>::remove(T data) {
	return rec_remove_node(root, data);
}

template <typename T>
bool BST<T>::recursively_remove_node(node_t *& t, T data) {
	if (t == NULL)
		return false;
	int sign = cmp_fn(data, t->data);
	if (sign == 0) {
		remove_target_node(t);
		return true;
	}
	if (sign < 0)
		return recursively_remove_node(t->left, data);
	return recursively_remove_node(t->right, data);
}

template <typename T>
void BST<T>::remove_target_node(node_t * & t) {
	node_t *to_delete = t;
	if (t->left == NULL)
		t = t->right;
	else if (t->right == NULL)
		t = t->left;
	else {
		node_t *new_root = t->left;
		node_t *parent = t;
		while (new_root->right != NULL) {
			parent = new_root;
			new_root = new_root->right;
		}
		if (parent != t) {
			parent->right = new_root->left;
			new_root->left = t->left;
		}
		new_root->right = t->right;
		t = new_root;
	}
	delete to_delete;
}

template <typename T>
template <typename client_T>
void BST<T>::map_all(void(*fn)(T elem, client_T &data), client_T &data) {
	recursively_map_all(root, fn, data);
}

template <typename T>
template <typename client_T>
void BST<T>::recursively_map_all(node_t *t, void(*fn)(T, client_T &), client_T &data) {
	if (t != NULL) {
		recursively_map_all(t->left, fn, data);
		fn(t->data, data);
		recursively_map_all(t->right, fn, data);
	}
}

#endif
