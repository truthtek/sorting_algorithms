#include "sort.h"

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme
 *
 * @array: Pointer to the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 *
 * @array: Pointer to the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort algorithm (Hoare partition scheme)
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
    print_array(array, size);
}
