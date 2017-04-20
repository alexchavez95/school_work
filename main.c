#include <stdio.h>
#include <string.h>

void main()
{
    int num;
    int array[num];
    //int num; //number of things in array
    int elem;

    printf("how many elements? ");
    scanf("%d", &num);

    printf("\nEnter contents of array ");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &elem);
        array[i] = elem;
    }

    int i;
    int small = array[i];
    int position;

    for (int i = 0; i < num; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
            position = i;
        }
    }
    printf("\nelem of small %d", small);
    printf("\nposition of small is %d\n", position);

}

