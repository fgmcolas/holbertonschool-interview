#!/usr/bin/python3
"""
validUTF8
"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    bytes = 0

    for num in data:

        if 191 >= num >= 128:

            if not bytes:
                return False

            bytes -= 1
        else:
            if bytes:
                return False

            if num < 128:
                continue
            elif num < 224:
                bytes = 1
            elif num < 240:
                bytes = 2
            elif num < 248:
                bytes = 3
            else:
                return False

    return bytes == 0
