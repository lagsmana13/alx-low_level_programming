#include "search_algos.h"

/**
 * linear_search - Examines for a data in an assortment of integers using sequential search.
 * @array: A pointer to the initial element of the assortment to examine.
 * @size: The quantity of elements in the assortment.
 * @value: The data to examine for.
 *
 * Return: If the data is not present or the assortment is NULL, returns -1.
 *         Otherwise, returns the initial index where the data is located.
 *
 * Explanation: This operation executes a sequential search on the assortment by sequentially
 *              examining each element until the data is found or the end of the assortment
 *              is reached. It prints the data of each element that is compared during
 *              the search.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL) /* Validate if the assortment is NULL */
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Data examined array[%ld] = [%d]\n", i, array[i]); /* Print the data of each element that is compared */
		if (array[i] == value) /* Validate if the current element is equal to the data */
			return (i); /* Return the initial index where the data is located */
	}

	return (-1); /* Return -1 if the data is not found */
}
