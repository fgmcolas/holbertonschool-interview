#!/usr/bin/python3
"""
Solves the N-Queens problem using backtracking
"""

import sys


def print_usage_and_exit():
    """Print usage message and exit with status 1"""
    print("Usage: nqueens N")
    exit(1)


def print_error_and_exit(message):
    """Print error message and exit with status 1"""
    print(message)
    exit(1)


if len(sys.argv) != 2:
    print_usage_and_exit()

try:
    N = int(sys.argv[1])
except ValueError:
    print_error_and_exit("N must be a number")

if N < 4:
    print_error_and_exit("N must be at least 4")


def solve_nqueens(N):
    """Solve the N-Queens problem and print all solutions"""
    def is_safe(board, row, col):
        """Check if placing a queen at board[row][col] is safe"""
        for i in range(col):
            if board[row][i]:
                return False
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j]:
                return False
        for i, j in zip(range(row, N), range(col, -1, -1)):
            if board[i][j]:
                return False
        return True

    def solve(col, board, solutions):
        """Backtracking utility to place queens"""
        if col == N:
            solutions.append([[i, row.index(1)]
                             for i, row in enumerate(board)])
            return
        for row in range(N):
            if is_safe(board, row, col):
                board[row][col] = 1
                solve(col + 1, board, solutions)
                board[row][col] = 0

    board = [[0] * N for _ in range(N)]
    solutions = []
    solve(0, board, solutions)
    for solution in solutions:
        print(solution)


solve_nqueens(N)
