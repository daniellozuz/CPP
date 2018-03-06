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
void BST<T>::recursively_free_tree(node_t *node) {
	if (node != NULL) {
		recursively_free_tree(node->left);
		recursively_free_tree(node->right);
		delete node;
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
typename BST<T>::node_t *BST<T>::recursively_find_node(node_t *node, T key) {
	if (node == NULL)
		return NULL;
	int sign = cmp_fn(key, node->data);
	if (sign == 0)
		return node;
	if (sign < 0)
		return recursively_find_node(node->left, key);
	return recursively_find_node(node->right, key);
}

template <typename T>
bool BST<T>::add(T data) {
	return recursively_add_node(root, data);
}

template <typename T>
bool BST<T>::recursively_add_node(node_t * & node, T data) {
	if (node == NULL) {
		node = new node_t;
		node->data = data;
		node->left = node->right = NULL;
		return true;
	}
	int sign = cmp_fn(data, node->data);
	if (sign == 0) {
		node->data = data;
		return false;
	}
	if (sign < 0)
		return recursively_add_node(node->left, data);
	return recursively_add_node(node->right, data);
}

template <typename T>
bool BST<T>::remove(T data) {
	return rec_remove_node(root, data);
}

template <typename T>
bool BST<T>::recursively_remove_node(node_t *& node, T data) {
	if (node == NULL)
		return false;
	int sign = cmp_fn(data, node->data);
	if (sign == 0) {
		remove_target_node(node);
		return true;
	}
	if (sign < 0)
		return recursively_remove_node(node->left, data);
	return recursively_remove_node(node->right, data);
}

template <typename T>
void BST<T>::remove_target_node(node_t * & node) {
	node_t *to_delete = node;
	if (node->left == NULL)
		node = node->right;
	else if (node->right == NULL)
		node = node->left;
	else {
		node_t *new_root = node->left;
		node_t *parent = node;
		while (new_root->right != NULL) {
			parent = new_root;
			new_root = new_root->right;
		}
		if (parent != node) {
			parent->right = new_root->left;
			new_root->left = node->left;
		}
		new_root->right = node->right;
		node = new_root;
	}
	delete to_delete;
}

template <typename T>
int BST<T>::height() {
	return height(root);
}

template <typename T>
int BST<T>::height(node_t *node) {
	if (node == NULL)
		return 0;
	int left_height = 1 + height(node->left);
	int right_height = 1 + height(node->right);
	return (left_height > right_height) ? left_height : right_height;
}

template <typename T>
bool BST<T>::is_balanced() {
	bool verdict = true;
	is_balanced(root, verdict);
	return verdict;
}

template <typename T>
int BST<T>::is_balanced(node_t *node, bool &verdict) {
	if (node == NULL)
		return 0;
	int left_height = height(node->left);
	int right_height = height(node->right);
	if (left_height > right_height + 1 || left_height + 1 < right_height)
		verdict = false;
	return (left_height > right_height) ? 1 + left_height : 1 + right_height;
}

template <typename T>
bool BST<T>::has_binary_search_property() {
	struct client_data_t {
		bool verdict;
		T *current_value;
	};
	auto fun = [this](T elem, client_data_t &data) { // Why void instead of auto does not work?
		if (data.current_value != NULL && cmp_fn(*data.current_value, elem) == 1)
			data.verdict = false;
		data.current_value = &elem;
	};
	client_data_t my_data;
	my_data.verdict = true;
	my_data.current_value = NULL;
	map_all<client_data_t>(fun, my_data);
	return my_data.verdict;
	// Do inorder walk (should yield nondecreasing strings).
	// recursively_map_all is inorder walk!
	// Just pass it appropriate lambda and return data
}

template <typename T>
template <typename client_T>
void BST<T>::map_all(void(*fn)(T elem, client_T &data), client_T &data) {
	recursively_map_all(root, fn, data);
}

template <typename T>
template <typename client_T>
void BST<T>::recursively_map_all(node_t *node, void(*fn)(T, client_T &), client_T &data) {
	if (node != NULL) {
		recursively_map_all(node->left, fn, data);
		fn(node->data, data);
		recursively_map_all(node->right, fn, data);
	}
}

#endif
