#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Enter a string: ");
    float L, S;
    //average num of letters per 100 words
    //struggles with this - get inconsisitent results with converting to the return values to float
    L = ((float)count_letters(text) / (float)count_words(text)) * 100;
    S = ((float)count_sentences(text) / (float)count_words(text)) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //printf("Text: %s\n", text);
    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));

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
}

int count_letters(string text)
{
    int lettercount = 0;
    int len = strlen(text);
    //covert to upper for simplicity
    for (int i = 0; i < len; i++)
    {
        text[i] = toupper(text[i]);
    }
    //count all letters
    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            lettercount++;
        }
    }
    return lettercount;
}

int count_words(string text)
{
    int wordcount = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            wordcount++;
        }
    }
    wordcount++; //add last word -- not sure if this is logical
    return wordcount;
}

int count_sentences(string text)
//counting all sentences by punctutation based on instructions
//contains bugs - of course
{
    int sentencecount = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencecount++;
        }
    }
    //wordcount++; //add last word -- not sure if this is logical

    return sentencecount;
}
