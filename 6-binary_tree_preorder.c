#include "binary_trees.h"
/**
*binary_tree_preorder - Travel through a binary tree using pre-order traversal
*@tree: Tree to gou through
*@func: pointer to function print
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}