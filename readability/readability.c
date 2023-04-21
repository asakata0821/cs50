#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade(int result_of_letters, int result_of_words, int result_of_sentences);

int main(void)
{
    string text = get_string("Text: ");
    int result_of_letters = 0, result_of_words = 0, result_of_sentences = 0;

    result_of_letters = count_letters(text);
    result_of_words = count_words(text);
    result_of_sentences = count_sentences(text);

    int index = grade(result_of_letters, result_of_words, result_of_sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}

int count_letters(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
        if (isalpha(text[i]))
        {
            count++;
        }

    return count;
}

int count_words(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int j = 0; j < length; j++)
        if (isspace(text[j]))
        {
            count++;

        }

    return count + 1;
}

int count_sentences(string text)
{
    int length = strlen(text);
    int count = 0;
    int k;

    for (k = 0; k < length; k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            count++;
        }
    }
    return count;
}

int grade(int result_of_letters, int result_of_words, int result_of_sentences)
{
    float L, S, index;
    L = (float) result_of_letters / (float)result_of_words * 100;
    S = (float) result_of_sentences / (float)result_of_words * 100;

    index = round((0.0588 * L) - (0.296 * S) - (15.8));
    int grade = (index);

    return grade;
}