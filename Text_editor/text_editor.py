errors = 0

def vow_func(inp: str) -> int:
    vowels = ['a', 'e', 'i', 'o', 'u']
    global errors
    for i in range(len(inp) - 1):
        j = i + 1
        if inp[i] in vowels and inp[j] in vowels:
            errors += 1
    return errors


def words_array(inp: str) -> list[str]:
    """
        Splits inp using delimiter as " ", it creates words list of the sentence in other words.

        :>>> words_array("an example sentence")
        ["an" "example" "sentence"]

        :param inp: The sentence to create words list
        :type inp: str
        :return: The list includes words, list[str]
    """
    words_list = inp.split(' ')
    words_list = list(filter(None, words_list))
    return words_list


def sentences_array(inp: str) -> list[str]:
    """
        Splits inp using delimiter as ". ", it creates sentences list of the input in other words.

        :>>> sentences_array("an example sentence. the second example sentence.")
        ["an example sentence", "the second example sentence."]

        :param inp: The input to create sentences list
        :type inp: str
        :return: The list includes sentences, list[str]
    """

    global errors
    words_in_sentence = inp.split('. ')
    words_in_sentence = list(filter(None, words_in_sentence))
    return words_in_sentence


def count_letters(inp: str) -> None:
    """
        Increase global errors variable by 1 if inp length is longer than 7

        :>>> count_letters("simple text")
        None

        :param inp: The input will be checked
        :type inp: str
        :return: None
    """

    global errors
    if len(inp) > 7:
        errors += 1


def text_editor(inp: str) -> None:
    """
        Checks the input and counts errors.
        Errors:
        + If a sentence includes more than 4 words,
        + If the total words of input is more than 30,
        + If the length of a word is more than 7,
        + If the vowel groups includes more than one vowel in the string (for example, "ateasdoea" is considered as includes two errors)
        They are counted as errors.

        :param inp: The input will be checked
        :type inp: str
        :return: None
    """

    global errors

    sentences_list = sentences_array(inp)

    for sentence in sentences_list:
        words = words_array(sentence)
        if len(words) > 4:
            errors += 1

    words_list = words_array(inp)

    if len(words_list) > 30:
        errors += 1

    temp_words_list = [x.translate(str.maketrans('', '', '(){}[],.')) for x in words_list]

    for word in temp_words_list:
        vow_func(word)

        if len(word) > 7:
            errors += 1

if __name__ == "__main__":
    text_editor(input())
    print(errors)
