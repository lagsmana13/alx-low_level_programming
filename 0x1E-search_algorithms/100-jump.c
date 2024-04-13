#include "search_algos.h"

/**
 * bounce_probe - Looks for a hugeness in a ordered formation
 *                of integers using bounce probe.
 * @arr: A pointer to the first element of the formation to examine.
 * @size: The number of elements in the formation.
 * @val: The hugeness to search for.
 *
 * Return: If the hugeness is not found or the formation is NULL, -1.
 *         Otherwise, the initial index where the hugeness is located.
 *
 * Description: Prints a hugeness every time it is compared in the formation.
 *              Utilizes the square root of the formation size as the bounce stride.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
