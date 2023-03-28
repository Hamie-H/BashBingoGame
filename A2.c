//hhamie, Hamie, Hussein, 500876254, secion 03
//a2aqeel, aqeel, ahsan, 500964214, section 09
//msani, Sani, Muhammad Zayd, 501042912, section 09
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    if ( argc != 3)
    {
        printf("Usage: %s seed cardFile \n", argv[0]);
        exit(1);
    }
    //Converts seed into integer and applies it to srand
    char *a = argv[1];
    if (!isdigit(*a)) {
        printf("Expected integer seed but got %s \n", argv[1]);
        exit(2);
    }
    int seed = atoi(a);
    srand(seed);
    /////////////////////////////////////////////////////
    //Reads second input which is the File & checks it
    FILE *f = fopen(argv[2], "r");
    int CardNums[25]; // 1d array
    int Card[5][5];
    int Scorecard[5][5] = {0};
    Scorecard[2][2] = 1; // 2d array
    int i;
    if (f == NULL) {
        printf("File is nonexistent or unreadable \n");
        exit(3);
    }



    
    // adding elements to CardNums 1d Arr
    for (i = 0; i < 25; i++)
    {
        fscanf(f, "%d", &CardNums[i]);
    }

    // Adding elements from 1d Arr to 2d Arr
    int j;
    int k = 0;
    if (checkDuplicate(CardNums) == 1)
    {
        for (i = 0; i < 5; i++)
        {
            if (k == 25)
            {
                break;
            }
            for (j = 0; j < 5; j++)
            {
                Card[i][j] = CardNums[k];
                k++;
            }
        }
    }

    //card check
    if (checkDuplicate(CardNums) == 0 || cardCheck(Card) == 0)
    {
        printf("%s has bad format \n", argv[2]);
        exit(4); //exit 4
    }

    f = fopen(argv[2], "r");
    int temp;
    char c;
    int count = 0;
    while((c=fgetc(f)) != EOF) {
        if(c == '\n') {
            count++;
        }
        temp++;
    }
    if (count != 5 && temp != 99) {
            printf("%s has bad format \n", argv[2]);
            exit(4);
        } 
    fclose(f);

    //Initialize the list
    list callist;
    INITIALIZE(&callist);
    char input;
    int callnum;
    int inc;
    while (1)
    {
        system("clear");
        printf("CallList: ");
        PRINT(&callist);
        printf("\n\nL   I   N   U   X   \n");      

        ///Score checking
        for (i = 0; i <= 5; i++)
        {
            for (j = 0; j <= 5; j++)
            {
                if (Card[i][j] == callnum)
                {
                    Scorecard[i][j] = 1;
                    //printArr(Scorecard, Scorecard);
                }
            }
        }
         printArr(Card, Scorecard);
        printf("enter any non-enter key for Call (q to quit): \n\n");
        //Win Check
        if (Scorecard[0][0] == 1 && Scorecard[0][4] == 1 && Scorecard[4][0] == 1 && Scorecard[4][4] == 1)
        {
            printf("WINNER\n");
            exit(0);
        }

        
        for (j = 0; j < 5; j++){
            inc = 0;
            for (i = 0; i < 5; i++)
            {
                if (Scorecard[j][i] == 1)
                    inc++;
                if (inc == 5){
                    printf("WINNER\n");
                    exit(0);}
            }
        }

        for (j = 0; j < 5; j++)
        {
            inc = 0;
            for (i = 0; i < 5; i++)
            {
                if (Scorecard[i][j] == 1)
                    inc++;
                if (inc == 5){
                    printf("WINNER\n");
                    exit(0);}
            }
        }

        do
        {
            callnum = (rand() % 75) + 1;
            CHECK(callnum, &callist);
        } while (callist.checker == 0);
        ADD(callnum, &callist);
        //printf("\n\nCALLNUM VALUE IS: %d \n", );

        do
        {
            input = getc(stdin);
        } while (input == 0x0A);
        if (input == 'q'){
            printf("WINNER\n");
            exit(0);}
    }

    return (0);
}


