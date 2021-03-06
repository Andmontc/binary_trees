#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: If tree is NULL return 0, else the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - is_complete
 * @root: root
 * @index: index
 * @number_nodes: number of nodes
 * Return: int
 */
int is_complete(const binary_tree_t *root, int index, int number_nodes)
{
	if (root == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, number_nodes) &&
			is_complete(root->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_complete - binary_tree_is_complete
 * @tree: tree
 * Return: int
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_size(tree);

	return (is_complete(tree, 0, nodes));
}
