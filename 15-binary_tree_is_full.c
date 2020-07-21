#include "binary_trees.h"
/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int r;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	else
	{
		r = binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
		return (r);
	}

	return (0);

}
