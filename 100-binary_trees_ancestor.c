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
 * @first: deeper node
 * @second: comparation node
 * Return: the ancestor
 */
binary_tree_t *find_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);
	else
		return (find_ancestor(first->parent, second->parent));
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
		while (depth_first > depth_second)
		{
			first = first->parent;
			depth_first--;
		}
	else
		while (depth_second > depth_first)
		{
			second = second->parent;
			depth_second--;
		}

	return (find_ancestor(first, second));
}
