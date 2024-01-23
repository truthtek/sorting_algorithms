#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Cocktail Shaker Sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *temp;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        /* Forward pass */
        swapped = 0;
        temp = *list;

        while (temp->next != NULL)
        {
            if (temp->n > temp->next->n)
            {
                swap_nodes(temp, temp->next, list);
                swapped = 1;

                /* Print the list after each swap */
                print_list(*list);
            }
            else
            {
                temp = temp->next;
            }
        }

        /* Backward pass */
        if (!swapped)
            break;

        swapped = 0;
        while (temp->prev != NULL)
        {
            if (temp->n < temp->prev->n)
            {
                swap_nodes(temp->prev, temp, list);
                swapped = 1;

                /* Print the list after each swap */
                print_list(*list);
            }
            else
            {
                temp = temp->prev;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: Left node to be swapped
 * @right: Right node to be swapped
 * @list: Pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
    if (left->prev != NULL)
        left->prev->next = right;
    else
        *list = right;

    if (right->next != NULL)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;
}
