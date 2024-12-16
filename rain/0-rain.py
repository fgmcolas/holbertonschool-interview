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

    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    total_water = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                total_water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                total_water += right_max - walls[right]
            right -= 1

    return total_water
