#ifndef _bst_h
#define _bst_h

#include <functional>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

template <typename T>
class BST {
public:
	BST(int(*cmp_fn)(T one, T two));
	~BST();

	T *find(T key);
	bool add(T elem);
	bool remove(T key);
	int height();
	bool is_balanced();
	bool has_binary_search_property();
	void show();

private:
	struct node_t {
		T data;
		node_t *left, *right;
	};
	struct client_data_t {
		bool verdict;
		T *current_value;
	};

	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;
	static const int CELL_WIDTH = 80;
	static const int CELL_HEIGHT = 50;
	static const int VERTICAL_SEPARATION = 100;

	node_t *root;
	int(*cmp_fn)(T, T);
	node_t *recursively_find_node(node_t *node, T key);
	bool recursively_add_node(node_t * & node, T key);
	bool recursively_remove_node(node_t * & node, T key);
	void remove_target_node(node_t * & node);
	void recursively_free_tree(node_t *node);
	int height(node_t *node);
	int is_balanced(node_t *node, bool &verdict);
	void recursively_map_all(node_t *node, function<void(T)> fn);
	void draw_node(Mat img, node_t *node, Point anchor, int level);
};

#include "BST.hpp"

#endif
