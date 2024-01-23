#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build a max heap */
    build_max_heap(array, size);

    /* Extract elements from the heap one by one */
    for (size_t i = size - 1; i > 0; i--)
    {
        /* Swap the root (maximum value) with the last element */
        swap(&array[0], &array[i]);
        print_array(array, size);

        /* Restore the max heap property */
        heapify(array, i, 0);
    }
}

/**
 * build_max_heap - Builds a max heap from the given array
 * @array: The array to be converted to a max heap
 * @size: Number of elements in the array
 */
void build_max_heap(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
}

/**
 * heapify - Maintains the max heap property by fixing a single violation
 * @array: The array representing the max heap
 * @size: Number of elements in the array
 * @root: The root index of the subtree
 */
void heapify(int *array, size_t size, size_t root)
{
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    if (left_child < size && array[left_child] > array[largest])
        largest = left_child;

    if (right_child < size && array[right_child] > array[largest])
        largest = right_child;

    if (largest != root)
    {
        /* Swap the root with the largest element */
        swap(&array[root], &array[largest]);
        print_array(array, size);

        /* Recursively heapify the affected subtree */
        heapify(array, size, largest);
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
