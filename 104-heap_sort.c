#include "sort.h"

/**
 * sift_down - Performs the sift-down operation on a heap
 *
 * @array: Pointer to the array
 * @size: Size of the heap
 * @root: Root index of the heap
 * @end: Last index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
size_t max = root;
size_t left_child = 2 * root + 1;
size_t right_child = 2 * root + 2;
if (left_child < end && array[left_child] > array[max])
max = left_child;
if (right_child < end && array[right_child] > array[max])
max = right_child;
if (max != root)
{
int temp = array[root];
array[root] = array[max];
array[max] = temp;
print_array(array, size);
sift_down(array, size, max, end);
}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
size_t i;
if (array == NULL || size < 2)
return;
for (i = size / 2; i > 0; i--)
sift_down(array, size, i - 1, size);
for (i = size - 1; i > 0; i--)    {
int temp = array[0];
array[0] = array[i];
array[i] = temp;
print_array(array, size);
sift_down(array, size, 0, i);
}
}
