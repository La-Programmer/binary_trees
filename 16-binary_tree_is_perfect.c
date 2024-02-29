#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_complete - Checks if a node is complete
 * @node: The node to check
 *
 * Return: 1 or 0
 */

int binary_complete(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	else if ((node->left != NULL) && (node->right != NULL))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf node
 * @node: The node to check
 *
 * Return: 1 or 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to check
 *
 * Return: The depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t result = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		result++;
		tree = tree->parent;
	}
	return (result);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if true, 0 if false
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 1;
	int l_result = 1;
	int r_result = 1;
	int l_depth = 0;
	int r_depth = 0;

	if (tree == NULL)
		return (0);
	if (binary_complete(tree->left) && !binary_tree_is_leaf(tree->left))
		l_result = binary_tree_is_perfect(tree->left);
	if (binary_complete(tree->right) && !binary_tree_is_leaf(tree->right))
		r_result = binary_tree_is_perfect(tree->right);
	if (binary_tree_is_leaf(tree->left))
		l_depth = binary_tree_depth(tree->left);
	if (binary_tree_is_leaf(tree->right))
		r_depth = binary_tree_depth(tree->right);
	if (l_depth != r_depth)
		result = 0;
	result = l_result * r_result * result;
	return (result);
}
