#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL return 0 else return the height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

		left = 1 + binary_tree_height(tree->left);
		right = 1 + binary_tree_height(tree->right);

	return (left + right);
}
/**
* binary_tree_is_perfect - Check for a perfect binary tree
* @tree: tree to check
* Return: 1 perfect, 0 not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	if (l != r)
	{
		return (0);
	}
	else
		return (1);
}
