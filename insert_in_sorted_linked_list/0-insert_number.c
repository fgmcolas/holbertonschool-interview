#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a new node with a given number into a sorted singly linked list.
 * @head: A double pointer to the head of the linked list, allowing modification of the list's head.
 * @number: The integer value to be stored in the new node and inserted into the list.
 *
 * Description: This function creates a new node with the specified number and inserts it into the
 *              correct position in the linked list, maintaining the list's sorted order. If the list
 *              is empty or the new node should be inserted before the current head, the new node becomes
 *              the new head. Otherwise, it is inserted in the appropriate position within the list.
 *
 * Return: Address of the newly created node if the insertion is successful; otherwise, returns NULL
 *         if memory allocation fails.
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;

    while (current && current->next && current->next->n < number)
        current = current->next;

    if ((current == NULL) || (number < current->n))
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        new->next = current->next;
        current->next = new;
    }

    return (new);
}