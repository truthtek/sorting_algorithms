#include "sort.h"

/**
 * partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be sorted
 * @min: Minimum index of the partition
 * @max: Maximum index of the partition
 * @size: Size of the array to be sorted
 * Return: Index + 1
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[max];
	i = min - 1;

	for (j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}

	if (array[max] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swap;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Recursively sorts an array using Quick Sort
 * @array: Array to be sorted
 * @min: Minimum index of the partition
 * @max: Maximum index of the partition
 * @size: Size of the array to be sorted
 */
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = partition(array, min, max, size);
		quicksort(array, min, pivot - 1, size);
		quicksort(array, pivot + 1, max, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
