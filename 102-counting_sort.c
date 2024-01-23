#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Populate the counting array with the frequency of each element */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Update the original array with sorted values */
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (counting_array[i] > 0)
        {
            array[j++] = i;
            counting_array[i]--;
        }
    }

    /* Free the dynamically allocated counting array */
    free(counting_array);
}
