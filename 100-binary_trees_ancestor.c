#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @tree: tree to travle through
* Return: the depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
/**
 * find_ancestor - function that find ancestor
 * @deeper: deeper node
 * @comp: comparation node
 * Return: the ancestor
 */
binary_tree_t *find_ancestor(const binary_tree_t *deeper,
const binary_tree_t *comp)
{
	if (deeper->parent == comp)
	{
		return (deeper->parent);
	}
	else if (deeper->parent->left != deeper)
	{
		if (deeper->parent->left == comp)
			return (deeper->parent);
	}
	else if (deeper->parent->right != deeper)
	{
		if (deeper->parent->right == comp)
			return (deeper->parent);
	}
	return (find_ancestor(deeper->parent, comp));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor of two nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	int depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first >= depth_second)
		return	(find_ancestor(first,  second));
	else
		return	(find_ancestor(second,  first));
}
