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
    int big = array[i];
    int s_position;
    int b_position;

    for (int i = 0; i < num; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
            s_position = i;
        }
    }

    printf("\nelem of small %d", small);
    printf("\nposition of small is %d\n", s_position);


    for (int i = 0; i < num; i++)
    {
        if (array[i] > big)
        {
            big = array[i];
            b_position = i;
        }
    }


    printf("\nelem of big %d", big);
    printf("\nposition of big %d\n", b_position);

    int temp, temp_p;

    temp = big;
    big = small;
    small = temp;

    temp_p = b_position;
    b_position = s_position;
    s_position = temp_p;

    printf("\nswitching positions: big %d, b_position %d, small %d, s position: %d\n", big, b_position, small, s_position);

}

