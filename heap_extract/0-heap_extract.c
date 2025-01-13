#include "binary_trees.h"

/**
 * bt_height - Get the height of a binary tree
 * @tree: Pointer to the tree node
 * Return: Height of the tree
 */
static size_t bt_height(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	h_left = tree->left ? 1 + bt_height(tree->left) : 0;
	h_right = tree->right ? 1 + bt_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * bt_preorder - Pre-order traversal to find a node at a specific level
 * @root: Pointer to tree root
 * @node: Pointer to store the found node
 * @h: Target height
 * @l: Current layer
 */
void bt_preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		bt_preorder(root->left, node, h, l);
	if (root->right)
		bt_preorder(root->right, node, h, l);
}

/**
 * bt_sorting - Restore heap property by sorting
 * @tmp: Pointer to the heap root
 * Return: Pointer to the last node
 */
heap_t *bt_sorting(heap_t *tmp)
{
	int aux;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = aux;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = aux;
			tmp = tmp->right;
		}
	}
	return (tmp);
}

/**
 * heap_extract - Remove and return the root value of a Max Heap
 * @root: Pointer to the heap root
 * Return: Value of the removed root
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	bt_preorder(tmp, &node, bt_height(tmp), 0);
	tmp = bt_sorting(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
