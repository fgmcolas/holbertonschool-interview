#include "binary_trees.h"
#include "binary_tree_is_bts.c"

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the node.
 *
 * Return: Height of the tree.
 */
int height(const binary_tree_t *tree)
{
    int left, right;

    if (!tree)
        return (-1); /* Changed from 0 to -1 for correct balance factor */

    left = height(tree->left);
    right = height(tree->right);

    return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the node.
 *
 * Return: Balance factor of the node.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (height(tree->left) - height(tree->right));
}

/**
 * preorder_balance - Checks balance for each node using pre-order traversal.
 * @t: Pointer to the root tree.
 * @f: Pointer to function that checks balance.
 *
 * Return: 1 if balanced, 0 otherwise.
 */
int preorder_balance(const binary_tree_t *t, int (*f)(const binary_tree_t *))
{
    if (!t)
        return (1);

    if (f(t) > 1 || f(t) < -1)
        return (0);

    return (preorder_balance(t->left, f) && preorder_balance(t->right, f));
}

/**
 * binary_tree_is_avl - Determines if a tree is AVL.
 * @tree: Pointer to the root.
 *
 * Return: 1 if tree is AVL, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!binary_tree_is_bst(tree))
        return (0);

    return (preorder_balance(tree, &binary_tree_balance));
}
