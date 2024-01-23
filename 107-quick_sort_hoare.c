#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick Sort algorithm with Hoare partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursive helper function for Quick Sort (Hoare partition scheme)
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in the array
 */
void quicksort_hoare(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        ssize_t pivot = hoare_partition(array, low, high, size);

        /* Recursively sort the two sub-arrays */
        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Performs the Hoare partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in the array
 * Return: The final position of the pivot element
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1;
    ssize_t j = high + 1;

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

        if (i < j)
        {
            /* Swap elements if not in the desired order */
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
        else
        {
            /* Return the final position of the pivot element */
            return j;
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
