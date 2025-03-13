#include "binary_trees.h"
#include "binary_tree_is_bts.c"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height
 **/
int height(binary_tree_t *tree)
{
    int left, right;

    if (!tree)
        return (0); // Changed from 1 to 0

    left = height(tree->left);
    right = height(tree->right);

    return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the node (use height)
 * Return: balance factor from the node
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return height(tree->left) - height(tree->right);
}

/**
 * preorder_balance - goes through a binary tree using pre-order traversal
 * @f: pointer to function that checks balance
 * @t: pointer to the root tree
 * Return: balanced 1 , unbalanced 0
 **/
int preorder_balance(const binary_tree_t *t, int (*f)(const binary_tree_t *))
{
    if (!t)
        return (1);

    if (f(t) > 1 || f(t) < -1)
        return (0);

    return preorder_balance(t->left, f) && preorder_balance(t->right, f);
}

/**
 * binary_tree_is_avl - Determine if tree is AVL
 * @tree: pointer to the root
 * Return: 1 if tree is AVL / 0 otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    if (!tree->left && !tree->right)
        return (1);
    if (!binary_tree_is_bst(tree))
        return (0);

    return preorder_balance(tree, &binary_tree_balance);
}
