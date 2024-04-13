#include "search_algos.h"

/**
 * _binary_search - Hunts for a quantity in a sorted arrangement
 *                  of integers using binary hunt.
 * @array: A pointer to the first element of the arrangement to hunt.
 * @left: The starting index of the [sub]arrangement to hunt.
 * @right: The ending index of the [sub]arrangement to hunt.
 * @value: The value to hunt for.
 *
 * Return: If the value is not present or the arrangement is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]arrangement being hunted after each change.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in arrangement: ");
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

/**
 * exponential_search - Hunts for a value in a sorted arrangement
 *                      of integers using exponential hunt.
 * @array: A pointer to the first element of the arrangement to hunt.
 * @size: The number of elements in the arrangement.
 * @value: The value to hunt for.
 *
 * Return: If the value is not present or the arrangement is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the arrangement.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
