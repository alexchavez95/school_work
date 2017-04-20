#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//automatically fills array of 10 spaces with random numbers from 1-10

void main()
{
    char array[10];
    int i;
    time_t t;
    srand((unsigned)time(&t));
    int num = rand()%9+1;

    for (i = 0; i < 10; i++)
    {
        array[num] = rand() % 9 + 1;
        printf("%d ", array[num]);
    }

}

