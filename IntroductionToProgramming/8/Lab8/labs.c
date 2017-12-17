#include "labs.h"

personalData getPersonDesc(char * line)
{
    personalData person;
    char * token;

    token = strtok(line, ";");  //starts searching the string until the semicolon
    snprintf(person.name, 20, "%s", token); //copy token into person.name

    token = strtok(NULL, ";");  //now start from the previous place(don't start from the beginning of the line)
    if(atoi(token) != 0)        //checks if conversion was valid
        person.age = atoi(token);
    else
        puts("Not a valid age.");

    token = strtok(NULL, ";");
    if(atof(token) != 0)
        person.weight = atof(token);
    else
        puts("Not a valid weight.");

    token = strtok(NULL, ";");
    person.remarks = malloc(50);   //allocate memory for remark as it hasn't been allocated yet
    snprintf(person.remarks, 50, "%s", token);

    return person;
}

int readData(personalData ar[], int len)
{
    char line[100];
    char *wsk;  //used to store the data

    int i = 0;

    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if(i < len-1)
        {
            wsk = line;
            ar[i] = getPersonDesc(wsk);
        }
        else
            break;
        ++i;
    }

    personalData person;

    person.remarks = '\0';
    ar[i] = person;

    return i;
}

int getOldestPerson(personalData data[])
{
    int oldestIndex = 0; //used to search for the oldest Person

    if(data == NULL)
        return -1;

    int i = 0;

    while(data[i].remarks != '\0')  //if remarks is set to \0, just stop searching
    {
        if(data[i].age > data[oldestIndex].age)
            oldestIndex = i;
        ++i;
    }
    return oldestIndex;
}

int getSlimmestPerson(personalData data[], int len)
{
    int slimmestIndex = 0; //used to search for the slimmest Person

    if(data == NULL)
        return -1;

    for(int i = 0; i < len; ++i)
    {
        if(data[i].weight < data[slimmestIndex].weight)
            slimmestIndex = i;
    }
    return slimmestIndex;
}

void printInfo(personalData ar[], int idx, char *msgOk, char *msgbad)
{
    if(idx < 0)
        printf("%s", msgbad);
    else
    {
        printf("%s \n", msgOk);
        printf(" Name: %s\n Age: %d\n Weight: %0.1f\n Remarks: %s\n", ar[idx].name, ar[idx].age, ar[idx].weight, ar[idx].remarks);
    }
}
