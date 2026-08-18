#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (-1);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * perfect_check - Checks if all leaves are at the same level
 * @tree: Pointer to the current node
 * @level: Current level
 * @height: Height of the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
static int perfect_check(const binary_tree_t *tree, int level, int height)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == height);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, level + 1, height)
		&& perfect_check(tree->right, level + 1, height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);

	return (perfect_check(tree, 0, height));
}
