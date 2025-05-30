import time

def elimination(bullet_count: int, bullets: list[int], people_count: int) -> None:
    """
        This function simulates a game where people are eliminated based on bullets.
        The bullets are represented as an array, where 0 means the bullet is not used and 1 means it is used.
        The function iterates through the people and bullets, eliminating people based on the bullets used.
        The last person remaining is printed.

        :param bullet_count: shows bullet chamber count
        :type bullet_count: int

        :param bullets: determines which bullets exists or not, value 1 means that bullet exists, value 0 means that bullet does not exist
        :type bullets: list[int]

        :param people_count: shows player count in the game
        :type people_count: int

        :return: number of last remaining player
    """

    people = set(range(1, int(people_count + 1)))

    # i represents index of bullets, j represents index of people
    i, j = 0, 0

    while len(people) > 1:
        j %= len(people)

        it = iter(people)
        for _ in range(j):
            next(it)

        i = i % bullet_count
        if bullets[i] == 0:
            bullets[i] = 1
        else:
            bullets[i] = 0
            people.remove(next(it))
            j -= 1

        i += 1
        j += 1

    return next(iter(people))

if __name__ == "__main__":
    bullet_count = int(input())
    bullets = []

    for _ in range(bullet_count):
        bullets.append(int(input()))
    
    people_count = int(input())
    print(f"Last remaining player: {elimination(bullet_count, bullets, people_count)}")

#agcsoru4(3, [1, 0, 1], 3319, 4)
