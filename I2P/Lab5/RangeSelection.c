#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "RangeSelection.h"

bool RangeSelection(char * argv[])
{
    int c;
    bool is_break;

    char * p = argv;

    int x;
    x = strlen(p);      //length of the argument

    char word[x];

    while((c = getchar()) != EOF)
    {
        is_break = false;       //a variable for checking if instruction break was used

        for(int j = 0; j < x; ++j)  //load chars into word
        {
            word[j] = c;
            c = getchar();  //to load chars into c
            if(c == '\n' || c == EOF)       //if there's less than 3 chars in this word, don't check it
            {
                is_break = true;
                break;
            }               //if that's EOF or new line, break
        }

        if(!is_break)
        {
            word[x] = '\0';
        }

        if(strcmp(word, argv) == 0 && !is_break)       //they're the same
        {
            for(int j = 0; j < x; ++j)         // less or equal as we have to print '\0' too <----- NO
            {
                printf("%c", word[j]);
            }

            do      //do while as it will show the output at least three times
            {
                printf("%c", c);        //print that char
                if(c == '\n') break;
            }
            while((c = getchar()) != EOF);
        }
        else
        {
            while((c = getchar()) != EOF)     //load chars until a new line
            {
                if(c == '\n') break;
            }
        }
    }
    return false;
}

bool RangeSelection2(char * argv1[], char * argv2[])
{
    int c;
    bool is_break;

    int x, y, buf;
    y = strlen(argv1);      //length of the first argument
    x = strlen(argv2);      //length of the second argument

    if(y > x)               //as x has to be bigger than y
    {
        buf = x;
        x = y;
        y = buf;
    }

    char word[x];

    while((c = getchar()) != EOF)
    {
        is_break = false;       //a variable for checking if instruction break was used

        for(int j = 0; j < x; ++j)  //load chars into word
        {
            word[j] = c;
            c = getchar();  //to load chars into c
            if(c == '\n' || c == EOF)       //if there's less than 3 chars in this word, don't check it
            {
                is_break = true;
                break;
            }               //if that's EOF or new line, break
        }

        if(!is_break)
        {
            word[x] = '\0';
        }

        if(strcmp(word, argv1) >= 0 && (strcmp(word, argv2) <= 0) && !is_break)       //if it's >= than argv1,it's after it.
        {                                                                //If it's <= than argv2, it's before it
            for(int j = 0; j < x; ++j)
            {
                printf("%c", word[j]);
            }

            do      //do while as it will show the output at least three times
            {
                printf("%c", c);        //print that char
                if(c == '\n') break;
            }
            while((c = getchar()) != EOF);
        }
        else
        {
            while((c = getchar()) != EOF)     //load chars until a new line
            {
                if(c == '\n') break;
            }
        }
    }
    return false;
}

bool RangeSelection3(char * argv1[], char * argv2[])
{
    int c;
    bool is_break;

    int x;
    x = strlen(argv2);      //length of the argument

    char word[x];

    while((c = getchar()) != EOF)
    {
        is_break = false;       //a variable for checking if instruction break was used

        for(int j = 0; j < x; ++j)  //load chars into word
        {
            word[j] = c;
            c = getchar();  //to load chars into c
            if(c == '\n' || c == EOF)       //if there's less than 3 chars in this word, don't check it
            {
                is_break = true;
                break;
            }               //if that's EOF or new line, break
        }

        if(!is_break)
        {
            word[x] = '\0';
        }

        if(strcmp(word, argv2) <= 0 && !is_break)       //if it's -1 or 0, it means that word is earlier or it starts with it
        {
            for(int j = 0; j < x; ++j)
            {
                printf("%c", word[j]);
            }

            do      //do while as it will show the output at least three times
            {
                printf("%c", c);        //print that char
                if(c == '\n') break;
            }
            while((c = getchar()) != EOF);
        }
        else
        {
            while((c = getchar()) != EOF)     //load chars until a new line
            {
                if(c == '\n') break;
            }
        }
    }
    return false;
}

bool RangeSelection4(char * argv1[], char * argv2[])
{
    int c;
    bool is_break;

    int x;
    x = strlen(argv1);      //length of the argument

    char word[x];

    while((c = getchar()) != EOF)
    {
        is_break = false;       //a variable for checking if instruction break was used

        for(int j = 0; j < x; ++j)  //load chars into word
        {
            word[j] = c;
            c = getchar();  //to load chars into c
            if(c == '\n' || c == EOF)       //if there's less than 3 chars in this word, don't check it
            {
                is_break = true;
                break;
            }               //if that's EOF or new line, break
        }

        if(!is_break)
        {
            word[x] = '\0';
        }

        if(strcmp(word, argv1) >= 0 && !is_break)       //if it's 1 or 0, it means that word is before it or it starts with it
        {
            for(int j = 0; j < x; ++j)
            {
                printf("%c", word[j]);
            }

            do      //do while as it will show the output at least three times
            {
                printf("%c", c);        //print that char
                if(c == '\n') break;
            }
            while((c = getchar()) != EOF);
        }
        else
        {
            while((c = getchar()) != EOF)     //load chars until a new line
            {
                if(c == '\n') break;
            }
        }
    }
    return false;
}
