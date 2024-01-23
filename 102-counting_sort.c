#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count = NULL, *output = NULL;
    size_t i, max = 0;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a count array of size max + 1 */
    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    /* Initialize the count array with all elements as 0 */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the occurrences of each element in the array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the count array */
    printf("Count array: ");
    for (i = 0; i <= max; i++)
        printf("%d ", count[i]);
    printf("\n");

    /* Calculate the cumulative count */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Create an output array */
    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    /* Build the output array */
    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free the allocated memory */
    free(count);
    free(output);
}
