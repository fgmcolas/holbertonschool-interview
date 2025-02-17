#!/usr/bin/python3
"""Module used to add two arrays."""


def makeChange(coins, total):
    """[Given a pile of coins of different values, determine the fewest number
            of coins needed to meet a given amount total]

    Args:
            coins ([list]): [list of the values of your the coins]
                              The value of a coin will always be an int > 0
            total ([type]): [description]

    Returns:
            c [int]: (change  [fewest number of coins needed to meet total]
    """

    if total <= 0:
        return 0

    # Verify coins is a valid
    if (coins is None or len(coins) == 0):
        return -1

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
