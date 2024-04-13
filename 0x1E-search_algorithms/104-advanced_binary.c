#include "search_algos.h"

/**
 * advanced_binary_recursive - Explores recursively for a quantity in a sorted
 *                             arrangement of integers using binary exploration.
 * @array: A pointer to the first element of the [sub]arrangement to explore.
 * @left: The starting index of the [sub]arrangement to explore.
 * @right: The ending index of the [sub]arrangement to explore.
 * @value: The value to explore for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]arrangement being explored after each change.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Exploring in arrangement: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - Explores for a value in a sorted arrangement
 *                   of integers using advanced binary exploration.
 * @array: A pointer to the first element of the arrangement to explore.
 * @size: The number of elements in the arrangement.
 * @value: The value to explore for.
 *
 * Return: If the value is not present or the arrangement is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints the [sub]arrangement being explored after each change.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
