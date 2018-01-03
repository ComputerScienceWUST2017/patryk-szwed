#include "func.h"

int main()
{
    struct personalData * data[10];

    int len = readPtrData(data, sizeof(data)/4);

    int i;

    puts("\n---------------------------- All data ----------------------------");

    for(i = 0; i < len; ++i)
        printData(data[i], len);

    weightSort(data, len);

    puts("\n---------------------------- After weight sorting ----------------------------");

    printPtrData(data, len);

    remarksSort(data, len);

    puts("\n---------------------------- After remarks sorting ----------------------------");

    printPtrData(data, len);

    puts("\nEnd of work!");

    system("PAUSE");

    return 0;
}
