#include "sort.h"

void swap_nodes(listint_t *left, listint_t *right, listint_t **head);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail Shaker Sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current, *max, *min;

    if (!list || !(*list) || (*list)->next == NULL)
        return;

    current = *list;
    do {
        while (current->next)
        {
            if (current->n > current->next->n)
                swap_nodes(current, current->next, list);
            else
                current = current->next;
        }
        max = current;

        while (current->prev != min)
        {
            if (current->n < current->prev->n)
                swap_nodes(current->prev, current, list);
            else
                current = current->prev;
        }
        min = current;
    } while (min != max);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: Left node to be swapped
 * @right: Right node to be swapped
 * @head: Pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **head)
{
    listint_t *swap1 = right->next;
    listint_t *swap2 = left->prev;

    if (swap1)
        swap1->prev = left;
    if (swap2)
        swap2->next = right;

    left->next = swap1;
    right->prev = swap2;
    left->prev = right;
    right->next = left;

    if (*head == left)
        *head = right;
    print_list(*head);
}
