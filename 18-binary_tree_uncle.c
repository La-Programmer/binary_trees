#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: Pointer to the node
 *
 * Return: Pointer to the sibling of the node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *head = malloc(sizeof(binary_tree_t));

	if (node == NULL || node->parent == NULL)
	{
		free(head);
		return (NULL);
	}
	head = node->parent;
	if (head->left == node)
		return (head->right);
	else
		return (head->left);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: Pointer to the node
 *
 * Return: Pointer to the uncle of the node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *head = malloc(sizeof(binary_tree_t));

	if (node == NULL || node->parent == NULL)
	{
		free(head);
		return (NULL);
	}
	head = node->parent;
	return (binary_tree_sibling(head));
}
