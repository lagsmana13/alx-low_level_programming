#include "search_algos.h"

/**
  * lookup_linear - Finds a number in a series
  *                 of digits using lookup linear.
  * @series: A reference to the starting element of the series to find.
  * @count: The quantity of digits in the series.
  * @number: The number to find.
  *
  * Return: If the number is absent or the series is NULL, -1.
  *         Otherwise, the primary position where the number is found.
  *
  * Explanation: Displays a number each time it is evaluated in the series.
  */
int lookup_linear(int *series, size_t count, int number)
{
	size_t j;

	if (series == NULL)
		return (-1);

	for (j = 0; j < count; j++)
	{
		printf("Number evaluated series[%ld] = [%d]\n", j, series[j]);
		if (series[j] == number)
			return (j);
	}

	return (-1);
}
