#!/usr/bin/python3
"""Script to get stats from a request"""
import sys


def print_stats(size, codes):
    """Prints the accumulated statistics."""
    print(f"File size: {size}")
    for code in sorted(codes):
        print(f"{code}: {codes[code]}")


# Initialize variables
total_size = 0
count = 0
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
codes = {code: 0 for code in status_codes}

try:
    # Read lines from stdin
    for line in sys.stdin:
        # Ensure the line follows the expected format
        parts = line.split()

        # Validate format (minimum number of parts and valid structure)
        if len(parts) < 7 or parts[5] != '"GET' or parts[6] != '/projects/260' or parts[7] != 'HTTP/1.1"':
            continue  # Skip invalid lines

        # Extract status code and file size
        try:
            status_code = parts[-2]
            file_size = int(parts[-1])
        except (ValueError, IndexError):
            continue  # Skip lines with invalid status code or file size

        # Accumulate file size
        total_size += file_size

        # Count valid status codes
        if status_code in codes:
            codes[status_code] += 1

        # Increment line counter
        count += 1

        # Every 10 lines, print the statistics
        if count == 10:
            print_stats(total_size, codes)
            count = 0

# Handle keyboard interruption (CTRL+C)
except KeyboardInterrupt:
    print_stats(total_size, codes)
    raise

# Print final stats when input ends
print_stats(total_size, codes)
