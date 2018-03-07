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
	bool verdict = true;
	T current_value = "";
	auto my_fun = [this, &verdict, &current_value](T elem) {
		if (cmp_fn(current_value, elem) == 1)
			verdict = false;
		current_value = elem;
	};
	recursively_map_all(root, my_fun);
	return verdict;
}

template <typename T>
void BST<T>::show() {
	Mat img(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3, Scalar(0, 0, 0));

	draw_node(img, root, Point(WINDOW_WIDTH / 2, 10), 2);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	resizeWindow("image", WINDOW_WIDTH, WINDOW_HEIGHT);
	waitKey(0);
}

template <typename T>
void BST<T>::draw_node(Mat img, node_t *node, Point anchor, int level) {
	if (node != NULL) {
		Scalar color = Scalar(255, 255, 255);
		Size text_size = getTextSize(node->data, FONT_HERSHEY_PLAIN, 1.0, 1, 0);
		Point next_left = anchor + Point(-WINDOW_WIDTH / (level*level), VERTICAL_SEPARATION);
		Point next_right = anchor + Point(WINDOW_WIDTH / (level*level), VERTICAL_SEPARATION);
		rectangle(img, anchor + Point(-CELL_WIDTH / 2, 0), anchor + Point(CELL_WIDTH / 2, CELL_HEIGHT), color);
		line(img, anchor + Point(-CELL_WIDTH / 2, CELL_HEIGHT / 2), anchor + Point(CELL_WIDTH / 2, CELL_HEIGHT / 2), color);
		line(img, anchor + Point(0, CELL_HEIGHT / 2), anchor + Point(0, CELL_HEIGHT), color);
		putText(img, node->data, anchor + Point(-text_size.width / 2, text_size.height + 5), FONT_HERSHEY_PLAIN, 1.0, color);
		if (node->left != NULL)
			line(img, anchor + Point(-CELL_WIDTH / 4, 3 * CELL_HEIGHT / 4), Point(next_left.x, next_left.y), color);
		else
			line(img, anchor + Point(-CELL_WIDTH / 2, CELL_HEIGHT), anchor + Point(0, CELL_HEIGHT / 2), color);
		if (node->right != NULL)
			line(img, anchor + Point(CELL_WIDTH / 4, 3 * CELL_HEIGHT / 4), Point(next_right.x, next_right.y), color);
		else
			line(img, anchor + Point(0, CELL_HEIGHT), anchor + Point(CELL_WIDTH / 2, CELL_HEIGHT / 2), color);
		draw_node(img, node->left, next_left, level + 1);
		draw_node(img, node->right, next_right, level + 1);
	}
}

template <typename T>
void BST<T>::recursively_map_all(node_t *node, function<void(T)> fn) {
	if (node != NULL) {
		recursively_map_all(node->left, fn);
		fn(node->data);
		recursively_map_all(node->right, fn);
	}
}

#endif
