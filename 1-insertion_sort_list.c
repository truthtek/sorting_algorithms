#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion sort
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *key, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        key = current;
        prev = key->prev;

        while (prev != NULL && prev->n > key->n)
        {
            /* Swap nodes */
            if (key->next != NULL)
                key->next->prev = prev;
            prev->next = key->next;
            key->prev = prev->prev;
            key->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = key;
            else
                *list = key;
            prev->prev = key;

            print_list(*list);

            prev = key->prev;
        }

        current = current->next;
    }
}
