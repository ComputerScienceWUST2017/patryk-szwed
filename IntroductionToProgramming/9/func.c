#include "func.h"

personalData * getPersonPtr(char * line)
{
    struct personalData * person = malloc(sizeof(personalData));  //allocate memory for this structure
    char * token;
    bool error = false;

    token = strtok(line, ";");  //starts searching the string until the semicolon
    if(token == NULL)           //if there is no data given or some data is missing
    {
        snprintf(person->name, 20, "%s", token);
        error = true;
    }
    else
        snprintf(person->name, 20, "%s", token); //copy token into person.name

    token = strtok(NULL, ";");  //now start from the previous place(don't start from the beginning of the line)
    if(atoi(token) != 0 && !error)        //checks if conversion was valid
        person->age = atoi(token);
    else
    {
        person->age = 0;
        error = true;
    }
    if(token == NULL)
    {
        person->age = 0;
        error = true;
    }

    token = strtok(NULL, ";");
    if(atof(token) != 0)
        person->weight = atof(token);
    else
    {
        person->weight = 999.9;
        error = true;
    }
    if(token == NULL)
    {
        person->weight = 999.9;
        error = true;
    }

    token = strtok(NULL, ";");
    person->remarks = malloc(50);   //allocate memory for remark as it hasn't been allocated yet
    snprintf(person->remarks, 50, "%s", token);

    if(error)   //check if there was an error inside data
    {
        person->age = 0;
        person->weight = 999.9;

        char * err = "Invalid data.";

        snprintf(person->name, 20, "%s", err);
    }

    return person;
}

int readPtrData(personalData * ar[], int len)
{
    char line[100];
    char *wsk;  //used to store the data

    int i = 0;

    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if(i < len)
        {
            wsk = line;
            ar[i] = getPersonPtr(wsk);
        }
        else
            break;
        ++i;
    }

    personalData person;

    int j = i-1;

    person.age = ar[j]->age;    //set those values for the last person
    snprintf(person.name, 20, "%s", ar[j]->name);
    person.weight = ar[j]->weight;
    person.remarks = '\0';  //set 0 as remarks

    ar[j] = malloc(sizeof(personalData));   //allocate memory for that person
    *ar[j] = person;    //assign that value

    return i;
}

void printData(personalData ar[], int len)
{
    if(len <= 0)
        puts("There is no data to print.");
    else
    {
        int idx = 0;
        printf(" \n Name: %s\n Age: %d\n Weight: %0.1f\n Remarks: %s\n", ar[idx].name, ar[idx].age, ar[idx].weight, ar[idx].remarks);
    }
}

void printPtrData(personalData * ar[], int len)
{
    if(len <= 0)
        puts("There is no data to print.");
    else
    {
        int idx = 0;    //used for moving through the array
        while(idx < len)
        {
            if(ar[idx]->remarks == NULL && checkRemarks)    //if it is used to write out remarks and the remarks is set to NULL, omit it
                ++idx;
            printf(" \n Name: %s\n Age: %d\n Weight: %0.1f\n Remarks: %s\n", ar[idx]->name, ar[idx]->age, ar[idx]->weight, ar[idx]->remarks);
            ++idx;
        }
    }
}

int structSortWeight(const void *a, const void *b)
{
    const personalData **p1 = a;    //pointer to a pointer as the function gets a pointer pointing to a structure instance
    const personalData **p2 = b;

    return ((*p1)->weight > (*p2)->weight) - ((*p1)->weight < (*p2)->weight); //2 compares are done, each returning int
                                                                                //(it's more accurate)
}

int structSortRemarks(const void *a, const void *b)
{
    const personalData **p1 = a;    //pointer to a pointer as the function gets a pointer pointing to a structure instance
    const personalData **p2 = b;

    if(((*p1)->remarks) == NULL || ((*p2)->remarks) == NULL)    //if there's a null in remarks, ignore it
        return 0;

    int x = strcmp(((*p1)->remarks), ((*p2)->remarks)); //compare 2 remarks
    return x;
}

void weightSort(personalData * data[], int len)
{
    qsort(data, len, sizeof(struct personalData *), structSortWeight);
}

void remarksSort(personalData * data[], int len)
{
    checkRemarks = true;    //set this boolean to true as sorting is called here

    qsort(data, len, sizeof(struct personalData *), structSortRemarks);
}
