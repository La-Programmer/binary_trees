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

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Balance factor of the binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int result;
	int l_height = 0;
	int r_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		l_height = 1 + (int)binary_tree_height(tree->left);
	if (tree->right != NULL)
		r_height = 1 + (int)binary_tree_height(tree->right);

	result = l_height - r_height;
	return (result);
}
