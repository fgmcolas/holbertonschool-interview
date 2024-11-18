#!/usr/bin/python3
"""Python program to solve the N-Queens problem"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)


def print_solution(board):
    """Prints one solution as a list of queen positions"""
    solution = [[i, row.index(1)] for i, row in enumerate(board)]
    print(solution)


def is_safe(board, row, col):
    """Checks if placing a queen at board[row][col] is safe"""
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


def solve_nqueens_util(board, col):
    """Recursively solves the N-Queens problem"""
    if col == N:
        print_solution(board)
        return True

    res = False
    for row in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1
            res = solve_nqueens_util(board, col + 1) or res
            board[row][col] = 0
    return res


def solve_nqueens():
    """Initializes the board and starts solving"""
    board = [[0] * N for _ in range(N)]
    solve_nqueens_util(board, 0)


solve_nqueens()
 