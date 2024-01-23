#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array (should be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || !is_power_of_two(size))
        return;

    bitonic_recursive_sort(array, size, 1);
}

/**
 * bitonic_recursive_sort - Recursively performs Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_recursive_sort(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;

        /* Sort in ascending order */
        bitonic_recursive_sort(array, mid, 1);

        /* Sort in descending order */
        bitonic_recursive_sort(array + mid, mid, 0);

        /* Merge the two halves */
        bitonic_merge(array, size, dir);
    }
}

/**
 * bitonic_merge - Merges two halves of an array in the given direction
 * @array: The array to be merged
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k, j;

        /* Bitonic sequence generation loop */
        for (k = size / 2; k > 0; k /= 2)
        {
            /* Bitonic merge loop */
            for (j = 0; j < size; j++)
            {
                int bitonic_dir = (j / k) % 2;

                if ((bitonic_dir == dir) && (array[j] > array[j + k]))
                {
                    /* Swap elements if not in the desired order */
                    swap(&array[j], &array[j + k]);
                    print_array(array, size);
                }
            }
        }
    }
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * is_power_of_two - Checks if a number is a power of two
 * @n: The number to be checked
 * Return: 1 if true, 0 if false
 */
int is_power_of_two(size_t n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}
