#include "sort.h"

/**
 * merge - Merges two subarrays in a bitonic sequence
 *
 * @array: Pointer to the array
 * @low: Starting index of the first subarray
 * @count: Number of elements to merge
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                print_array(array, count);
            }
        }

        merge(array, low, k, dir);
        merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort
 *
 * @array: Pointer to the array
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, low, k, !dir);
        bitonic_sort_recursive(array, low + k, k, dir);
        merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
