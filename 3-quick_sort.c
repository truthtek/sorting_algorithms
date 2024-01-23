#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive helper function for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high);

        quicksort_recursive(array, low, pivot - 1);
        quicksort_recursive(array, pivot + 1, high);
    }
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);

    return (i + 1);
}

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
