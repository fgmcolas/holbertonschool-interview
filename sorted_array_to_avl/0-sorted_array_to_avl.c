#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * add_node - Recursively creates an AVL tree node from a sorted array
 *
 * @array: Pointer to the portion of the array to be used
 * @size: Size of the current portion of the array
 * @parent: Pointer to the parent node of the new node
 *
 * Return: Pointer to the newly created AVL tree node, or NULL on failure
 */

binary_tree_t *add_node(int *array, size_t size, avl_t *parent)
{
	binary_tree_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[(size - 1) / 2];
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;

	if (size > 1)
	{
		node->right = add_node(array + (size + 1) / 2, size / 2, node);
		if (node->right == NULL)
			return (NULL);
	}
	if (size > 2)
	{
		node->left = add_node(array, (size - 1) / 2, node);
		if (node->right == NULL)
			return (NULL);
	}

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the sorted array
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	if (!size)
		return (NULL);

	return ((avl_t *)add_node(array, size, NULL));
}
