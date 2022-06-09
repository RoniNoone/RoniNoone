#include <cs50.h>
#include <stdio.h>

/*Soution for Mario problem in CS50
Veronica "Roni" Noone
June 9, 2022
This was a lot of trial and error. Thought I could accomplish with two loops ented up using a third.
*/

void drawPyramid(int h);

int main(void)
{
    int height;
    const int UPPERB = 8; //upper bound
    const int LOWERB = 1; //lower bound
    bool again = false; //flag to tack is user entered what we wanted.
    do //do while loop to force use to enter what we want 1-8
    {
        height = get_int("\nHow tall should be make the pyramids?\nEnter a number between 1 and 8 ");
        if (height >= LOWERB && height <= UPPERB)
        {
            //printf("\nAwesome! You entered: %i\n", height); // took out since it failed the check
            again = false; //yay they entered something correct -- move on!
        }
        else
        {
            printf("try again...\n");
            again = true; //nope -- keep looping. else catches all including if user enters string.
        }
    }
    while (again); //Keep asking until they enter what we want

    //call drawPyramid
    drawPyramid(height);
}

void drawPyramid(int h)
//funciton to draw pyramid based on height
{
    int htrace = h; //variable to help with loop for spaces.
    for (int i = 0; i < h; i++)
    {
        htrace--; //one less space each time.
        for (int j = 0; j < htrace; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#"); // left side of pyramid
        }
        printf("  ");
        for (int l = 0; l <= i; l++)
        {
            printf("#"); // right side of pyramid
        }
        printf("\n");
    }
    //printf("\n"); //extra space to buffer command prompt. removed for check script since it kept failing.
}
