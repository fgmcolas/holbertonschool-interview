#!/usr/bin/python3
""" Rainwater Trapping Between Walls """


def rain(walls):
    """
    Calculate how much water will be retained after it rains.

    Args:
        wall_heights (list): A list of non-negative integers
        representing the heights of walls of width 1.

    Returns:
        int: Total amount of water retained between the walls.
    """
    wall_count = len(walls)
    if wall_count == 0 or wall_count == 1 or wall_count == 2:
        return 0

    total_water = 0
    while wall_count >= 3:
        sorted_heights = walls.copy()
        sorted_heights.sort()
        highest_wall = sorted_heights[-1]
        hightest_wall2 = sorted_heights[-2]
        highest_index = walls.index(highest_wall)
        hightest_index2 = walls.index(hightest_wall2)
        if highest_index == hightest_index2:
            hightest_index2 = walls.index(hightest_index2, highest_index + 1)
        indices = [highest_index, hightest_index2]
        indices.sort()
        lower_wall_height = min(walls[indices[0]], walls[indices[1]])
        for i in range(indices[0] + 1, indices[1]):
            total_water += lower_wall_height - walls[i]
        for i in range(indices[0], indices[1] + 1):
            del walls[indices[0]]
        walls.insert(indices[0], lower_wall_height)
        wall_count = len(walls)

    return total_water
