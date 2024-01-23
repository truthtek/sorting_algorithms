#include "sort.h"

/**
 * get_max - Returns the maximum element in an array
 *
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sorts an array of integers based on a specific digit using Counting sort
 *
 * @array: Pointer to the array
 * @size: Size of the array
 * @exp: The current exponent (significant digit)
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    /* Store the count of occurrences in count[] */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Calculate the cumulative count */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i < (size_t)-1; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the sorted elements to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print the current state of the array */
    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    size_t exp;

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, size, exp);
}
