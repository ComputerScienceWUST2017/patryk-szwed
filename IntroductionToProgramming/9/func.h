#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct personalData
{
    char name[20];  //reserve memory for name
    char * remarks;
    int age;
    float weight;
} personalData;

static bool checkRemarks = false; //used for checking if the sorting of remarks was called

personalData * getPersonPtr(char * line);
int readPtrData(personalData * ar[], int len);
void printData(personalData ar[], int len);
void printPtrData(personalData * ar[], int len);
int structSortWeight(const void *a, const void *b);
int structSortRemarks(const void *w1, const void *w2);
void weightSort(personalData * data[], int len);
void remarksSort(personalData * data[], int len);

#endif // FUNC_H_INCLUDED
