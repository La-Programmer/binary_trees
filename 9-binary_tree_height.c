#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Checks the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t result = 0;
	size_t l_height = 0;
	size_t r_height = 0;

	if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
		return (0);
	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	result = 1 + (l_height > r_height ? l_height : r_height);
	return (result);
}
