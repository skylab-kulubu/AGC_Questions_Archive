import random


def lexicographical_order(n: int) -> list[int]:
    """
    Returns the lexicographical order of an array of integers up to nth element.

    >>> lexicographical_order(12)
    [1, 10, 11, 12, 2, 3, 4, 5, 6, 7, 8, 9]

    :param n: Final element of the integer array.
    :type n: int
    :return: Array of integers up to nth element.

    """
    return sorted((n for n in range(1, n+1)), key=str)