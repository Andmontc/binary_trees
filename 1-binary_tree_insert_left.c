#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	newnode->right = NULL;
	newnode->n = value;
	if (parent->left != NULL)
	{
		parent->left->parent = newnode;
	}
	newnode->left = parent->left;
	parent->left = newnode;
	newnode->parent = parent;
	return (newnode);
}
