#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    if not nums or x < 1:
        return None

    max_num = max(nums)

    # Sieve of Eratosthenes
    primes = [True for _ in range(max_num + 1)]
    primes[0] = primes[1] = False

    for i in range(2, int(max_num ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, max_num + 1, i):
                primes[j] = False

    # Precompute number of primes up to each i
    prime_count = [0] * (max_num + 1)
    count = 0
    for i in range(1, max_num + 1):
        if primes[i]:
            count += 1
        prime_count[i] = count

    # Play the game
    maria = ben = 0
    for n in nums:
        if prime_count[n] % 2 == 0:
            ben += 1
        else:
            maria += 1

    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    return None
