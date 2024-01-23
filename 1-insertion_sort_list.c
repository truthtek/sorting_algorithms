#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion Sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current)
{
temp = current->next;
while (current->prev && current->n < current->prev->n)
{
/* Swap nodes */
current->prev->next = current->next;
if (current->next)
current->next->prev = current->prev;
current->next = current->prev;
current->prev = current->prev->prev;
current->next->prev = current;
if (current->prev)
current->prev->next = current;
else
*list = current;
/* Print the list after each swap */
print_list(*list);
}
current = temp;
}
}
