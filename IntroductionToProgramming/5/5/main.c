#include <stdio.h>
#include <stdlib.h>
#include "RangeSelection.h"

int main(int argc, char * argv[])
{
    const int N = 256;  //256 = line length limit

    char line[N];

    while(RangeSelection2(argv[1], argv[2]))
    {
        continue;
    }

    return 0;
}
