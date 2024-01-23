#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1, size);
}

/**
 * merge_sort_recursive - Recursive helper function for Merge Sort
 * @array: The array to be sorted
 * @left: Left index of the sub-array
 * @right: Right index of the sub-array
 * @size: Number of elements in the array
 */
void merge_sort_recursive(int *array, size_t left, size_t right, size_t size)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;

        /* Recursively sort the left and right sub-arrays */
        merge_sort_recursive(array, left, middle, size);
        merge_sort_recursive(array, middle + 1, right, size);

        /* Merge the sorted sub-arrays */
        merge_arrays(array, left, middle, right, size);
    }
}

/**
 * merge_arrays - Merges two sorted sub-arrays into a single sorted array
 * @array: The array containing the sub-arrays
 * @left: Left index of the first sub-array
 * @middle: Right index of the first sub-array and left index of the second sub-array
 * @right: Right index of the second sub-array
 * @size: Number of elements in the array
 */
void merge_arrays(int *array, size_t left, size_t middle, size_t right, size_t size)
{
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    int *left_array = malloc(n1 * sizeof(int));
    int *right_array = malloc(n2 * sizeof(int));

    if (left_array == NULL || right_array == NULL)
    {
        free(left_array);
        free(right_array);
        return;
    }

    /* Copy data to temporary arrays left_array[] and right_array[] */
    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];

    for (j = 0; j < n2; j++)
        right_array[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    /* Merge the two sub-arrays back into the original array */
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }

    /* Copy the remaining elements of left_array[], if any */
    while (i < n1)
        array[k++] = left_array[i++];

    /* Copy the remaining elements of right_array[], if any */
    while (j < n2)
        array[k++] = right_array[j++];

    /* Print the array after each merge operation */
    print_array(array, size);

    /* Free the dynamically allocated memory */
    free(left_array);
    free(right_array);
}
