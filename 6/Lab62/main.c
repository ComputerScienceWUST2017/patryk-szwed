#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int len, char * argv[])
{
    if(argv[1]) //if there's a parameter
    {
        switch(argv[1][1])
        {
        case 'm':
        case 'M':
            CountMost();   //read the second argument from input
            break;
        case 'l':
        case 'L':
            CountLeast();
            break;
        default:                        //none of above was used
            CountMost();
            break;
        }
    }
    else    //in case that no parameters were given
    {
        CountMost();
    }

    return 0;
}
