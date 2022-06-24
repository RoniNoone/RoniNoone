#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    //convert the word to uppcase
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
    }

    //use the length to loop through chars in word
    char *curchar; //used to store current char for pos
    int pos; //used to store pos of char to compare against array
    for (int i = 0, length = strlen(word) ; i < length ; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            curchar = strchr(alpha, word[i]); //look up cur char in alpha string
            pos = (int)(curchar - alpha); //get pos (index) of the char
            score = score + POINTS[pos]; //use the index to get point value and add it to total
            //printf("%c  %i\n", word[i], pos);
        }

    }

    return score;
}
