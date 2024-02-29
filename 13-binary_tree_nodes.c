#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least a child
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of non-leaf nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{
		if ((tree->right != NULL) || (tree->left != NULL))
			counter++;
		counter += binary_tree_nodes(tree->left);
		counter += binary_tree_nodes(tree->right);
	}
	return (counter);
}
