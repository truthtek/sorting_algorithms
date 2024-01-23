#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to know the number of digits */
    int max_num = find_max(array, size);

    /* Do counting sort for every digit, starting from the least significant */
    for (int exp = 1; max_num / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort_radix - Performs counting sort on an array based on a significant digit
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current significant digit (power of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    if (output == NULL)
        return;

    /* Count occurrences of each digit in the current significant place */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Modify count array to store the position of each digit in the output array */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array by placing elements in their correct position */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the sorted output array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    /* Free the dynamically allocated memory */
    free(output);
}

/**
 * find_max - Finds the maximum number in an array
 * @array: The array to find the maximum number from
 * @size: Number of elements in the array
 * Return: The maximum number in the array
 */
int find_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
