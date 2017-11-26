#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void change2LowerCase(char s)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(isupper(c) && c == toupper(s))
        {
            printf("%c", tolower(c));
        }
        else if(c == '\n')
        {
            printf("\n");
        }
        else printf("%c", c);
    }
}
void change2UpperCase(char s)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(islower(c) && c == tolower(s))
        {
            printf("%c", toupper(c));
        }
        else if(c == '\n')
        {
            printf("\n");
        }
        else printf("%c", c);
    }
}
void switchCase(char s)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(isupper(c) && c == toupper(s))
        {
            printf("%c", tolower(c));
        }
        else if(islower(c) && c == tolower(s))
        {
            printf("%c", toupper(c));
        }
        else if(c == '\n')
        {
            printf("\n");
        }
        else printf("%c", c);
    }
}
void makeNames(char s)
{
    int c;
    bool is_first_letter = true;   //used to check if next letter will be the first one

    while((c = getchar()) != EOF)
    {
        if(is_first_letter)        //it's first letter so write it as an uppercase
        {
            printf("%c", toupper(c));
            is_first_letter = false;
        }
        else
            printf("%c", tolower(c));

        if(c == 32 || c == '\n')    //if "c" is a space or it's a new line, set is_first_letter to true
            is_first_letter = true;
    }
}
