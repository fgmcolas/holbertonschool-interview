#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""
import sys
import signal

# Initialize global variables
total_file_size = 0
status_code_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}
line_count = 0


def print_statistics():
    """
    Prints the current statistics.
    """
    print("File size: {}".format(total_file_size))
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print("{}: {}".format(code, status_code_counts[code]))


def signal_handler(sig, frame):
    """
    Prints the stats obtained from the file when a keyboard interrupt occurs.
    """
    print_statistics()


# Register the signal handler for SIGINT
signal.signal(signal.SIGINT, signal_handler)
try:
    for line in sys.stdin:
        line_count += 1
        line_parsed = line.split()
        length_line = len(line_parsed)
        if length_line < 2:
            continue
        total_file_size += int(line_parsed[length_line - 1])
        if line_parsed[length_line - 2] not in status_code_counts.keys():
            continue
        status_code_counts[line_parsed[length_line - 2]] += 1
        if line_count % 10 == 0:
            print_statistics()
finally:
    print_statistics()
