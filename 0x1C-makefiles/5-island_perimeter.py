#!/usr/bin/python3
"""Defines a function to calculate the perimeter of an island."""


def island_perimeter(grid):
    """Return the perimeter of an island.

    The grid represents water with 0 and land with 1.

    Args:
        grid (list): A list of lists of integers representing an island.
    Returns:
        The perimeter of the island defined in the grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    # Iterate over each cell in the grid
    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                # Check neighboring cells
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1

    # Calculate the perimeter using the formula
    return size * 4 - edges * 2
