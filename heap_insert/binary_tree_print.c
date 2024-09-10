#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print_tree - Prints a binary tree in a structured way
 * @tree: Pointer to the root node of the tree to print
 * @offset: Offset used for formatting
 * @depth: Depth of the node
 * @s: Buffer to store the formatted string
 * Return: Length of the printed tree
 */

static int print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_tree(tree->left, offset, depth + 1, s);
    right = print_tree(tree->right, offset + left + width, depth + 1, s);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */

void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t i, j;
    int height = 10;

    if (!tree)
        return;
    s = malloc(height * sizeof(*s));
    if (!s)
        return;
    for (i = 0; i < (size_t)height; i++)
    {
        s[i] = malloc(255);
        if (!s[i])
            return;
        for (j = 0; j < 255; j++)
            s[i][j] = ' ';
    }
    print_tree(tree, 0, 0, s);
    for (i = 0; i < (size_t)height; i++)
    {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
