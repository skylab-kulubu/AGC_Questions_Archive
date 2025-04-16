# 1 - iki sesli harf yan yana gelmemeli  +++++++
# 3 - bir cümle max 4 kelime olabilir.+++++
# 4 - bir kelime max 7 harf olabilir. +++++
# 6 - toplam 30 kelime geçilmemeli. ++++++
# 7 - sadece alfanumerik karakterler harften sayiliyor +++++
# 8 - parantez dengesi gozetilecek +++++
# ------------------------------------------------------------------
#
# 1 - iki sesli harf
# 2 - cumle max 4 kelime
# 3 - kelime max 7 harf

# string = '{alaah}wdkwad. k(dj)adkwad, jah(dwak(d, aduoaw[d, awhbdakw. kljawhdw]ad.'

string = 'baris kaan nilay algolab. secim ucube kaan reis.'
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
    words_list = inp.split(' ')
    words_list = list(filter(None, words_list))
    return words_list


def sentences_array(inp: str) -> list[str]:
    global errors
    words_in_sentence = inp.split('. ')
    words_in_sentence = list(filter(None, words_in_sentence))
    return words_in_sentence


def count_letters(inp: str) -> None:
    global errors
    if len(inp) > 7:
        errors += 1


def text_editor(inp):
    global errors

    sentences_list = sentences_array(inp)
    # print(f'sentences: {sentences_list}')

    for sentence in sentences_list:
        words = words_array(sentence)
        if len(words) > 4:
            errors += 1

    words_list = words_array(inp)
    # print(f'words: {words_list}')

    if len(words_list) > 30:
        errors += 1

    temp_words_list = [x.translate(str.maketrans('', '', '(){}[],.')) for x in words_list]
    # print(temp_words_list)

    for word in temp_words_list:
        vow_func(word)
        if len(word) > 7:
            errors += 1


def test_cases():
    phrases = [
        'Algorithms Games Challenge is the best around.',                                               # 4
        'Beauty is in the eyes of the beholder. Skating is so much fun.',                               # 5
        'He owes me a lot.',                                                                            # 1
        "I would like to check your blood pressure. She is my mother. We closed the deal successfully.",# 8
        'She had eleven brothers and sisters.',                                                         # 2
        'What are your favorite candies. There are so many things to consider.'                         # 6
    ]
    # for phrase in phrases:
    #     global errors
    #     text_editor(phrase)
    #     print(errors)
    #     errors = 0

    for index, val in enumerate(phrases):
        global errors
        with open('input'+str(index)+'.txt', 'w') as file:
            file.write(val)
        
        with open('output'+str(index)+'.txt', 'w') as file:
            text_editor(val)
            file.write(str(errors))
            errors = 0

if __name__ == '__main__':
    # text_editor(string)
    # print(errors)
    # print('hello world')
    test_cases()

