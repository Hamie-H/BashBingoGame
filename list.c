#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

void INITIALIZE(struct list *whichlist)
{
    whichlist->values = (int *)calloc(100,sizeof(int));
    whichlist->count = 0;
    whichlist->checker = 1;
}

int ADD(int item, struct list *whichlist)
{
    whichlist->values[whichlist->count] = item;
    (whichlist->count)++;
    //whichlist->values = (int *)realloc(whichlist->values, 8);
    return (0);
}

int CHECK(int testval, struct list *testlist)
{
    int i;
    for (i = 0; i <= testlist->count; ++i)
    {
        if (testlist->values[i] == testval)
        {
            testlist->checker = 0;
            break;
        }
        else
        {
            testlist->checker = 1;
        }
    }
    return (0);
}

int PRINT(struct list *whichlist)
{
    int i;
    for (i = 0; i < whichlist->count; ++i)
    {

        if (whichlist->values[i] < 10)
            printf("L0%d ", whichlist->values[i]);
        else if (10 <= whichlist->values[i] && whichlist->values[i] < 15)
            printf("L%d ", whichlist->values[i]);
        else if (15 < whichlist->values[i] && whichlist->values[i] <= 30)
            printf("I%d ", whichlist->values[i]);
        else if (30 < whichlist->values[i] && whichlist->values[i] <= 45)
            printf("N%d ", whichlist->values[i]);
        else if (45 < whichlist->values[i] && whichlist->values[i] <= 60)
            printf("U%d ", whichlist->values[i]);
        else if (60 < whichlist->values[i] && whichlist->values[i] <= 75)
            printf("X%d ", whichlist->values[i]);
    }
    return (0);
}
///////////////////////////////////////////////////////////////////////////////////////
int cardCheck(int Card[5][5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (((floor(log10(abs(Card[i][0]))) + 1) > 2) || ((floor(log10(abs(Card[i][0]))) + 1) < 1) || Card[i][0] < 1 || Card[i][0] > 15)
        {
            return 0;
        }
        else if ((floor(log10(abs(Card[i][1]))) + 1) != 2 || Card[i][1] < 16 || Card[i][1] > 30)
        {
            return 0;
        }
        else if ((Card[i][2] < 31 || Card[i][2] > 45 || Card[2][2] != 0))
        {
            if (i != 2)
            {
                return 0;
            }
            else if (i == 2 && Card[i][2] != 0)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
        else if ((floor(log10(abs(Card[i][3]))) + 1) != 2 || Card[i][3] < 46 || Card[i][3] > 60)
        {
            return 0;
        }
        else if ((floor(log10(abs(Card[i][4]))) + 1) != 2 || Card[i][4] < 61 || Card[i][4] > 75)
        {
            return 0;
        }
    }
    return 1;
}

int checkDuplicate(int arr[])
{
    int i, j;
    int count = 25;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (arr[i] == arr[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void printArr(int Card[5][5], int Card2[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (Card[i][j] < 10 || Card[i][j] >= 0)
            {
                if (Card2[i][j] == 1)
                {
                    printf("%02dm ", Card[i][j]);
                }
                else
                {
                    printf("%02d  ", Card[i][j]);
                }
            }
            else
            {
                if (Card2[i][j] == 1)
                {
                    printf("m%d ", Card[i][j]);
                }
                printf("%d  ", Card[i][j]);
            }
        }
        if (i == 4)
        {
            printf("\n");
        }
        else if (i == 9)
        {
            printf("\n");
        }
        else if (i == 14)
        {
            printf("\n");
        }
        else if (i == 19)
        {
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }
}