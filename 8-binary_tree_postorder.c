#include "binary_trees.h"
/**
*binary_tree_postorder - Travel through a binary tree using postorder traversal
*@tree: Tree to go through
*@func: pointer to function print
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
