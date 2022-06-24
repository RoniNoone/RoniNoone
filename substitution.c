#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //initial error handling - only 1 argument and must be 26 charachters.
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key (key should be 26 letters - each only once)");
        return 1;
    }
    //get length of string
    int argvLength = strlen(argv[1]);
    // check langth of string
    if (argvLength != 26)
    {
        printf("Usage: ./substitution key (key should be 26 letters - each only once)");
        return 1;
    }
    // make sure cipher is letters only and no repeats
    //loop through each character
    for (int i = 0; i < argvLength; i++)
    {
        //check if is a letter.
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain letters");
            return 1;
        }
        //check for repeats in the string by adding second loop
        for (int j = i + 1; j < argvLength; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key cannot contain repeated letters");
                return 1;
            }
        }
    }
    //good to go! Let's do this!

    //get string from user
    string plaintext = get_string("plaintext: ");
    //printf("%s\n", plaintext);
    printf("ciphertext: ");
    //decided to just print string to screen since I ciouldn't get the strncat to work to build the string :()
    // string of alphabet for lookup purposes - I'm sure there is a better way then this!
    string alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphaLower = "abcdefghijklmnopqrstuvwxyz";
    //var to hold current char in loop
    char *curchar; //used to store current char for pos
    int pos = 1 ; //used to store pos of char to compare against array
    //loop though users text
    int ptLength = strlen(plaintext);
    for (int i = 0; i < ptLength; i++)
    {
        //printf("\nCurrent char is %c\n", plaintext[i]);
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                curchar = strchr(alphaLower, plaintext[i]); //look up cur char in alpha string
                pos = (int)(curchar - alphaLower); //get pos (index) of the char
                printf("%c", tolower(argv[1][pos]));
            }
            else if (isupper(plaintext[i]))
            {
                //copied and pasted so this can't be good :(
                curchar = strchr(alphaUpper, plaintext[i]); //look up cur char in alpha string
                pos = (int)(curchar - alphaUpper); //get pos (index) of the char
                printf("%c", toupper(argv[1][pos]));
            }
        }
        else //not in alphabet just print it out
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
