#!/usr/bin/python3
"""Interview problems involving lockboxes."""
from itertools import dropwhile


def canUnlockAll(boxes):
    """Determines if all boxes can be unlocked.

    Args:
        boxes (list of lists): A list where each element is a list representing
        the keys contained in each box.

    Returns:
        bool: True if all boxes can be unlocked, otherwise False.
    """

    keys = {0}
    range_boxes = range(len(boxes))

    while True:
        not_found = set()

        for i in range_boxes:
            if i in keys:
                for key in dropwhile(lambda k: k in keys, boxes[i]):
                    keys.add(key)
            else:
                not_found.add(i)

        if range_boxes == not_found:
            return False

        if not not_found:
            return True

        range_boxes = not_found
