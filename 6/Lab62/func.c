#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //INT_MAX
#include "func.h"

void CountMost()
{
    int c, most_occurrings;    //most_occurrings is being used to remember the most often appearing char's occurrings
    unsigned int most_nr;
                                        //most_nr is used to remember the exact value of this char
    int allChars[256] = {0};    //set 0 to all elements of this array

    while((c = getchar()) != EOF)
    {
        if(!isalpha(c))   //don't count '\0', new lines and spaces,etc.
            continue;

        allChars[c]++;
    }

    int i;

    most_occurrings = 0;

    for(i = 0; i < sizeof(allChars)/sizeof(int); ++i)
    {
        if(allChars[i] > most_occurrings && allChars[i] != 0)
        {
            most_occurrings = allChars[i];
            most_nr = i;
        }
    }
    printf("Character '%c' appears most often(%d times).", most_nr, most_occurrings);
}
void CountLeast()
{
    int c;

    unsigned int least_occurrings, least_nr;    //least_occurrings is being used to remember the least often appearing char's occurrings
                                        //least_nr is used to remember the exact value of this char
    int allChars[256] = {0};    //set 0 to all elements of this array

    while((c = getchar()) != EOF)
    {
        if(!isalpha(c))   //don't count '\0', new lines and spaces,etc.
            continue;

        allChars[c]++;
    }

    int i;
    least_occurrings = INT_MAX;

    for(i = 0; i < sizeof(allChars)/sizeof(int); ++i)
    {
        if(allChars[i] < least_occurrings && allChars[i] != 0)  //don't count characters that are not present
        {
            least_occurrings = allChars[i];
            least_nr = i;
        }
    }
    printf("Character '%c' appears least often(%d times).", least_nr, least_occurrings);
}
