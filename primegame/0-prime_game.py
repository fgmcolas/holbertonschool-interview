#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Determines the winner of each round and returns the player
    with the most wins.
    """
    if not nums or x < 1 or len(nums) != x:
        return None

    max_n = max(nums)
    # Generate prime numbers using Sieve of Eratosthenes
    sieve = [True] * (max_n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(max_n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, max_n + 1, i):
                sieve[j] = False

    # Precompute number of primes up to each n
    primes_up_to = [0] * (max_n + 1)
    count = 0
    for i in range(1, max_n + 1):
        if sieve[i]:
            count += 1
        primes_up_to[i] = count

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n < 1:
            continue  # Skip invalid rounds
        if primes_up_to[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
