#include "search_algos.h"

/**
  * binary_lookup - Finds a number in an ordered series
  *                 of digits using binary lookup.
  * @series: A reference to the initial element of the series to find.
  * @count: The total digits in the series.
  * @number: The number to find.
  *
  * Return: If the number is absent or the series is NULL, -1.
  *         Otherwise, the position where the number is found.
  *
  * Explanation: Displays the [sub]series being searched after each modification.
  */
int binary_lookup(int *series, size_t count, int number)
{
	size_t j, start, end;

	if (series == NULL)
		return (-1);

	for (start = 0, end = count - 1; end >= start;)
	{
		printf("Looking in series: ");
		for (j = start; j < end; j++)
			printf("%d, ", series[j]);
		printf("%d\n", series[j]);

		j = start + (end - start) / 2;
		if (series[j] == number)
			return (j);
		if (series[j] > number)
			end = j - 1;
		else
			start = j + 1;
	}

	return (-1);
}
