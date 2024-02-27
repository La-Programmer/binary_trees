#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a left child node for a parent node
 *
 * @parent: Pointer to the parent node
 * @value: Value to be stored in new node
 *
 * Return: Pointer to new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (parent->left == NULL)
		parent->left = new_node;
	else
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
		parent->left = new_node;
	}
	return (new_node);
}
