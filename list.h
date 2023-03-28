#ifndef LIST_DOT_H
#define LIST_DOT_H
#include<stdio.h>
typedef struct list
{
    int size;
    int count;
    int checker;
    int *values;

} list;

void INITIALIZE(struct list *whichlist);
int CHECK(int testval, struct list *testlist);
int ADD(int item, struct list *whichlist);
int PRINT(struct list *whichlist);

//Card checking functions
int cardCheck(int Card[5][5]);
int lineCheck(char *a);
int checkDuplicate(int arr[]);
void printArr(int Card[5][5], int Card2[5][5]);
#endif