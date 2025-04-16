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


def test_case_generator() -> None:
    random_vals = [[] * 15 for _ in range(15)]
    for i in range(5):
        random_vals[i].append(random.randint(1, 10))
        random_vals[i].append([random.randint(1, 100) for _ in range(random_vals[i][0])])
    for i in range(5, 10):
        random_vals[i].append(random.randint(10, 100))
        random_vals[i].append([random.randint(1, 1_000) for _ in range(random_vals[i][0])])
    for i in range(10, 15):
        random_vals[i].append(random.randint(100, 1_000))
        random_vals[i].append([random.randint(100, 1_000) for _ in range(random_vals[i][0])])

    print(random_vals, sep='\n')
    # for index, val in enumerate(random_vals):
    #     print(index, val)
    for index, val in enumerate(random_vals):
        with open('input' + str(index) + '.txt', 'w') as file:
            file.write(str(val[0]))
            file.write('\n')
            for i in val[1]:
                file.write(str(i))
                file.write(' ')

        with open('output' + str(index) + '.txt', 'w') as file:
            for i in val[1]:
                for num in lexicographical_order(i):
                    file.write(str(num))
                    file.write(' ')
                file.write('\n')


test_case_generator()

