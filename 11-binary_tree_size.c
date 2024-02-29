#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of the binary tree
 *
 * @tree: The pointer to the root node of the tree
 *
 * Return: Nothing
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{
		counter++;
		counter += binary_tree_size(tree->left);
		counter += binary_tree_size(tree->right);
	}
	return (counter);
}
