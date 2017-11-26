#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int len, char * argv[])
{
    char s = 'i';   //used for a case where no parameters were given

    if(argv[1]) //if there's a parameter
    {
        if(argv[2])     //user provided a char
        {
            switch(argv[1][1])
            {
            case 'l':
            case 'L':
                change2LowerCase(argv[2][0]);   //read the second argument from input
                break;
            case 'u':
            case 'U':
                change2UpperCase(argv[2][0]);
                break;
            case 'c':
            case 'C':
                switchCase(argv[2][0]);
                break;
            case 'n':
            case 'N':
                makeNames(argv[2][0]);
                break;
            default:                        //none of above was used
                change2UpperCase(s);
                break;
            }
        }
        else        //no char was given so use "s" instead
        {
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
            default:                        //none of above was used
                change2UpperCase(s);
                break;
            }
        }
    }
    else    //in case that no parameters were given
    {
        change2UpperCase(s);
    }

    return 0;
}
