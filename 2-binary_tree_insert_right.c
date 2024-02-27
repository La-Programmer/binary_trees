#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a right child to a parent node
 *
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (parent->right == NULL)
		parent->right = new_node;
	else
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
	}
	return (new_node);
}
