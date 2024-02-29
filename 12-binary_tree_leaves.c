#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaf nodes of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaf nodes
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
			counter++;
		counter += binary_tree_leaves(tree->left);
		counter += binary_tree_leaves(tree->right);
	}
	return (counter);
}
