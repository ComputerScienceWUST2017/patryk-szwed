#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int len, char * argv[])
{
    char s = 'i';

    switch(argv[1][1])
    {
    case 'l':
    case 'L':
        change2LowerCase(s);
        break;
    case 'u':
    case 'U':
        change2UpperCase(s);
        break;
    case 'c':
    case 'C':
        switchCase(s);
        break;
    case 'n':
    case 'N':
        makeNames(s);
        break;
    default:
        change2UpperCase(s);
        break;
    }

    return 0;
}
