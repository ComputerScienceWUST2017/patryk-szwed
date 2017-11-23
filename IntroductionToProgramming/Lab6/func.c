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
		puts("a");
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
    puts("makenames");
}
