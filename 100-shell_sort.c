#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 *               with the Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate the initial gap using Knuth sequence */
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ;

    while (gap > 0)
    {
        /* Perform insertion sort with the calculated gap */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        /* Reduce the gap for the next iteration */
        gap = (gap - 1) / 3;

        /* Print the array after each decrease in the interval */
        print_array(array, size);
    }
}
