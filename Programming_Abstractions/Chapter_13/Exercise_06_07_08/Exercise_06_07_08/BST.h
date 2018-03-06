#ifndef _bst_h
#define _bst_h

using namespace std;

template <typename T>
class BST {
public:
	BST(int(*cmp_fn)(T one, T two));
	~BST();
	
	T *find(T key);
	bool add(T elem);
	bool remove(T key);
	int height();

	template <typename client_T>
	void map_all(void(*fn)(T elem, client_T &data), client_T &data);

private:
	struct node_t {
		T data;
		node_t *left, *right;
	};

	node_t *root;
	int(*cmp_fn)(T, T);
	node_t *recursively_find_node(node_t *node, T key);
	bool recursively_add_node(node_t * & node, T key);
	bool recursively_remove_node(node_t * & node, T key);
	void remove_target_node(node_t * & node);
	void recursively_free_tree(node_t *node);
	int height(node_t *node);

	template <typename client_T>
	void recursively_map_all(node_t *node, void(*fn)(T, client_T &), client_T &data);
};

#include "BST.hpp"

#endif