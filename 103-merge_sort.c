#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 *
 * @array: Pointer to the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t i, mid;
    int *left, *right;

    if (array == NULL || size < 2)
        return;

    mid = size / 2;

    left = array;
    right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < mid; i++)
        printf("%d ", left[i]);
    printf("\n");

    printf("[right]: ");
    for (i = 0; i < size - mid; i++)
        printf("%d ", right[i]);
    printf("\n");

    merge(array, left, mid, right, size - mid);

    printf("[Done]: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
