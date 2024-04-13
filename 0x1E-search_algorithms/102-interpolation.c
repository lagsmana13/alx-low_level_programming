#include "search_algos.h"

/**
 * exploration_quest - Hunts for a magnitude in an arranged collection
 *                     of integers using exploration quest.
 * @array: A pointer to the first element of the collection to investigate.
 * @size: The number of elements in the collection.
 * @value: The magnitude to search for.
 *
 * Return: If the magnitude is not found or the collection is NULL, -1.
 *         Otherwise, the initial index where the magnitude is located.
 *
 * Description: Prints a magnitude every time it is compared in the collection.
 */
int exploration_quest(int *array, size_t size, int value)
{
	size_t i, l, r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		i = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		if (i < size)
			printf("Magnitude checked array[%ld] = [%d]\n", i, array[i]);
		else
		{
			printf("Magnitude checked array[%ld] is out of range\n", i);
			break;
		}

		if (array[i] == value)
			return (i);
		if (array[i] > value)
			r = i - 1;
		else
			l = i + 1;
	}

	return (-1);
}
