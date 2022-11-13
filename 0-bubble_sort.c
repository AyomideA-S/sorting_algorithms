#include "sort.h"

/**
 * swap - Swaps values of 2 given variables
 *
 * @arr: An array of integer values
 * @head: The first value of the array to be swapped
 * @tail: The second value of the array to be swapped
 */
void swap(int arr[], int head, int tail)
{
	int tmp;
	tmp = arr[head];
	arr[head] = arr[tail];
	arr[tail] = tmp;
}

/**
 * bubble_sort - Bubble Sort algorithm
 *
 * @array: An array of integer values
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int range, n = size;

	while(n > 1)
	{
		range = 0;
		for (int head = 0; head < size - 1; head++)
		{
			int tail = head + 1;
			if (array[head] > array[tail])
			{
				swap(array, head, tail);
				range = head;
				print_array(array, size);
			}
		}
		n = range;
	}
}
