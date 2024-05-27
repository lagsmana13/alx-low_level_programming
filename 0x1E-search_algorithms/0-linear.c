#include "search_algos.h"

/**
 * lookup_linear - Finds number in series of digits using the Lookup linear method
 *
 * @series: Series to find
 *
 * @count: Count of the series
 *
 * @number: Number to find
 *
 * Return: Primary position where number is found or -1 for NULL series
 */

int lookup_linear(int *series, size_t count, int number)
{
	unsigned int position;

	for (position = 0; series && position < count; position++)
	{
		printf("Number evaluated series[%d] = [%d]\n", position, series[position]);

		if (series[position] == number)
		{
			return (position);
		}
	}
	return (-1);
}
