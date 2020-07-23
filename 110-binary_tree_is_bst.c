#include "binary_trees.h"
/**
 * find_max_key - find_max_key
 * @tree: tree
 * Return: int
 */
int find_max_key(binary_tree_t *tree)
{

	int res, lres, rres;

	if (tree == NULL)
		return (0);

	res = tree->n;
	lres = find_max_key(tree->left);
	rres = find_max_key(tree->right);

	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return (res);
}
/**
 * find_min_key - find_min_keys
 * @tree: tree
 * Return: int
 */
int find_min_key(binary_tree_t *tree)
{
	int res, lres, rres;

	if (tree == NULL)
		return (INT_MAX);

	res = tree->n;
	lres = find_min_key(tree->left);
	rres = find_min_key(tree->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return (res);
}
/**
 * is_bst - is_bst
 * @tree: tree
 * Return: int
 */
int is_bst(const binary_tree_t *tree)
{
	int max_key_in_left, min_key_in_right;

	if (tree == NULL)
		return (1);

	max_key_in_left = find_max_key(tree->left);
	min_key_in_right = find_min_key(tree->right);

	if (max_key_in_left > tree->n || min_key_in_right < tree->n)
		return (0);

	if (is_bst(tree->left) && is_bst(tree->right))
		return (1);
	return (0);
}
/**
 * binary_tree_is_bst - binary_tree_is_bst
 * @tree: tree
 * Return: int
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree));
}
