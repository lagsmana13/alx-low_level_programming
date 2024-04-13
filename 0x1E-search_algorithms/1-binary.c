#include "search_algos.h"

/**
 * binary_search - Hunts for a value in a sorted selection
 *                 of integers using binary search.
 * @array: A pointer to the first element of the selection to hunt.
 * @size: The number of elements in the selection.
 * @value: The value to hunt for.
 *
 * Return: If the value is not present or the selection is NULL, returns -1.
 *         Otherwise, returns the index where the value is located.
 *
 * Explanation: This function executes a binary search on the sorted selection by dividing
 *              the search range in half at each step. It prints the subselection being
 *              searched after each change.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL) /* Check if the selection is NULL */
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Hunting in subselection: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}
