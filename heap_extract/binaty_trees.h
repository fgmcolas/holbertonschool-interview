#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Node of a binary tree
 * @n: Integer in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s heap_t;

/* Functions for binary tree operations */
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int heap_extract(heap_t **root);

/* Printing function */
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
