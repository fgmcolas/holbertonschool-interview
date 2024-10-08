#!/usr/bin/python3
"""
A script that reads lines from standard input and computes metrics:
- Total file size from the lines
- Counts of valid status codes (200, 301, 400, 401, 403, 404, 405, 500)

After every 10 lines or upon receiving a keyboard interrupt (Ctrl + C), it prints:
- The total file size
- The count of each status code in ascending order
"""

import sys

# Initialize variables to track file size and status code counts
total_size = 0
status_codes_count = {}
valid_status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
line_count = 0

try:
    for line in sys.stdin:
        # Split the line into components
        parts = line.split()

        # Check if the line has the correct format
        if len(parts) < 7:
            continue

        # Extract file size and status code
        try:
            file_size = int(parts[-1])
            status_code = parts[-2]
        except (ValueError, IndexError):
            continue

        # Update the total file size
        total_size += file_size

        # Update the count for the status code if it's valid
        if status_code in valid_status_codes:
            if status_code in status_codes_count:
                status_codes_count[status_code] += 1
            else:
                status_codes_count[status_code] = 1

        # Increment the line count
        line_count += 1

        # Every 10 lines, print the statistics
        if line_count == 10:
            print("File size: {}".format(total_size))
            for code in sorted(status_codes_count.keys()):
                print("{}: {}".format(code, status_codes_count[code]))
            line_count = 0  # Reset line count

except KeyboardInterrupt:
    # Handle Ctrl + C: print statistics before exiting
    pass

finally:
    # Always print final statistics before exiting
    print("File size: {}".format(total_size))
    for code in sorted(status_codes_count.keys()):
        print("{}: {}".format(code, status_codes_count[code]))
