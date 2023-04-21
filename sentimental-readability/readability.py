from cs50 import get_string


def main():
    text = get_string("Text: ").lower()

    result_of_letters = count_letters(text)
    result_of_words = count_words(text)
    result_of_sentences = count_sentences(text)
    index = grade(result_of_letters, result_of_words, result_of_sentences)

    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print("Grade ", index)

    return 0
    

def count_letters(text):
    length = len(text)
    count = 0

    for i in range(length):
        if text[i].isalpha() == True:
            count += 1
    return count


def count_words(text):
    length = len(text)
    count = 0

    for j in range(length):
        if text[j].isspace() == True:
            count += 1
    return count + 1


def count_sentences(text):
    length = len(text)
    count = 0

    for k in range(length):
        if text[k] in [".", "!", "?"]:
            count += 1
    print(count)
    return count


def grade(result_of_letters, result_of_words, result_of_sentences):
    L = (result_of_letters * 100) / result_of_words
    S = (result_of_sentences * 100) / result_of_words

    index = round(0.0588 * L - 0.296 * S - 15.8)
    grade = index

    return grade


main()